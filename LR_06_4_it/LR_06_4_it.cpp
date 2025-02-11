#include <iomanip>
#include <iostream>

using namespace std;

void Input(double* arr, const int size) 
{
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
	cout << endl;
}

double MultipOfPositiveElements(double* arr, int n)
{
	double p = 1;
	int positiveCount = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			p *= arr[i];
			positiveCount++;
		}
	}
	return (positiveCount > 0) ? p : 0;
	/*if (positiveCount > 0) {
		return p;
	}
	else {
		return 0;
	}*/
}


double SumBeforeMinElement(double* arr, int n)
{
	if (n == 0) return 0;

	int minIndex = 0;
	double minElement = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] < minElement) {
			minElement = arr[i];
			minIndex = i;
		}
	}

	double sum = 0;
	for (int i = 0; i < minIndex; i++) {
		sum += arr[i];
	}
	return sum;
}

void SortEvenOddPositions(double* arr, int n)
{
	for (int i = 0; i < n - 2; i += 2) {                //  Even
		for (int j = 0; j < n - i - 2; j += 2) {
			if (arr[j] > arr[j + 2]) {

				double tmp = arr[j];
				arr[j] = arr[j + 2];
				arr[j + 2] = tmp;
			}
		}
	}

	for (int i = 1; i < n - 2; i += 2) {                //  Odd 
		for (int j = 1; j < n - i - 2; j += 2) {
			if (arr[j] > arr[j + 2]) {

				double tmp = arr[j];
				arr[j] = arr[j + 2];
				arr[j + 2] = tmp;
			}
		}
	}
}
void printArray(double* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n;
	cout << "Enter the number of array elements: ";
	cin >> n;

	double* arr = new double[n];

	Input(arr, n);

	double positiveMultip = MultipOfPositiveElements(arr, n);
	cout << "The multiplication: " << positiveMultip << endl;

	cout << "В array: ";
	printArray(arr, n);

	double sum = SumBeforeMinElement(arr, n);
	cout << "The sum of the elements: " << sum << endl;

	SortEvenOddPositions(arr, n);

	cout << "Converted array: ";
	printArray(arr, n);

	delete[] arr;

	return 0;
}