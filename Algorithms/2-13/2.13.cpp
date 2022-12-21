#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    float a, b, c, D, x1, x2, x;

    cout << "Ââåäèòå çíà÷åíèÿ äëÿ a,b,c " << endl;
    cin >> a >> b >> c;

    D = pow(b, 2) - 4 * a * c;

    if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "x1=" << x1 << endl;
        cout << "x2=" << x2 << endl;
    }
    else if (D == 0)
    {
        x = (-b) / (2 * a);
        cout << "x=" << x << endl;
    }
    else
    {
        cout << "Êîðíåé íåò" << endl;
    }

    return 0;
}
