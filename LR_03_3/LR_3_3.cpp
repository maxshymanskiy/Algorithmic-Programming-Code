// Lab_03_3.cpp
// <Шиманський Максим >
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 20

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу
	
	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;

	// розгалуження в повній формі
		if (x <= 0)
			y = -x / 2.;
		else
			if (0 < x && x <= R)
				y = R - sqrt( pow(R, 2) - pow(R, 2));
			else
				if (R < x && x <= 2 * R)
					y = sqrt(pow(R, 2) - pow((x - R), 2));
				else
					y = -(x - 2 * R) / (6 - 2 * R);
	cout << endl;
	cout << "y = " << y << endl;

	cin.get();
	return 0;
}