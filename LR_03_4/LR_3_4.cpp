// Lab_03_4.cpp
// < �������, ��� ������ >
// ����������� ������ � 3.4
// ������������, ������ ������� �������.
// ������ 20
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double x; // ������� ��������
	double y; // ������� ��������
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	// ������������ � ����� ����
	if ((y >= pow((x-2), 2) - 3 && y >= 0 && y <= x) ||
		(y >= pow((x - 2), 2) - 3 && y <= -x))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cin.get();
	return 0;
}