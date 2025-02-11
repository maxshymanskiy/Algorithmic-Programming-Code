#include <iostream>
#include <cmath>

using namespace std;

double h(const double x, const double y);

int main() {

	double p, q;

	cout << "p = "; cin >> p;
	cout << "q = "; cin >> q;

	double c = pow(h(abs(p - q), sqrt(abs(p - q))), 2) + h(1, (q * q) - (p * p));
	cout << "c = " << c << endl;
	return 0;

}

double h(const double x, const double y) {

	/*if ((x * x) < (y * y)) {
		cout << "Negative" << endl;
		return 0;
	}*/
	return (y * y - sqrt((x * x) + (y * y))) / (1 + x * x * y * y);
}