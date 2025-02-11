#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;
}

int Max(int* a, const int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

template <typename T>
void CreateT(T* a, const int size, const T Low, const T High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void PrintT(T* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;
}

template <typename T>
T MaxT(T* a, const int size)
{
	T max = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int main()
{
	srand((unsigned)time(NULL)); 

	const int n = 10;
	int a[n];
	int Low = -10;
	int High = 34;
	
	Create(a, n, Low, High);
	
	Print(a, n);
	cout << "max = " << Max(a, n) << endl;
	CreateT(a, n, Low, High);

	PrintT(a, n);
	cout << "max = " << MaxT(a, n) << endl;
	return 0;
}