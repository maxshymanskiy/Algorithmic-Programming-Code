#include <iomanip>
#include <iostream>
#include <time.h>


using namespace std;

void Create(int* x, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		x[i] = Low + rand() % (High - Low + 1);
}
void Print(int* x, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << x[i];
	cout << endl;
}
int CountElements(int* x, const int size)
{
	int count_element = 0;
	for (int i = 0; i < size; i++)
		if (x[i] < 0 && !(x[i] % 3 == 0))
			count_element++;
	return count_element;
}
int Sum(int* x, const int size, int& count_element)
{
	int S = 0;
	count_element = 0;
	for (int i = 0; i < size; i++)
		if (x[i] < 0 && !(x[i] % 3 == 0)) {
			S += x[i];
			count_element++;
			x[i] = 0;
		}
	return S;
}
void ReplaceElements(int* x, const int size)
{
	for (int i = 0; i < size; i++)
		if (x[i] < 0 && !(x[i] % 3 == 0))
			x[i] = 0;
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 24;
	int x[n];
	int Low = -17;
	int High = 53;
	Create(x, n, Low, High);
	Print(x, n);
	int count_element = CountElements(x, n);
	int sum = Sum(x, n, count_element);
	ReplaceElements(x, n);
	cout << "S = " << sum << endl;
	cout << "Count of element = " << count_element << endl;
	Print(x, n);
	return 0;
}