#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	long long P, S;
	int k, i;

	i = 5;
	S = 0;

	while (i <= 25)
	{
		P = 1;
		k = 1;
		while (k <= i * i)
		{
			P *= k;
			k++;
		}
		S += (sqrt((i * i) + P)) / i;
		i+=5;
	}
	cout << S << endl;

	i = 5;
	S = 0;
	do {
		P = 1;
		k = 1;
		do {
			P *= k;
			k++;
		} while (k <= i * i);
		S += (sqrt((i * i) + P)) / i;
		i+=5;
	} while (i <= 25);
	cout << S << endl;

	S = 0;
	for (i = 5; i <= 25; i+=5)
	{
		P = 1;
		for (k = 1; k <= i * i; k++)
		{
			P *= k;
		}
		S += (sqrt((i * i) + P)) / i;
	}
	cout << S << endl;

	S = 0;
	for (i = 25; i >= 5; i-=5)
	{
		P = 1;
		for (k = i * i; k >= 1; k--)
		{
			P *= k;
		}
		S += (sqrt((i * i) + P)) / i;
	}
	cout << S << endl;

	return 0;
}
