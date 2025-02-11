#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// ������� ��� ��������� ���������� ����� F � �������������� ������
void createFileF(const string& fileName) 
{
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "������� ��������� ����� " << fileName << "!" << endl;
        return;
    }
    cout << "������ ����� ��� ����� " << fileName << ". ������ 'END' ��� ���������� �����:\n";
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        outFile << line << endl;
    }

    outFile.close();
    cout << "���� " << fileName << " �������� ������.\n";
}

// ������� ��� ������������� ����� � ����� F �� ����� H � ���������� ������ �� �������
void copyFileWithModification(const string& inputFileName, const string& outputFileName) 
{
    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);

    if (!inFile) {
        cerr << "������� �������� ����� " << inputFileName << " ��� �������!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "������� �������� ����� " << outputFileName << " ��� ������!" << endl;
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
    cout << "���� " << outputFileName << " �������� ������.\n";
}

void menu() {
    while (true) {
        int choice;
        cout << "\n--- ���� ---\n";
        cout << "1. �������� ���� F\n";
        cout << "2. ���������� ����� � F �� H � ���������� ������ �� �������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;
        cin.ignore(); // �������� ������ ������ ����� ���� �������� �����

        if (choice == 1) {
            string fileName;
            cout << "������ ��'� ����� F: ";
            cin >> fileName;
            cin.ignore(); // �������� ������ ������ ����� ���� �������� ����
            createFileF(fileName);
        }
        else if (choice == 2) {
            string inputFileName, outputFileName;
            cout << "������ ��'� �������� ����� F: ";
            cin >> inputFileName;
            cout << "������ ��'� ��������� ����� H: ";
            cin >> outputFileName;
            copyFileWithModification(inputFileName, outputFileName);
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "������� ����. ��������� �� ���.\n";
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();

    return 0;
}
