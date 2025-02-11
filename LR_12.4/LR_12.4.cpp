#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Bill
{
    string payer_account;
    string recipient_account;
    double amount;
};

void InputBillsToFile(const char* filename);
void SortBillsInFile(const char* filename);
void OutputTotalAmountByPayerFromFile(const char* filename, const string& payer_account);

int main()
{
    // ������������ ������ ��� ���������� ����������� ���������� �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    char filename[100];
    string payer_account;

    do
    {
        cout << "\n����:\n";
        cout << "1. �������� ����� � ��������� � ����\n";
        cout << "2. ������������� ������ � ���� �� �������������� ��������� ��������\n";
        cout << "3. ��������� ���������� ��� ����, ����� � �������������� ������� ��������\n";
        cout << "0. �����\n";
        cout << "������ ��� ����: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "������ ��'� ����� ��� ������: ";
            cin.getline(filename, 100);
            InputBillsToFile(filename);
            break;
        case 2:
            cout << "������ ��'� ����� ��� �������������: ";
            cin.getline(filename, 100);
            SortBillsInFile(filename);
            break;
        case 3:
            cout << "������ ��'� ����� ��� ������: ";
            cin.getline(filename, 100);
            cout << "������ ������������� ������� ��������: ";
            getline(cin, payer_account);
            OutputTotalAmountByPayerFromFile(filename, payer_account);
            break;
        case 0:
            cout << "���������� ������ ��������.\n";
            break;
        default:
            cout << "������������ ����. ��������� �����.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

void InputBillsToFile(const char* filename)
{
    int N;
    cout << "������ ������� �������: ";
    while (!(cin >> N) || N <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "����������� ��������. ������ N �����: ";
    }
    cin.ignore();

    ofstream fout(filename, ios::binary);
    if (!fout)
    {
        cout << "������� �������� ����� ��� ������!\n";
        return;
    }

    // �������� N � ����
    fout.write((char*)&N, sizeof(N));

    Bill bill;
    for (int i = 0; i < N; ++i)
    {
        cout << "����� �" << i + 1 << ":\n";
        cout << "������������� ������� ��������: ";
        getline(cin, bill.payer_account);
        cout << "������������� ������� ����������: ";
        getline(cin, bill.recipient_account);
        cout << "������������ ���� (���.): ";
        while (!(cin >> bill.amount) || bill.amount < 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "����������� ��������. ������ ���� �����: ";
        }
        cin.ignore(); // ������� ����� �����

        // �������� bill � ����

        // �������� payer_account
        size_t len = bill.payer_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bill.payer_account.c_str(), len);

        // �������� recipient_account
        len = bill.recipient_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bill.recipient_account.c_str(), len);

        // �������� amount
        fout.write((char*)&bill.amount, sizeof(bill.amount));
    }

    fout.close();
    cout << "��� ������ �������� � ����.\n";
}

void SortBillsInFile(const char* filename)
{
    // ������ �� ������ � ����� � �����
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "������� �������� ����� ��� �������!\n";
        return;
    }

    int N;
    fin.read((char*)&N, sizeof(N));
    if (N <= 0)
    {
        cout << "���� �� ������ ����� ��� ����������.\n";
        fin.close();
        return;
    }

    Bill* bills = new Bill[N];

    for (int i = 0; i < N; ++i)
    {
        // ������� payer_account
        size_t len;
        fin.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        bills[i].payer_account = buffer;
        delete[] buffer;

        // ������� recipient_account
        fin.read((char*)&len, sizeof(len));
        buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        bills[i].recipient_account = buffer;
        delete[] buffer;

        // ������� amount
        fin.read((char*)&bills[i].amount, sizeof(bills[i].amount));
    }

    fin.close();

    // ������� ����� bills �� payer_account (����������� ����������)
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (bills[j].payer_account > bills[j + 1].payer_account)
            {
                Bill temp = bills[j];
                bills[j] = bills[j + 1];
                bills[j + 1] = temp;
            }
        }
    }

    // �������� ����������� ������ ����� � ����
    ofstream fout(filename, ios::binary);
    if (!fout)
    {
        cout << "������� �������� ����� ��� ������!\n";
        delete[] bills;
        return;
    }

    fout.write((char*)&N, sizeof(N));

    for (int i = 0; i < N; ++i)
    {
        // �������� payer_account
        size_t len = bills[i].payer_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bills[i].payer_account.c_str(), len);

        // �������� recipient_account
        len = bills[i].recipient_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bills[i].recipient_account.c_str(), len);

        // �������� amount
        fout.write((char*)&bills[i].amount, sizeof(bills[i].amount));
    }

    fout.close();
    delete[] bills;
    cout << "��� ������ ������������ �� �������� � ����.\n";
}

void OutputTotalAmountByPayerFromFile(const char* filename, const string& payer_account)
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "������� �������� ����� ��� �������!\n";
        return;
    }

    int N;
    fin.read((char*)&N, sizeof(N));
    if (N <= 0)
    {
        cout << "���� �� ������ �����.\n";
        fin.close();
        return;
    }

    double total_amount = 0.0;
    bool found = false;

    for (int i = 0; i < N; ++i)
    {
        Bill bill;

        // ������� payer_account
        size_t len;
        fin.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        bill.payer_account = buffer;
        delete[] buffer;

        // ������� recipient_account
        fin.read((char*)&len, sizeof(len));
        buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        bill.recipient_account = buffer;
        delete[] buffer;

        // ������� amount
        fin.read((char*)&bill.amount, sizeof(bill.amount));

        if (bill.payer_account == payer_account)
        {
            total_amount += bill.amount;
            found = true;
        }
    }

    fin.close();

    if (found)
    {
        cout << "����, ����� � ������� " << payer_account << ": " << total_amount << " ���.\n";
    }
    else
    {
        cout << "�������� � ������������� �������� " << payer_account << " �� ��������.\n";
    }
}
