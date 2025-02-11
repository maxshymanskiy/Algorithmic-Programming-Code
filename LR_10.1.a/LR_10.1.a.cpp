#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { RI, IK, SSHI };
string specialnistStr[] = { "РІ", "ІК", "СШІ" };

struct Student {
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    int ocinkaFizyka;
    int ocinkaMatematika;
    int ocinkaInformatika;
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
int FindStudentWithMinAverage(const Student* s, const int N);
void CountSatisfactoryGrades(const Student* s, const int N);
void PrintStudentWithMinAverage(const Student* s, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Кількість студентів: "; cin >> N;

    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    PrintStudentWithMinAverage(s, N);
    CountSatisfactoryGrades(s, N);

    delete[] s;
    return 0;
}

void Create(Student* s, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "Студент №" << i + 1 << ":" << endl;
        cin.get();
        cout << " Прізвище: "; getline(cin, s[i].prizv);
        cout << " Курс: "; cin >> s[i].kurs;
        cout << " Спеціальність (0 - РІ, 1 - ІК, 2 - СШІ): ";
        cin >> specialnist;
        s[i].specialnist = (Specialnist)specialnist;
        cout << " Оцінка з фізики: "; cin >> s[i].ocinkaFizyka;
        cout << " Оцінка з математики: "; cin >> s[i].ocinkaMatematika;
        cout << " Оцінка з інформатики: "; cin >> s[i].ocinkaInformatika;
        cout << endl;
    }
}

void Print(const Student* s, const int N) {
    cout << "===========================================================================================================" << endl;
    cout << "| № | Прізвище      | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з інформатики |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(1) << i + 1
            << " | " << setw(14) << left << s[i].prizv
            << "|  " << setw(3) << left << s[i].kurs
            << " | " << setw(13) << left << specialnistStr[s[i].specialnist]
            << " | " << setw(15) << s[i].ocinkaFizyka
            << " | " << setw(19) << s[i].ocinkaMatematika
            << " | " << setw(20) << s[i].ocinkaInformatika << " |" << endl;
    }
    cout << "===========================================================================================================" << endl;
}

int FindStudentWithMinAverage(const Student* s, const int N) {
    int minIndex = 0;
    double minAvg = (s[0].ocinkaFizyka + s[0].ocinkaMatematika + s[0].ocinkaInformatika) / 3.0;

    for (int i = 1; i < N; i++) {
        double avg = (s[i].ocinkaFizyka + s[i].ocinkaMatematika + s[i].ocinkaInformatika) / 3.0;
        if (avg < minAvg) {
            minAvg = avg;
            minIndex = i;
        }
    }
    return minIndex;
}

void PrintStudentWithMinAverage(const Student* s, const int N) {
    int minIndex = FindStudentWithMinAverage(s, N);
    cout << "Студента, у якого найменший середній бал: " << s[minIndex].prizv << endl;
}

void CountSatisfactoryGrades(const Student* s, const int N) {
    int satisfactoryPhysics = 0, satisfactoryMath = 0, satisfactoryInformatics = 0;

    for (int i = 0; i < N; i++) {
        if (s[i].ocinkaFizyka == 3) satisfactoryPhysics++;
        if (s[i].ocinkaMatematika == 3) satisfactoryMath++;
        if (s[i].ocinkaInformatika == 3) satisfactoryInformatics++;
    }

    cout << "Кількість задовільних оцінок з фізики: " << satisfactoryPhysics << endl;
    cout << "Кількість задовільних оцінок з математики: " << satisfactoryMath << endl;
    cout << "Кількість задовільних оцінок з інформатики: " << satisfactoryInformatics << endl;
}