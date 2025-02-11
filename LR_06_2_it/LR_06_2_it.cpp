#include <iostream>
#include <iomanip>

using namespace std;


void genArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
}

 double avgSum(const int arr[], const int n) 
{
	double s = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
		 s += i;
		 count++;
		}
	}
	if (count == 0) return count = 0;

	return s / count;
}

void Print(const int arr[], const int size)
{
	for (int i = 0; i < size; i++) {
		cout << setw(4) << arr[i];
	}
	cout << endl;
}

int main() 
{
	int size;

	cout << "Size arr[i] = "; cin >> size;
	int* arr = new int[size];
	genArray(arr, size);

	cout << "arr[" << size << "] = ";
	Print(arr, size);

	double sum = avgSum(arr, size);
	cout << "avgSum: " << fixed << setprecision(2) << sum << endl;

	delete[] arr;
	return 0;
}