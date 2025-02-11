#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void Create(int* x, const int size, const int Low, const int High, int i)
{
	x[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(x, size, Low, High, i + 1);
}

void Print(int* x, const int size, int i)
{
	cout << setw(4) << x[i];
	if (i < size - 1)
		Print(x, size, i + 1);
	else
		cout << endl;
}

int CountElements(int* x, const int size, int i, int& count_element)
{
	if (i < size)
	{
		if (x[i] < 0 && !(x[i] % 3 == 0)) {
			count_element++;
		}
		return CountElements(x, size, i + 1, count_element);
	}
	return count_element;
}

int SumElements(int* x, const int size, int i)
{
	if (i < size)
	{
		if (x[i] < 0 && !(x[i] % 3 == 0))
		{
			return x[i] + SumElements(x, size, i + 1);
		}
		else
		{
			return SumElements(x, size, i + 1);
		}
	}
	return 0;
}

void ReplaceElements(int* x, const int size, int i)
{
	if (i < size)
	{
		if (x[i] < 0 && !(i % 3 == 0))
		{
			x[i] = 0;
		}
		ReplaceElements(x, size, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 24;
	int x[n];
	int Low = -17;
	int High = 53;
	int count_element = 0;
	Create(x, n, Low, High, 0);
	Print(x, n, 0);
	int sum = SumElements(x, n, count_element);
	cout << "S = " << sum << endl;
	CountElements(x, n, 0, count_element);
	cout << "Count of element = " << count_element << endl;
	ReplaceElements(x, n, 0);
	Print(x, n, 0);
	return 0;
}