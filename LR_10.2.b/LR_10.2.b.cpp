#include <cmath> // ��� ������� abs ��� �������� ������� ����
#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;

// ������ ��������������
enum Specialnist { KN, INF, ME, FI, TN }; // KN - ����'����� �����, INF - �����������, ME - ���������� �� ��������, FI - Գ���� �� �����������, TN - ������� ��������
string specialnistStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

// ��������� ��������
struct Student
{
	string prizv;
	unsigned kurs;
	Specialnist specialnist;
	int ocinkaFizyka;
	int ocinkaMatematika;
	union
	{
		int ocinkaProgramming;
		int ocinkaNumericalMethods;
		int ocinkaPedagogics;
	};
	// ������� ��� ���������� ���������� ����
	double avg() const {
		int thirdGrade = (specialnist == KN) ? ocinkaProgramming :
			(specialnist == INF) ? ocinkaNumericalMethods : ocinkaPedagogics;
		return (ocinkaFizyka + ocinkaMatematika + thirdGrade) / 3.0;
	}
};

// ��������� �������
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
int BinSearch(Student* p, const int N, const string prizv, const unsigned kurs, const double avg);
int GetIntInRange(const string& prompt, int min, int max);
void ClearInputBuffer();

int main()
{
	// ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

	int N;
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];
	int ispec;
	string prizv;
	unsigned kurs;
	double avg;
	int found;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������� ������������� �����" << endl;
		cout << " [4] - �������� ������������� �� ���� �����" << endl;
		cout << " [5] - ������� ����� �������� �� ��������, ������ �� ������� �����" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			cout << "��� ����������� �������." << endl;
			break;
		case 4:
		{
			int* indices = IndexSort(p, N);
			PrintIndexSorted(p, indices, N);
			delete[] indices;
		}
		break;
		case 5:
			cout << "������ ����� ������:" << endl;
			cin.get(); // ������� ����� ���������
			cout << " �������: "; getline(cin, prizv);
			kurs = GetIntInRange(" ���� (1-6): ", 1, 6);
			cout << " ������� ���: "; cin >> avg;
			found = BinSearch(p, N, prizv, kurs, avg);
			if (found != -1)
				cout << "�������� �������� � ������� " << found + 1 << endl;
			else
				cout << "�������� �������� �� ��������" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	delete[] p;
	return 0;
}

void Create(Student* p, const int N)
{
	int specialnist;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ���������
		cout << " �������: "; getline(cin, p[i].prizv);
		p[i].kurs = GetIntInRange(" ���� (1-6): ", 1, 6);
		cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		p[i].specialnist = (Specialnist)GetIntInRange("", 0, 4);
		p[i].ocinkaFizyka = GetIntInRange(" ������ � ������ (1-5): ", 1, 5);
		p[i].ocinkaMatematika = GetIntInRange(" ������ � ���������� (1-5): ", 1, 5);
		switch (p[i].specialnist)
		{
		case KN:
			p[i].ocinkaProgramming = GetIntInRange(" ������ � ������������� (1-5): ", 1, 5);
			break;
		case INF:
			p[i].ocinkaNumericalMethods = GetIntInRange(" ������ � ��������� ������ (1-5): ", 1, 5);
			break;
		default:
			p[i].ocinkaPedagogics = GetIntInRange(" ������ � ��������� (1-5): ", 1, 5);
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "==============================================================================================================================" << endl;
	cout << "| � |     �������     | ���� |      ������������      | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(17) << left << p[i].prizv;
		cout << "| " << setw(4) << right << p[i].kurs << " ";
		cout << "| " << setw(22) << left << specialnistStr[p[i].specialnist];
		cout << "| " << setw(7) << right << p[i].ocinkaFizyka << " ";
		cout << "| " << setw(10) << right << p[i].ocinkaMatematika << " ";
		switch (p[i].specialnist)
		{
		case KN:
			cout << "| " << setw(13) << right << p[i].ocinkaProgramming << " |" << setw(17) << right << "|" << setw(13) << right << "|" << endl;
			break;
		case INF:
			cout << "| " << setw(15) << right << "|" << setw(15) << right << p[i].ocinkaNumericalMethods << " |" << setw(13) << right << "|" << endl;
			break;
		default:
			cout << "| " << setw(15) << right << "|" << setw(17) << right << "|" << setw(13) << right << p[i].ocinkaPedagogics << " |" << endl;
			break;
		}
	}
	cout << "==============================================================================================================================" << endl;
	cout << endl;
}

