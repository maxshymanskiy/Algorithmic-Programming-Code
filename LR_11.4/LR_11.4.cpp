#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Функція для створення текстового файлу F з користувацьким вводом
void createFileF(const string& fileName) 
{
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Помилка створення файлу " << fileName << "!" << endl;
        return;
    }
    cout << "Введіть рядки для файлу " << fileName << ". Введіть 'END' для завершення вводу:\n";
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        outFile << line << endl;
    }

    outFile.close();
    cout << "Файл " << fileName << " створено успішно.\n";
}

// Функція для переписування рядків з файлу F до файлу H з додаванням номерів та довжини
void copyFileWithModification(const string& inputFileName, const string& outputFileName) 
{
    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);

    if (!inFile) {
        cerr << "Помилка відкриття файлу " << inputFileName << " для читання!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "Помилка відкриття файлу " << outputFileName << " для запису!" << endl;
        return;
    }

    string line;
    int lineNumber = 1;
    while (getline(inFile, line)) {
        int length = line.length();
        outFile << lineNumber << " " << line << " " << length << endl;
        lineNumber++;
    }

    inFile.close();
    outFile.close();
    cout << "Файл " << outputFileName << " створено успішно.\n";
}

void menu() {
    while (true) {
        int choice;
        cout << "\n--- Меню ---\n";
        cout << "1. Створити файл F\n";
        cout << "2. Переписати рядки з F до H з додаванням номерів та довжини\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(); // Ігноруємо символ нового рядка після введення числа

        if (choice == 1) {
            string fileName;
            cout << "Введіть ім'я файлу F: ";
            cin >> fileName;
            cin.ignore(); // Ігноруємо символ нового рядка після введення імені
            createFileF(fileName);
        }
        else if (choice == 2) {
            string inputFileName, outputFileName;
            cout << "Введіть ім'я вхідного файлу F: ";
            cin >> inputFileName;
            cout << "Введіть ім'я вихідного файлу H: ";
            cin >> outputFileName;
            copyFileWithModification(inputFileName, outputFileName);
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();

    return 0;
}
