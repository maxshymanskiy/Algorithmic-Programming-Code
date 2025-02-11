#include <iostream>
using namespace std;


double a_n(int n, int level, int& depth) {
    if (level > depth)
        depth = level;

    cout << "Current recursion level: " << level << endl;


    if (n == 1)
        return 1.0;


    double previos = a_n(n - 1, level + 1, depth);
    return (1.0 / 3) * (2 * previos + 8.0 / previos);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int depth = 0;
    double result = a_n(n, 1, depth);

    cout << "The result a_" << n << " = " << result << endl;
    cout << "The depth of recursion was: " << depth << endl;

    return 0;
}
