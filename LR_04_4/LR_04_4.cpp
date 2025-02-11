// Lab_04_4.cpp
// <Шиманський Максим >
// Лабораторна робота № 4.4
// Розгалуження, задане графіком функції.
// Варіант 20

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	double x, xp, xk, dx, R, y;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "R = "; cin >> R;

	cout << fixed;
	cout << "--------------------" << endl;
	cout << "|" << setw(7) << "x   " << "|"
		<< setw(10) << "y    " << "|" << endl;
	cout << "--------------------" << endl;

	x = xp;

	while (x <= xk) {
		if (x <= 0)
			y = -x / 2.;
		else
			if (0 < x && x <= R)
				y = R - sqrt(pow(R, 2) - pow(R, 2));
			else
				if (R < x && x <= 2 * R)
					y = sqrt(pow(R, 2) - pow((x - R), 2));
				else
					y = -(x - 2 * R) / (6 - 2 * R);


		cout << "|" << setw(7) << setprecision(2) << x
			<< "|" << setw(10) << setprecision(3) << y
			<< "|" << endl;
		x += dx;
	}

	cout << "--------------------" << endl;
	cin.get();
	return 0;
}