// Lab_03_2.cpp
// <Шиманський Максим>
// Лабораторна робота № 3.2
// Розгалуження, задане формулою: функція з параметрами.
// Варіант 20
#include <iostream>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double a; // вхідний параметр
	double b; // вхідний параметр
	double c; // вхідний параметр
	double F; // результат обчислення виразу
	
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	cout << "x = "; cin >> x;

	// спосіб 1: розгалуження в скороченій формі
	
	if (x < 0 && b != 0)
		F = -(2 * x - c) / (c * x - a);
	if (x > 0 && b == 0)
		F = (x - a) / (x - c);
	if (!(x < 0 && b != 0) && !(x > 0 && b == 0))
		F = -x / c + (-c) / (2 * x );
	cout << endl;
	cout << "1) F = " << F << endl;
	
	
	// спосіб 2: розгалуження в повній формі
	
	if (x < 0 && b != 0)
		F = -(2 * x - c) / (b * x - a);
	else
		if (x > 0 && b == 0)
			F = (x - a) / (x - c);
		else
			F = -x / c + (-c) / (2 * x + 1);
	
	cout << "2) F = " << F << endl;
	
	cin.get();
	return 0;
}
