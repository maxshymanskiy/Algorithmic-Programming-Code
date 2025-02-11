#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** a, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** a, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);


int main()
{
	srand((unsigned)time(NULL));
	int Low = 11;
	int High = 74;
	int rowCount = 8;
	int colCount = 9;
	int** a = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);

	Print(a, rowCount, colCount);

	Sort(a, rowCount, colCount);

	Print(a, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	Print(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		else {
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
		}
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			cout << setw(4) << a[i][j];
			Print(a, rowCount, colCount, i, j + 1);
		}
		else {
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
	}
	else if (i == rowCount && j == 0) {
		cout << endl;
	}
}

void Sort(int** a, const int rowCount, const int colCount, int i0, int i1)
{
	if (i0 < rowCount - 1) {
		if (i1 < rowCount - i0 - 1) {
			if ((a[i1][0] > a[i1 + 1][0])
				|| (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1])
				|| (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] < a[i1 + 1][3])) {
				Change(a, i1, i1 + 1, colCount);
			}
			Sort(a, rowCount, colCount, i0, i1 + 1);
		}
		else {
			Sort(a, rowCount, colCount, i0 + 1, 0);
		}
	}
}

void Change(int** y, const int row1, const int row2, const int colCount, int j)
{
	if (j < colCount) {
		int tmp = y[row1][j];
		y[row1][j] = y[row2][j];
		y[row2][j] = tmp;
		Change(y, row1, row2, colCount, j + 1);
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			if (a[i][j] % 6 == 0 && ((i + j) % 5 != 0)) {
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
			Calc(a, rowCount, colCount, S, k, i, j + 1);
		}
		else {
			Calc(a, rowCount, colCount, S, k, i + 1, 0);
		}
	}
}
