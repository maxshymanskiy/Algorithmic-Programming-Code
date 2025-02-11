#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

/*
{ "Ivanenko", 2, 0, 3, 4, 5 },
{ "Petrenko", 3, 1, 2, 3, 4 },
{ "Sydorenko", 1, 2, 5, 5, 5 }
*/

enum Specialnist { RI, IK, SSHI };
string specialnistStr[] = { "РІ", "ІК", "СШІ" };

struct Student {
	string prizv;
	unsigned kurs;
	Specialnist specialnist;
	int ocinkaFizyka;
	int ocinkaMatematika;
	int ocinkaInformatika;

	double avg() const {
		return (ocinkaFizyka + ocinkaMatematika + ocinkaInformatika) / 3.0;
	}
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
int FindStudentWithMinAverage(const Student* s, const int N);
void CountSatisfactoryGrades(const Student* s, const int N);
void PrintStudentWithMinAverage(const Student* s, const int N);
void SortPhysical(Student* s, const int N);
void PrintIndexSorted(const Student* s, const int* I, const int N);
int* IndexSort(Student* s, const int N);
int BinSearch(const Student* s, const int N, const string prizv, unsigned kurs, double avg);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* s = new Student[N];

	string prizv;
	unsigned kurs;
	double avg;

	int menuItem;
	int indexBin = -1;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl << endl;
		cout << " [4] - індексне впорядкування даних" << endl << endl;
		cout << " [5] - бінарний пошук" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			SortPhysical(s, N);
			cout << "Дані фізично впорядковано." << endl;
			break;
		case 4:
		{
			int* indexArray = IndexSort(s, N);
			PrintIndexSorted(s, indexArray, N);
			delete[] indexArray;
			break;
		}
		case 5:
			SortPhysical(s, N);
			cout << "Введіть прізвище студента для пошуку: "; cin >> prizv;
			cout << "Введіть курс студента: "; cin >> kurs;
			cout << "Введіть середній бал студента: "; cin >> avg;

			indexBin = BinSearch(s, N, prizv, kurs, avg);

			if (indexBin != -1) {
				cout << "Студента знайдено:" << endl;
				cout << "Прізвище: " << s[indexBin].prizv << endl;
				cout << "Курс: " << s[indexBin].kurs << endl;
				cout << "Спеціальність: " << specialnistStr[s[indexBin].specialnist] << endl;
				cout << "Середній бал: " << fixed << setprecision(2) << s[indexBin].avg() << endl;
			}
			else {
				cout << "Студента з таким прізвищем, курсом та середнім балом не знайдено!" << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	PrintStudentWithMinAverage(s, N);
	CountSatisfactoryGrades(s, N);

	delete[] s;
	return 0;
}

void Create(Student* s, const int N) {
	int specialnist;
	for (int i = 0; i < N; i++) {
		cout << "Студент № " << i + 1 << ":" << endl;
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
	cout << "=================================================================================" << endl;
	cout << "| № | Прізвище       | Курс | Спеціальність | Фізика | Математика | Інформатика |" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << i + 1
			<< " | " << setw(15) << left << s[i].prizv
			<< "|  " << setw(3) << left << s[i].kurs
			<< " | " << setw(13) << left << specialnistStr[s[i].specialnist]
			<< " | " << setw(6) << s[i].ocinkaFizyka
			<< " | " << setw(10) << s[i].ocinkaMatematika
			<< " | " << setw(11) << s[i].ocinkaInformatika << " |" << endl;
	}
	cout << "=================================================================================" << endl;
}

int FindStudentWithMinAverage(const Student* s, const int N) {
	int minIndex = 0;
	double minAvg = s[0].avg();

	for (int i = 1; i < N; i++) {
		double avg = s[i].avg();
		if (avg < minAvg) {
			minAvg = avg;
			minIndex = i;
		}
	}
	return minIndex;
}

void PrintStudentWithMinAverage(const Student* s, const int N) {
	int minIndex = FindStudentWithMinAverage(s, N);
	cout << "Студент з найнижчим середнім балом: " << s[minIndex].prizv << endl;
}

void CountSatisfactoryGrades(const Student* s, const int N) {
	int satisfactoryPhysics = 0, satisfactoryMath = 0, satisfactoryInformatics = 0;

	for (int i = 0; i < N; i++) {
		if (s[i].ocinkaFizyka == 3) satisfactoryPhysics++;
		if (s[i].ocinkaMatematika == 3) satisfactoryMath++;
		if (s[i].ocinkaInformatika == 3) satisfactoryInformatics++;
	}

	cout << "Кількість оцінок 'задовільно' з фізики: " << satisfactoryPhysics << endl;
	cout << "Кількість оцінок 'задовільно' з математики: " << satisfactoryMath << endl;
	cout << "Кількість оцінок 'задовільно' з інформатики: " << satisfactoryInformatics << endl;
}

void SortPhysical(Student* s, const int N) {
	for (int i0 = 0; i0 < N - 1; i0++) {
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if (
				(s[i1].avg() > s[i1 + 1].avg()) ||
				(s[i1].avg() == s[i1 + 1].avg() && s[i1].prizv < s[i1 + 1].prizv) ||
				(s[i1].avg() == s[i1 + 1].avg() && s[i1].prizv == s[i1 + 1].prizv && s[i1].kurs > s[i1 + 1].kurs)
				) {
				Student tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
		}
	}
}

int* IndexSort(Student* s, const int N) {
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;

	int i, j, value;
	for (i = 1; i < N; i++) {
		value = I[i];
		j = i - 1;
		while (j >= 0 && (
			(s[I[j]].avg() > s[value].avg()) ||
			(s[I[j]].avg() == s[value].avg() && s[I[j]].prizv > s[value].prizv) ||
			(s[I[j]].avg() == s[value].avg() && s[I[j]].prizv == s[value].prizv && s[I[j]].kurs > s[value].kurs)
			)) {
			I[j + 1] = I[j];
			j--;
		}
		I[j + 1] = value;
	}
	return I;
}

int BinSearch(const Student* s, const int N, const string prizv, unsigned kurs, double avg) {
	int L = 0, R = N - 1, m;
	while (L <= R) {
		m = (L + R) / 2;
		if (s[m].prizv == prizv && s[m].kurs == kurs && s[m].avg() == avg)
			return m;
		if (
			(s[m].prizv < prizv) ||
			(s[m].prizv == prizv && s[m].kurs < kurs) ||
			(s[m].prizv == prizv && s[m].kurs == kurs && s[m].avg() < avg)
			) {
			L = m + 1;
		}
		else {
			R = m - 1;
		}
	}
	return -1;
}

void PrintIndexSorted(const Student* s, const int* I, const int N) {
	cout << "Студенти, впорядковані за середнім балом:" << endl;
	cout << "============================================================" << endl;
	cout << "| № | Прізвище       | Курс | Спеціальність | Середній бал |" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << i + 1
			<< " | " << setw(14) << left << s[I[i]].prizv
			<< " |  " << setw(3) << left << s[I[i]].kurs
			<< " | " << setw(13) << left << specialnistStr[s[I[i]].specialnist]
			<< " | " << setw(12) << fixed << setprecision(2) << s[I[i]].avg() << " |" << endl;
	}
	cout << "============================================================" << endl;
}
