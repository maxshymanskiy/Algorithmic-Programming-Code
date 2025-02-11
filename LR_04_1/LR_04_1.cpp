// LR_4_1.cpp
// < Шиманський Максим>
// Лабораторна робота № 4.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 20

#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int k, N, i;
	double S;
	cout << "k = "; cin >> k;
	cout << "N = "; cin >> N;
	
	S = 0;
	i = k;
	while (i <= N)
	{
		S += (sin(i) * cos(i)) / (1 + pow(cos(i), 2));
		i++;
	}
	cout << S << endl;

	S = 0;
	i = k;
	do 
	{
		S += (sin(i) * cos(i)) / (1 + pow(cos(i), 2));
		i++;
	} while (i <= N);
	cout << S << endl;
	S = 0;
	for (i = k; i <= N; i++)
	{
		S += (sin(i) * cos(i)) / (1 + pow(cos(i), 2));
	}
	cout << S << endl;
	S = 0;
	for (i = N; i >= k; i--)
	{
		S += (sin(i) * cos(i)) / (1 + pow(cos(i), 2));
	}
	cout << S << endl;
	return 0;
}