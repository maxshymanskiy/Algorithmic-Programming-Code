#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { KN, INF, ME, FI, TN };
string specialnistStr[] = { "Комп'ютерні науки", "Інформатика", "Мат-економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    int ocinkaFizyka;
    int ocinkaMatematika;

    union {
        int ocinkaProgramming;
        int ocinkaNumericalMethods;
        int ocinkaPedagogics;
    };
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

        if (s[i].specialnist == KN) {
            cout << "Оцінка програмування: "; cin >> s[i].ocinkaProgramming;
        }
        else if (s[i].specialnist == INF) {
            cout << " Оцінка з числових методів : "; cin >> s[i].ocinkaNumericalMethods;
        }
        else {
            cout << " Оцінка за педагогіку: "; cin >> s[i].ocinkaPedagogics;
        }
        cout << endl;

        cout << endl;
    }
}

void Print(const Student* s, const int N) {
    cout << "=========================================================================================================================" << endl;
    cout << "| № | Прізвище        | Курс | Спеціальність        | Фізики| Математики | Програмування | Чисельні методи | Педагогіка |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| "
            << setw(1) << right << i + 1 << " | "                      
            << setw(15) << left << s[i].prizv << " | "                  
            << setw(4) << left << s[i].kurs << " | "                   
            << setw(20) << left << specialnistStr[s[i].specialnist] << " | "
            << setw(5) << right << fixed << setprecision(0) << s[i].ocinkaFizyka << " | " 
            << setw(10) << right << fixed << setprecision(0) << s[i].ocinkaMatematika << " | "; 

        if (s[i].specialnist == KN) {
            cout << setw(13) << right << (s[i].ocinkaProgramming > 0 ? to_string(static_cast<int>(s[i].ocinkaProgramming)) : "-") << " | " 
                << setw(15) << right << (s[i].ocinkaNumericalMethods > 0 ? to_string(static_cast<int>(s[i].ocinkaNumericalMethods)) : "-") << " | " 
                << setw(10) << right << "-" << " |" << endl;                              
        }
        else if (s[i].specialnist == INF) {
            cout << setw(13) << right << "-" << " | "                                          
                << setw(15) << right << (s[i].ocinkaNumericalMethods > 0 ? to_string(static_cast<int>(s[i].ocinkaNumericalMethods)) : "-") << " | " 
                << setw(10) << right << (s[i].ocinkaPedagogics > 0 ? to_string(static_cast<int>(s[i].ocinkaPedagogics)) : "-") << " |" << endl;                                    
        }
        else {
            cout << setw(13) << right << "-" << " | "                                             
                << setw(15) << right << "-" << " | "                                            
                << setw(10) << right << (s[i].ocinkaPedagogics > 0 ? to_string(static_cast<int>(s[i].ocinkaPedagogics)) : "-") << " |" << endl; 
        }
    }

    cout << "=========================================================================================================================s" << endl;
}

int FindStudentWithMinAverage(const Student* s, const int N) {
    int minIndex = 0;
    double minAvg = (s[0].ocinkaFizyka + s[0].ocinkaMatematika + (s[0].specialnist == KN ? s[0].ocinkaProgramming :
        (s[0].specialnist == INF ? s[0].ocinkaNumericalMethods : s[0].ocinkaPedagogics))) / 3.0;

    for (int i = 1; i < N; i++) {
        double avg = (s[i].ocinkaFizyka + s[i].ocinkaMatematika + (s[i].specialnist == KN ? s[i].ocinkaProgramming :
            (s[i].specialnist == INF ? s[i].ocinkaNumericalMethods : s[i].ocinkaPedagogics))) / 3.0;
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

//void CountSatisfactoryGrades(const Student* s, const int N) {
//    int satisfactoryPhysics = 0, satisfactoryMath = 0, satisfactoryInformatics = 0;
//
//    for (int i = 0; i < N; i++) {
//        if (s[i].ocinkaFizyka == 3) satisfactoryPhysics++;
//        if (s[i].ocinkaMatematika == 3) satisfactoryMath++;
//
//        if (s[i].specialnist == KN && s[i].ocinkaProgramming == 3) satisfactoryInformatics++;
//        else if (s[i].specialnist == INF && s[i].ocinkaNumericalMethods == 3) satisfactoryInformatics++;
//        else if (s[i].specialnist != KN && s[i].specialnist != INF && s[i].ocinkaPedagogics == 3) satisfactoryInformatics++;
//    }
//    cout << "Кількість задовільних оцінок з фізики: " << satisfactoryPhysics << endl;
//    cout << "Кількість задовільних оцінок з математики: " << satisfactoryMath << endl;
//    cout << "Кількість задовільних оцінок з інформатики: " << satisfactoryInformatics << endl;
//} 
void CountSatisfactoryGrades(const Student* s, const int N) {
    int satisfactoryPhysics = 0, satisfactoryMath = 0;
    int satisfactoryProgramming = 0, satisfactoryNumericalMethods = 0, satisfactoryPedagogics = 0;

    for (int i = 0; i < N; i++) {
        // Перевірка фізики
        if (s[i].ocinkaFizyka == 3)
            satisfactoryPhysics++;

        // Перевірка математики
        if (s[i].ocinkaMatematika == 3)
            satisfactoryMath++;

        // Перевірка програмування
        if (s[i].ocinkaProgramming == 3)
            satisfactoryProgramming++;

        // Перевірка чисельних методів
        if (s[i].ocinkaNumericalMethods == 3)
            satisfactoryNumericalMethods++;

        // Перевірка педагогіки
        if (s[i].ocinkaPedagogics == 3)
            satisfactoryPedagogics++;
    }

    cout << "Кількість задовільних оцінок з фізики: " << satisfactoryPhysics << endl;
    cout << "Кількість задовільних оцінок з математики: " << satisfactoryMath << endl;
    cout << "Кількість задовільних оцінок з програмування: " << satisfactoryProgramming << endl;
    cout << "Кількість задовільних оцінок з чисельних методів: " << satisfactoryNumericalMethods << endl;
    cout << "Кількість задовільних оцінок з педагогіки: " << satisfactoryPedagogics << endl;
}
