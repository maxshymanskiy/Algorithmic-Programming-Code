// Lab_02.1.cpp
// ���������� ������
// ����������� ������ � 2.1.
// ˳����� ��������.
// ������ 20

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double m; // ������� ��������
	double n; // ������� ��������
	double z1; // ��������� ���������� 1-�� ������
	double z2; // ��������� ���������� 2-�� ������
	
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;
	
	//z1 = ((m - 1) * sqrt(m) - (n - 1) * sqrt(n)) / (sqrt(pow(m, 3) * n) + (n * m) + pow(m, 2) - m);
	 z2 = (sqrt(m) - sqrt(n)) / m;
	
	cout << endl;
	//cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	
	cin.get();
	cin.get();

	return 0;

}

