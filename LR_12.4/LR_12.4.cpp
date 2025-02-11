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
    // Налаштування консолі для коректного відображення українських символів
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    char filename[100];
    string payer_account;

    do
    {
        cout << "\nМеню:\n";
        cout << "1. Введення даних з клавіатури у файл\n";
        cout << "2. Впорядкування записів у файлі за розрахунковими рахунками платників\n";
        cout << "3. Виведення інформації про суму, зняту з розрахункового рахунку платника\n";
        cout << "0. Вихід\n";
        cout << "Введіть ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Введіть ім'я файлу для запису: ";
            cin.getline(filename, 100);
            InputBillsToFile(filename);
            break;
        case 2:
            cout << "Введіть ім'я файлу для впорядкування: ";
            cin.getline(filename, 100);
            SortBillsInFile(filename);
            break;
        case 3:
            cout << "Введіть ім'я файлу для пошуку: ";
            cin.getline(filename, 100);
            cout << "Введіть розрахунковий рахунок платника: ";
            getline(cin, payer_account);
            OutputTotalAmountByPayerFromFile(filename, payer_account);
            break;
        case 0:
            cout << "Завершення роботи програми.\n";
            break;
        default:
            cout << "Неправильний вибір. Спробуйте знову.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

void InputBillsToFile(const char* filename)
{
    int N;
    cout << "Введіть кількість платежів: ";
    while (!(cin >> N) || N <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Неправильне значення. Введіть N знову: ";
    }
    cin.ignore();

    ofstream fout(filename, ios::binary);
    if (!fout)
    {
        cout << "Помилка відкриття файлу для запису!\n";
        return;
    }

    // Записуємо N у файл
    fout.write((char*)&N, sizeof(N));

    Bill bill;
    for (int i = 0; i < N; ++i)
    {
        cout << "Платіж №" << i + 1 << ":\n";
        cout << "Розрахунковий рахунок платника: ";
        getline(cin, bill.payer_account);
        cout << "Розрахунковий рахунок одержувача: ";
        getline(cin, bill.recipient_account);
        cout << "Перерахована сума (грн.): ";
        while (!(cin >> bill.amount) || bill.amount < 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Неправильне значення. Введіть суму знову: ";
        }
        cin.ignore(); // Очищаємо буфер вводу

        // Записуємо bill у файл

        // Записуємо payer_account
        size_t len = bill.payer_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bill.payer_account.c_str(), len);

        // Записуємо recipient_account
        len = bill.recipient_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bill.recipient_account.c_str(), len);

        // Записуємо amount
        fout.write((char*)&bill.amount, sizeof(bill.amount));
    }

    fout.close();
    cout << "Дані успішно записано у файл.\n";
}

void SortBillsInFile(const char* filename)
{
    // Читаємо всі записи з файлу в масив
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Помилка відкриття файлу для читання!\n";
        return;
    }

    int N;
    fin.read((char*)&N, sizeof(N));
    if (N <= 0)
    {
        cout << "Файл не містить даних для сортування.\n";
        fin.close();
        return;
    }

    Bill* bills = new Bill[N];

    for (int i = 0; i < N; ++i)
    {
        // Зчитуємо payer_account
        size_t len;
        fin.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
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

    // Сортуємо масив bills за payer_account (бульбашкове сортування)
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

    // Записуємо впорядковані записи назад у файл
    ofstream fout(filename, ios::binary);
    if (!fout)
    {
        cout << "Помилка відкриття файлу для запису!\n";
        delete[] bills;
        return;
    }

    fout.write((char*)&N, sizeof(N));

    for (int i = 0; i < N; ++i)
    {
        // Записуємо payer_account
        size_t len = bills[i].payer_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bills[i].payer_account.c_str(), len);

        // Записуємо recipient_account
        len = bills[i].recipient_account.length();
        fout.write((char*)&len, sizeof(len));
        fout.write(bills[i].recipient_account.c_str(), len);

        // Записуємо amount
        fout.write((char*)&bills[i].amount, sizeof(bills[i].amount));
    }

    fout.close();
    delete[] bills;
    cout << "Дані успішно впорядковано та записано у файл.\n";
}

void OutputTotalAmountByPayerFromFile(const char* filename, const string& payer_account)
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Помилка відкриття файлу для читання!\n";
        return;
    }

    int N;
    fin.read((char*)&N, sizeof(N));
    if (N <= 0)
    {
        cout << "Файл не містить даних.\n";
        fin.close();
        return;
    }

    double total_amount = 0.0;
    bool found = false;

    for (int i = 0; i < N; ++i)
    {
        Bill bill;

        // Зчитуємо payer_account
        size_t len;
        fin.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        bill.payer_account = buffer;
        delete[] buffer;

        // Зчитуємо recipient_account
        fin.read((char*)&len, sizeof(len));
        buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        bill.recipient_account = buffer;
        delete[] buffer;

        // Зчитуємо amount
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
        cout << "Сума, знята з рахунку " << payer_account << ": " << total_amount << " грн.\n";
    }
    else
    {
        cout << "Платника з розрахунковим рахунком " << payer_account << " не знайдено.\n";
    }
}
