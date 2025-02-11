#include <iomanip>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Max(int* a, const int size, int i, int max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}
template <typename T>
void CreateT(T* a, const int size, const T Low, const T High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		CreateT(a, size, Low, High, i + 1);
}

template <typename T>
void PrintT(T* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		PrintT(a, size, i + 1);
	else
		cout << endl;
}

template <typename T>
T MaxT(T* a, const int size, int i, T max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return MaxT(a, size, i + 1, max);
	else
		return max;
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 5;
	int a[n];
	int Low = -10;
	int High = 34;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "max = " << Max(a, n, 1, a[0]) << endl;

	CreateT(a, n, Low, High, 0);
	PrintT(a, n, 0);
	cout << "max = " << MaxT(a, n, 1, a[0]) << endl;
	return 0;
}
