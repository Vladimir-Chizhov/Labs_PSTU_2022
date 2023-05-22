#include <iostream>

class LinearEquation {
private:
    double A;
    double B;

public:
    LinearEquation(double coefficientA, double coefficientB) {
        A = coefficientA;
        B = coefficientB;
    }

    double root() {
        if (A == 0) {
            std::cout << "Коэффициент A не может быть равен нулю." << std::endl;
            return 0.0;
        }

        return -B / A;
    }
};

int main() {
    double coefficientA, coefficientB;

    std::cout << "Введите коэффициенты A и B: ";
    std::cin >> coefficientA >> coefficientB;

    LinearEquation equation(coefficientA, coefficientB);
    double root = equation.root();

    std::cout << "Корень линейного уравнения y = Ax + B: " << root << std::endl;

    return 0;
}
