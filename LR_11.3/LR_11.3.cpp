#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Transfer {
	string payer_account;
	string recipient_account;
	double amount;
};

void displayMenu();
string getFileName();
void createList(const string& filename);
void viewList(const string& filename);
void addTransfer(const string& filename);
void getTotalAmountByPayer(const string& filename, const string& payer_account);

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename = getFileName();
	int choice;

	do {
		displayMenu();
		cout << "Оберіть опцію: ";
		while (!(cin >> choice)) {
			cout << "Невірний вибір. Спробуйте ще раз: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		cin.ignore(10000, '\n'); // Очищуємо буфер вводу

		switch (choice) {
		case 1:
			createList(filename);
			break;
		case 2:
			viewList(filename);
			break;
		case 3:
			addTransfer(filename);
			break;
		case 4: {
			string payer_account;
			cout << "Введіть розрахунковий рахунок платника: ";
			getline(cin, payer_account);
			getTotalAmountByPayer(filename, payer_account);
			break;
		}
		case 0:
			cout << "Вихід з програми." << endl;
			break;
		default:
			cout << "Невірний вибір. Спробуйте ще раз." << endl;
		}
	} while (choice != 0);

	return 0;
}

void displayMenu() 
{
	cout << "\n--- Меню ---" << endl;
	cout << "1. Створити новий список" << endl;
	cout << "2. Переглянути список" << endl;
	cout << "3. Додати переказ до списку" << endl;
	cout << "4. Вивести суму, зняту з рахунку платника" << endl;
	cout << "0. Вихід" << endl;
}

string getFileName() {
	string filename;
	cout << "Введіть ім'я файлу: ";
	getline(cin, filename);
	return filename;
}

void createList(const string& filename) 
{
	ofstream file(filename);
	if (file) {
		cout << "Новий список створено." << endl;
	}else {
		cerr << "Помилка створення файлу." << endl;
	}
}

void viewList(const string& filename)
{
	ifstream file(filename);
	if (!file) {
		cerr << "Не вдалося відкрити файл." << endl;
		return;
	}

	cout << "\nСписок переказів:\n";
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
}

void addTransfer(const string& filename) 
{
	ofstream file(filename, ios::app);
	if (!file) {
		cerr << "Не вдалося відкрити файл для запису." << endl;
		return;
	}

	Transfer newTransfer;
	cout << "Введіть розрахунковий рахунок платника: ";
	getline(cin, newTransfer.payer_account);
	cout << "Введіть розрахунковий рахунок одержувача: ";
	getline(cin, newTransfer.recipient_account);
	cout << "Введіть перераховану суму (грн.): ";
	while (!(cin >> newTransfer.amount) || newTransfer.amount < 0) {
		cout << "Невірна сума. Спробуйте ще раз: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cin.ignore(10000, '\n'); // Очищуємо буфер вводу

	file << newTransfer.payer_account << " "
		<< newTransfer.recipient_account << " "
		<< newTransfer.amount << endl;

	cout << "Переказ додано до списку." << endl;
}

void getTotalAmountByPayer(const string& filename, const string& payer_account) 
{
	ifstream file(filename);
	if (!file) {
		cerr << "Не вдалося відкрити файл." << endl;
		return;
	}

	string line;
	bool found = false;
	double total_amount = 0.0;

	while (getline(file, line)) {
		istringstream iss(line);
		Transfer transfer;
		if (!(iss >> transfer.payer_account >> transfer.recipient_account >> transfer.amount)) {
			continue; // Пропускаємо некоректні рядки
		}
		if (transfer.payer_account == payer_account) {
			total_amount += transfer.amount;
			found = true;
		}
	}

	if (found) {
		cout << "Сума, знята з рахунку " << payer_account << ": " << total_amount << " грн." << endl;
	}
	else {
		cout << "Платника з розрахунковим рахунком " << payer_account << " не знайдено." << endl;
	}
}
