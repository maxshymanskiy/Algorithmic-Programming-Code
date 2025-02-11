#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int countCommaDash(const string& line) {
    int count = 0;
    for (size_t i = 1; i + 1 < line.length(); i++) {
        if (line[i - 1] == ',' && line[i + 1] == '-') {
            count++;
        }
    }
    return count;
}

int countCommaDashInFile(const string& filename) {
    ifstream file(filename); 
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл: " << filename << endl;
        return 0;
    }

    int totalCount = 0;
    string line;
    while (getline(file, line)) { 
        totalCount += countCommaDash(line);
    }

    file.close(); 
    return totalCount;
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    string filename = "t.txt"; 
    int result = countCommaDashInFile(filename); 

    if (result > 0) {
        cout << "У файлі знайдено " << result << " груп(и) ', -'." << endl;
    }
    else {
        cout << "У файлі НЕ знайдено груп ', -'." << endl;
    }

    return 0;
}


