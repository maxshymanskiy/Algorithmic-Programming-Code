#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);
const double PI = 4 * atan(1.0);

int main()
{
	double xp, xk, x, dx, eps, s = 0;
	int n = 0;


	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "arccos" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		s = S(x, eps, n, s);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(4) << acos(x) << " |"
			<< setw(10) << setprecision(4) << (PI / 2.0) - x - s << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;

	return 0;
}


double S(const double x, const double eps, int& n, double s) {

		n = 1;
		double a = (x * x * x) / 6;
		s = a;
		do {
			n++;
			a = A(x, n, a);
			s += a;
		} while (abs(a) >= eps);
		return s;
}

double A(const double x, const int n, double a) {

	double R = ((2.0 * n - 1) * (2.0 * n - 1)) / (2.0 * n * (2.0 * n + 1)) * (x * x);
	a *= R;
	return a;

}
		