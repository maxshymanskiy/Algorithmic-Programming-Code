#include <algorithm> 
#include <iomanip>
#include <iostream>

using namespace std;

void Input(double* arr, const int size, int i = 0)
{
	if (i < size) {
		cout << "a[" << i << "] = ";
		cin >> arr[i];
		Input(arr, size, i + 1);
	}
	else {
		cout << endl;
		return;
	}
}

double MultipOfPositiveElementsHelper(const double* arr, int n, int& positiveCount)
{
	if (n <= 0)
		return 1.0;

	double product = MultipOfPositiveElementsHelper(arr, n - 1, positiveCount);

	if (arr[n - 1] > 0) {
		positiveCount++;
		return product * arr[n - 1];
	}
	else
		return product;
}

double MultipOfPositiveElements(const double* arr, int n)
{
	int positiveCount = 0;
	double product = MultipOfPositiveElementsHelper(arr, n, positiveCount);
	return (positiveCount > 0) ? product : 0.0;
}

int FindMinIndex(double* arr, int index, int size, int currentMinIndex)
{
	if (index >= size)
		return currentMinIndex;
	if (arr[index] < arr[currentMinIndex])
		return FindMinIndex(arr, index + 1, size, index);
	else
		return FindMinIndex(arr, index + 1, size, currentMinIndex);
}

double SumBeforeMinElement(double* arr, int minIndex, int currentIndex)
{
	if (currentIndex >= minIndex)
		return 0;
	else
		return arr[currentIndex] + SumBeforeMinElement(arr, minIndex, currentIndex + 1);
}

void sortEvenPositionsInner(double* arr, int n, int i, int j) // парні
{
	if (j >= n - i - 2)
		return;

	if (arr[j] > arr[j + 2]) {
		swap(arr[j], arr[j + 2]);
	}

	sortEvenPositionsInner(arr, n, i, j + 2);
}

void sortEvenPositions(double* arr, int n, int i = 0)
{
	if (i >= n - 2)
		return;

	sortEvenPositionsInner(arr, n, i, 0);

	sortEvenPositions(arr, n, i + 2);
}

void sortOddPositionsInner(double* arr, int n, int i, int j)  //непарні
{
	if (j >= n - i - 2)
		return;

	if (arr[j] > arr[j + 2]) {
		swap(arr[j], arr[j + 2]);
	}

	sortOddPositionsInner(arr, n, i, j + 2);
}

void sortOddPositions(double* arr, int n, int i = 1)
{
	if (i >= n - 2)
		return;

	sortOddPositionsInner(arr, n, i, 1);
	sortOddPositions(arr, n, i + 2);
}

void printArray(double* arr, const int n, int i)
{
	cout << arr[i] << " ";
	if (i < n - 1)
		printArray(arr, n, i + 1);
	else
		cout << endl;
}

int main()
{
	int n;
	cout << "Enter the number of array elements: ";
	cin >> n;

	if (n <= 0) {
		cout << "Number of elements must be positive." << endl;
		return 1;
	}

	double* arr = new double[n];

	Input(arr, n);

	double positiveMultip = MultipOfPositiveElements(arr, n);
	cout << "The multiplication: " << positiveMultip << endl;

	int minIndex = FindMinIndex(arr, 0, n, 0);

	double sum = SumBeforeMinElement(arr, minIndex, 0);
	cout << "The sum of the elements: " << sum << endl;

	sortEvenPositions(arr, n);
	sortOddPositions(arr, n);

	cout << "Converted array: ";
	printArray(arr, n, 0);

	delete[] arr;

	return 0;
}
