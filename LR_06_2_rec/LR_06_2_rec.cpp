#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;


void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

double avgSum(const int* arr, const int size, int i, double s, int count)
{
	if (i == size) {
		if (count == 0) {
			cerr << "Error: No even numbers in the array." << endl;
			return 0;
		}
		return s / count;
	}
	if (arr[i] % 2 == 0) {
		s += i;
		count++;
	}
	return avgSum(arr, size, i + 1, s, count);
}

void Print(const int* arr, const int size, int i)
{
	if (i < size) {
		cout << setw(4) << arr[i];
		Print(arr, size, i + 1);
	}
	else {
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int size = 16;
	int Low = 1;
	int High = 100;
	int* arr = new int[size];

	Create(arr, size, Low, High, 0);

	cout << "arr[" << size << "] = ";

	Print(arr, size, 0);

	double s = 0;
	int count = 0;
	double sum = avgSum(arr, size, 0, s, count);
	cout << "avgSum: " << fixed << setprecision(2) << sum << endl;

	delete[] arr;

	return 0;
}