void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (
				(p[i1].avg() < p[i1 + 1].avg()) || // ������� ��� �� ���������
				(abs(p[i1].avg() - p[i1 + 1].avg()) < 1e-6 && p[i1].prizv < p[i1 + 1].prizv) || // ������� � ���������� �������
				(abs(p[i1].avg() - p[i1 + 1].avg()) < 1e-6 && p[i1].prizv == p[i1 + 1].prizv && p[i1].kurs > p[i1 + 1].kurs) // ����
				)
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

int* IndexSort(Student* p, const int N)
{
	int* I = new int[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		I[i] = i; // ��������� ���� ����������� ������
	int i, j, value; // �������� ��������� ����� �������
	for (i = 1; i < N; i++)
	{
		value = I[i];
		j = i - 1;
		while (j >= 0 &&
			(
				(p[I[j]].avg() < p[value].avg()) || // ������� ��� �� ���������
				(abs(p[I[j]].avg() - p[value].avg()) < 1e-6 && p[I[j]].prizv > p[value].prizv) || // ������� �� ��������
				(abs(p[I[j]].avg() - p[value].avg()) < 1e-6 && p[I[j]].prizv == p[value].prizv && p[I[j]].kurs > p[value].kurs) // ����
				))
		{
			I[j + 1] = I[j];
			j--;
		}
		I[j + 1] = value;
	}
	return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{
	cout << "��� ���� ���������� ����������:\n";
	cout << "==============================================================================================================================" << endl;
	cout << "| � |     �������     | ���� |      ������������      | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++)
	{
		int idx = I[i];
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(17) << left << p[idx].prizv;
		cout << "| " << setw(4) << right << p[idx].kurs << " ";
		cout << "| " << setw(22) << left << specialnistStr[p[idx].specialnist];
		cout << "| " << setw(7) << right << p[idx].ocinkaFizyka << " ";
		cout << "| " << setw(10) << right << p[idx].ocinkaMatematika << " ";
		switch (p[idx].specialnist)
		{
		case KN:
			cout << "| " << setw(13) << right << p[idx].ocinkaProgramming << " |" << setw(17) << right << "|" << setw(13) << right << "|" << endl;
			break;
		case INF:
			cout << "| " << setw(15) << right << "|" << setw(15) << right << p[idx].ocinkaNumericalMethods << " |" << setw(13) << right << "|" << endl;
			break;
		default:
			cout << "| " << setw(15) << right << "|" << setw(17) << right << "|" << setw(13) << right << p[idx].ocinkaPedagogics << " |" << endl;
			break;
		}
	}
	cout << "========================================================================================================================" << endl;
	cout << endl;
}

int BinSearch(Student* p, const int N, const string prizv, const unsigned kurs, const double avg)
{
	int L = 0, R = N - 1, m;
	while (L <= R)
	{
		m = (L + R) / 2;
		double m_avg = p[m].avg();
		if (p[m].prizv == prizv && p[m].kurs == kurs && abs(m_avg - avg) < 1e-6)
			return m;
		if (
			(p[m].avg() < avg) ||
			(abs(p[m].avg() - avg) < 1e-6 && p[m].prizv < prizv) ||
			(abs(p[m].avg() - avg) < 1e-6 && p[m].prizv == prizv && p[m].kurs > kurs)
			)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	}
	return -1;
}

int GetIntInRange(const string& prompt, int min, int max) {
	int value;
	bool valid;
	do {
		cout << prompt;
		cin >> value;
		valid = !cin.fail() && value >= min && value <= max;
		if (!valid) {
			cout << " ����������� ��������. ��������� �� ���.\n";
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (!valid);
	return value;
}

void ClearInputBuffer() {
	cin.ignore(32767, '\n');
}
