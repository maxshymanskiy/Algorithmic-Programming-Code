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
		cout << "������ �����: ";
		while (!(cin >> choice)) {
			cout << "������� ����. ��������� �� ���: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		cin.ignore(10000, '\n'); // ������� ����� �����

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
			cout << "������ ������������� ������� ��������: ";
			getline(cin, payer_account);
			getTotalAmountByPayer(filename, payer_account);
			break;
		}
		case 0:
			cout << "����� � ��������." << endl;
			break;
		default:
			cout << "������� ����. ��������� �� ���." << endl;
		}
	} while (choice != 0);

	return 0;
}

void displayMenu() 
{
	cout << "\n--- ���� ---" << endl;
	cout << "1. �������� ����� ������" << endl;
	cout << "2. ����������� ������" << endl;
	cout << "3. ������ ������� �� ������" << endl;
	cout << "4. ������� ����, ����� � ������� ��������" << endl;
	cout << "0. �����" << endl;
}

string getFileName() {
	string filename;
	cout << "������ ��'� �����: ";
	getline(cin, filename);
	return filename;
}

void createList(const string& filename) 
{
	ofstream file(filename);
	if (file) {
		cout << "����� ������ ��������." << endl;
	}else {
		cerr << "������� ��������� �����." << endl;
	}
}

void viewList(const string& filename)
{
	ifstream file(filename);
	if (!file) {
		cerr << "�� ������� ������� ����." << endl;
		return;
	}

	cout << "\n������ ��������:\n";
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
}

void addTransfer(const string& filename) 
{
	ofstream file(filename, ios::app);
	if (!file) {
		cerr << "�� ������� ������� ���� ��� ������." << endl;
		return;
	}

	Transfer newTransfer;
	cout << "������ ������������� ������� ��������: ";
	getline(cin, newTransfer.payer_account);
	cout << "������ ������������� ������� ����������: ";
	getline(cin, newTransfer.recipient_account);
	cout << "������ ������������ ���� (���.): ";
	while (!(cin >> newTransfer.amount) || newTransfer.amount < 0) {
		cout << "������ ����. ��������� �� ���: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cin.ignore(10000, '\n'); // ������� ����� �����

	file << newTransfer.payer_account << " "
		<< newTransfer.recipient_account << " "
		<< newTransfer.amount << endl;

	cout << "������� ������ �� ������." << endl;
}

void getTotalAmountByPayer(const string& filename, const string& payer_account) 
{
	ifstream file(filename);
	if (!file) {
		cerr << "�� ������� ������� ����." << endl;
		return;
	}

	string line;
	bool found = false;
	double total_amount = 0.0;

	while (getline(file, line)) {
		istringstream iss(line);
		Transfer transfer;
		if (!(iss >> transfer.payer_account >> transfer.recipient_account >> transfer.amount)) {
			continue; // ���������� ��������� �����
		}
		if (transfer.payer_account == payer_account) {
			total_amount += transfer.amount;
			found = true;
		}
	}

	if (found) {
		cout << "����, ����� � ������� " << payer_account << ": " << total_amount << " ���." << endl;
	}
	else {
		cout << "�������� � ������������� �������� " << payer_account << " �� ��������." << endl;
	}
}
