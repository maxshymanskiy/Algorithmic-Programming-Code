#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count);
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount);
bool IsMaxInColN(int** a, const int n, const int k, const int colCount);
bool IsMinInRowK(int** a, const int n, const int k, const int rowCount);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);
    int count = 0;
    if (Part1_Count(a, rowCount, colCount, count))
        cout << "count NegativeNums = " << count << endl;
    else
        cout << "there are no zero elements" << endl;
    cout << endl;
    Part2_SaddlePoint(a, rowCount, colCount);
    cout << endl;
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count)
{
    bool result = false;
    count = 0;
    int k_zero;
    for (int i = 0; i < rowCount; i++)
    {
        k_zero = 0;
        for (int j = 0; j < colCount; j++)
            if (a[i][j] == 0)
            {
                result = true;
                k_zero++;
                break;
            }
        if (k_zero > 0)
        {
            for (int j = 0; j < colCount; j++)
                if (a[i][j] < 0)
                    count++;
        }
    }
    return result;
}
bool IsMinInRowK(int** a, const int n, const int k, const int rowCount)
{
    for (int i = 0; i < rowCount; i++)
        if (a[i][k] > a[n][k])
        {
            return false;
        }
    return true;
}
bool IsMaxInColN(int** a, const int n, const int k, const int colCount)
{
    for (int j = 0; j < colCount; j++)
        if (a[n][j] < a[n][k])
        {
            return false;
        }
    return true;
}
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount)
{
    cout << "Saddle points: min in row & max in col" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;
    for (int n = 0; n < rowCount; n++)
        for (int k = 0; k < colCount; k++)
            if (IsMaxInColN(a, n, k, colCount) && IsMinInRowK(a, n, k, rowCount))
            {
                cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
            }
}