#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

int main() {
    double x, y;
    double x_min = -1, x_max = 5;
    double y_min = -3, y_max = 5;

    // Випадкових чисел
    srand((unsigned)time(NULL));

    // Введення координат користувача
    for (int i = 0; i < 10; i++) {
        cout << "x: "; cin >> x;
        cout << "y: "; cin >> y;

        // Перевірка попадання у заштриховану область
        if ((y >= pow((x - 2), 2) - 3 && y >= 0 && y <= x) ||
            (y >= pow((x - 2), 2) - 3 && y <= -x)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    cout << endl << fixed;

    // Генерація 10 випадкових пострілів
    for (int i = 0; i < 10; i++) {
        // Генерація випадкових координат (x, y)
        x = x_min + rand() / (RAND_MAX / (x_max - x_min));
        y = y_min + rand() / (RAND_MAX / (y_max - y_min));

        // Виведення координат
        cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << " ";

        // Перевірка попадання у заштриховану область
        if ((y >= pow((x - 2), 2) - 3 && y >= 0 && y <= x) ||
            (y >= pow((x - 2), 2) - 3 && y <= -x)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
