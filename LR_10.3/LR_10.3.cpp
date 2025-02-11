#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h> 

using namespace std;

struct Bill
{
	string payer_account;
	string recipient_account;
	double amount;
};

void CreateBills(Bill* bills, const int N);
void PrintBills(Bill* bills, const int N);
void SortBills(Bill* bills, const int N);
double GetAmountByPayer(Bill* bills, const int N, const string& payer_account);
void SaveToFile(Bill* bills, const int N, const char* filename);
void LoadFromFile(Bill*& bills, int& N, const char* filename);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number;
	cout << "Введіть кількість платежів N: ";
	while (!(cin >> number) || number <= 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Неправильне значення. Введіть N знову: ";
	}

	Bill* bills = new Bill[number];

	string payer_account;
	double amount;
	char filename[100];
	int menuItem;

	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - впорядкування масиву структур за алфавітним порядком рахунків платників" << endl;
		cout << " [4] - вивід інформації про суму, зняту з рахунку платника" << endl;
		cout << " [5] - запис даних у файл" << endl;
		cout << " [6] - зчитування даних із файлу" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl;
		cout << "Введіть значення: ";
		while (!(cin >> menuItem) || menuItem < 0 || menuItem > 6)
		{
			cin.clear();
			cin.ignore(10000, '\n'); // -> очищення вхідного буфера після введення числових значень, просто велике число.
			cout << "Неправильне значення. Введіть пункт меню знову: ";
		}
		cin.ignore(); // очищуємо буфер вводу

		switch (menuItem)
		{
		case 1:
			CreateBills(bills, number);
			break;
		case 2:
			PrintBills(bills, number);
			break;
		case 3:
			SortBills(bills, number);
			cout << "Масив впорядковано." << endl;
			break;
		case 4:
			cout << "Введіть розрахунковий рахунок платника: ";
			getline(cin, payer_account);
			amount = GetAmountByPayer(bills, number, payer_account);
			if (amount >= 0)
			{
				cout << "Сума, знята з рахунку " << payer_account << ": " << amount << " грн." << endl;
			}
			else
			{
				cout << "Платника з розрахунковим рахунком " << payer_account << " не знайдено." << endl;
			}
			break;
		case 5:
			cout << "Введіть ім'я файлу: ";
			cin.getline(filename, 99);
			SaveToFile(bills, number, filename);
			break;
		case 6:
			cout << "Введіть ім'я файлу: ";
			cin.getline(filename, 99);
			LoadFromFile(bills, number, filename);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню." << endl;
		}

	} while (menuItem != 0);

	delete[] bills;
	return 0;
}

void CreateBills(Bill* bills, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Платіж № " << i + 1 << ":" << endl;
		cout << " Розрахунковий рахунок платника: ";
		getline(cin, bills[i].payer_account);
		cout << " Розрахунковий рахунок одержувача: ";
		getline(cin, bills[i].recipient_account);
		cout << " Перерахована сума (грн.): ";
		while (!(cin >> bills[i].amount) || bills[i].amount < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Неправильне значення. Введіть суму знову: ";
		}
		cin.ignore(); // очищуємо буфер вводу
		cout << endl;
	}
}

void PrintBills(Bill* bills, const int N)
{
	cout << "========================================================================================" << endl;
	cout << "| № | Розрахунковий рахунок платника | Розрахунковий рахунок одержувача | Сума (грн.)  |" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(31) << left << bills[i].payer_account;
		cout << "| " << setw(33) << left << bills[i].recipient_account;
		cout << "| " << setw(12) << right << setprecision(2) << fixed << bills[i].amount << " |" << endl;
	}
	cout << "========================================================================================" << endl;
	cout << endl;
}

void SortBills(Bill* bills, const int N)
{
	Bill temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (bills[j].payer_account > bills[j + 1].payer_account) {
				temp = bills[j];
				bills[j] = bills[j + 1];
				bills[j + 1] = temp;
			}
		}
	}
}

double GetAmountByPayer(Bill* bills, const int N, const string& payer_account)
{
	double total_amount = 0;
	bool found = false;
	for (int i = 0; i < N; i++) {
		if (bills[i].payer_account == payer_account) {
			total_amount += bills[i].amount;
			found = true;
		}
	}
	if (found)
		return total_amount;
	else
		return -1; // Якщо рахунок не знайдено
}

void SaveToFile(Bill* bills, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);
	if (!fout)
	{
		cout << "Помилка відкриття файлу для запису!" << endl;
		return;
	}
	fout.write((char*)&N, sizeof(N));
	for (int i = 0; i < N; i++)
	{
		size_t len;

		// Зберігаємо payer_account
		len = bills[i].payer_account.size();
		fout.write((char*)&len, sizeof(len));
		fout.write(bills[i].payer_account.c_str(), len);

		// Зберігаємо recipient_account
		len = bills[i].recipient_account.size();
		fout.write((char*)&len, sizeof(len));
		fout.write(bills[i].recipient_account.c_str(), len);

		// Зберігаємо amount
		fout.write((char*)&bills[i].amount, sizeof(bills[i].amount));
	}
	fout.close();
	cout << "Дані успішно збережено у файл." << endl;
}

void LoadFromFile(Bill*& bills, int& N, const char* filename)
{
	ifstream fin(filename, ios::binary);
	if (!fin)
	{
		cout << "Помилка відкриття файлу для зчитування!" << endl;
		return;
	}
	fin.read((char*)&N, sizeof(N));
	if (bills != nullptr)
	{
		delete[] bills;
	}
	bills = new Bill[N];
	for (int i = 0; i < N; i++)
	{
		size_t len;
		char* buffer;

		// Зчитуємо payer_account
		fin.read((char*)&len, sizeof(len));
		buffer = new char[len + 1];
		fin.read(buffer, len);
		buffer[len] = '\0';
		bills[i].payer_account = buffer;
		delete[] buffer;

		// Зчитуємо recipient_account
		fin.read((char*)&len, sizeof(len));
		buffer = new char[len + 1];
		fin.read(buffer, len);
		buffer[len] = '\0';
		bills[i].recipient_account = buffer;
		delete[] buffer;

		// Зчитуємо amount
		fin.read((char*)&bills[i].amount, sizeof(bills[i].amount));
	}
	fin.close();
	cout << "Дані успішно зчитано з файлу." << endl;
}
