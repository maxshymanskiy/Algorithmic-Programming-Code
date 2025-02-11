#include <iostream>
#include <fstream>

using namespace std;

void CreateBin(char* fname)
{
	ofstream fout(fname, ios::binary);
	char ch;
	int num;

	do {
		cout << "Enter number: ";
		cin >> num;
		fout.write((char*)&num, sizeof(num));

		cout << "Continue? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	fout.close();
}
void PrintBin(char* fname)
{
	ifstream fin(fname, ios::binary);
	int num;
	
	cout << "File content (" << fname << "):" << endl;
	while (fin.read((char*)&num, sizeof(num))) {
		cout << num << " ";
	}
	cout << endl;

	fin.close();
}
void ProcessBin(char* fname, char* gname)
{
	ifstream fin(fname, ios::binary);
	ofstream fout(gname, ios::binary);

	int num, sum = 0;

	while (fin.read((char*)&num, sizeof(num))) {
		sum += num;
		fout.write((char*)&sum, sizeof(sum));
	}
	fin.close();
	fout.close();
}
int main() {
	char fname[100];
	char gname[100];

	cout << "Enter file name 1: ";
	cin >> fname;
	CreateBin(fname);
	PrintBin(fname);

	cout << "Enter file name 2: ";
	cin >> gname;
	ProcessBin(fname, gname);

	PrintBin(gname);
	
	return 0;
}