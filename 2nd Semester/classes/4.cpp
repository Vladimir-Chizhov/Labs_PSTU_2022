#include <iostream>

class Pair {
protected:
    int first;
    int second;

public:
    Pair(int first = 0, int second = 0) {
        this->first = first;
        this->second = second;
    }

    void setFirst(int first) {
        this->first = first;
    }

    void setSecond(int second) {
        this->second = second;
    }

    int getFirst() const {
        return first;
    }

    int getSecond() const {
        return second;
    }

    Pair operator+(const Pair& other) const {
        int sumFirst = first + other.first;
        int sumSecond = second + other.second;
        return Pair(sumFirst, sumSecond);
    }
};

class LongNumber : public Pair {
private:
    int highPart;

public:
    LongNumber(int highPart = 0, int lowPart = 0) : Pair(highPart, lowPart) {
        this->highPart = highPart;
        this->second = lowPart;
    }

    void setHighPart(int highPart) {
        this->highPart = highPart;
    }

    int getHighPart() const {
        return highPart;
    }

    LongNumber operator+(const LongNumber& other) const {
        int sumHighPart = highPart + other.highPart;
        int sumLowPart = second + other.second;

        if (sumLowPart >= 100) {
            sumHighPart += sumLowPart / 100;
            sumLowPart %= 100;
        }

        return LongNumber(sumHighPart, sumLowPart);
    }

    LongNumber operator-(const LongNumber& other) const {
        int diffHighPart = highPart - other.highPart;
        int diffLowPart = second - other.second;

        if (diffLowPart < 0) {
            diffHighPart -= 1;
            diffLowPart += 100;
        }

        return LongNumber(diffHighPart, diffLowPart);
    }

    LongNumber operator*(const LongNumber& other) const {
        int productHighPart = highPart * other.highPart;
        int productLowPart = second * other.second;

        if (productLowPart >= 100) {
            productHighPart += productLowPart / 100;
            productLowPart %= 100;
        }

        return LongNumber(productHighPart, productLowPart);
    }
};

int main() {
    Pair pair1(2, 3);
    Pair pair2(4, 5);
    Pair sumPair = pair1 + pair2;

    std::cout << "Сумма пары чисел: (" << sumPair.getFirst() << ", " << sumPair.getSecond() << ")" << std::endl;

    LongNumber longNum1(12, 34);
    LongNumber longNum2(56, 78);
    LongNumber sumLongNum = longNum1 + longNum2;
    LongNumber diffLongNum = longNum1 - longNum2;
    LongNumber productLongNum = longNum1 * longNum2;

    std::cout << "Сумма длинного числа: (" << sumLongNum.getHighPart() << ", " << sumLongNum.getSecond() << ")" << std::endl;
    std::cout << "Разность длинного числа: (" << diffLongNum.getHighPart() << ", " << diffLongNum.getSecond() << ")" << std::endl;
    std::cout << "Произведение длинного числа: (" << productLongNum.getHighPart() << ", " << productLongNum.getSecond() << ")" << std::endl;

    return 0;
}
