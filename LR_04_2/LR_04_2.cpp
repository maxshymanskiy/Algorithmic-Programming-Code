// LR_4.2.cpp
// < Шиманський Максим>
// Лабораторна робота № 4.2
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 20


#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	double x, xp, xk, dx, A, B, y;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;

	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "y" << " |" << endl;
	cout << "----------------------" << endl;

	x = xp;

	while (x <= xk)
	{
		A = tan(x) + 1;
		if (x <= -5)
			B = exp(x / abs(1 - x));
		else
			if (-5 < x && x <= 3)
				B = 3.2 + log10(1.8 * x * x);
			else
				B = abs(x) * sqrt(x);

		y = A - B;
		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;
		x += dx;

	}
	cout << "----------------------" << endl;

	cin.get();
	return 0;
}
