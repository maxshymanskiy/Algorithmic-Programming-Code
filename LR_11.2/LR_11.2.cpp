#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <Windows.h>

using namespace std;

// Функція, яка обробляє рядок з урахуванням заданих умов
void processLine(char* line, ofstream& outputFile) {
    int i = 0;
    int len = strlen(line);

    while (i < len) {
        if (isdigit(line[i])) {
            bool precededByDot = (i > 0 && line[i - 1] == '.');
            int j = i;

            while (j < len && isdigit(line[j])) {
                j++;
            }

            char digitGroup[1024];
            int groupLen = j - i;
            strncpy(digitGroup, &line[i], groupLen);
            digitGroup[groupLen] = '\0';

            if (!precededByDot) {
                // Видаляємо початкові нулі
                int k = 0;
                while (digitGroup[k] == '0' && digitGroup[k + 1] != '\0') {
                    k++;
                }

                // Якщо всі цифри були нулями і після них іде крапка, залишаємо один нуль
                if (digitGroup[k] == '\0' && line[j] == '.') {
                    strcpy(digitGroup, "0");
                }
                else {
                    int m = 0;
                    while (digitGroup[k] != '\0') {
                        digitGroup[m++] = digitGroup[k++];
                    }
                    digitGroup[m] = '\0';
                }
            }
            else {
                // Скорочуємо дробову частину до двох цифр
                if (strlen(digitGroup) > 2) {
                    digitGroup[2] = '\0';
                }
            }

            // Записуємо оброблену групу цифр у вихідний файл
            outputFile << digitGroup;
            i = j;
        }
        else {
            // Записуємо символ у вихідний файл
            outputFile.put(line[i]);
            i++;
        }
    }
    outputFile.put('\n');  
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* inputFileName = "t1.txt";  // Вхідний файл
    const char* outputFileName = "t2.txt"; // Вихідний файл

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Помилка відкриття вхідного файлу!" << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Помилка відкриття вихідного файлу!" << endl;
        return 1;
    }

    char line[1024];  

    while (inputFile.getline(line, sizeof(line))) {
        processLine(line, outputFile);
    }

    inputFile.close();
    outputFile.close();

    cout << "Обробка завершена. Результат записано у файл " << outputFileName << endl;
    return 0;
}
