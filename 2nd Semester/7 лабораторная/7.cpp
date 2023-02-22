#include <iostream>
#include <complex>

using namespace std;

double multiply(double a, double b)
{
    return a * b;
}

complex<double> multiply(complex<double> a, complex<double> b)
{
    return a * b;
}

int main()
{
    double a = 2.5;
    double b = 3.7;
    cout << "Результат умножения вещественных чисел: " << multiply(a, b) << endl;

    complex<double> c(1.0, 2.0);
    complex<double> d(3.0, 4.0);
    cout << "Результат умножения комплексных чисел: " << multiply(c, d) << endl;

    return 0;
}
