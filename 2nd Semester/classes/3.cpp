#include <iostream>

class Money {
private:
    long rubles;
    int kopeks;

public:
    Money(long rubles = 0, int kopeks = 0) {
        this->rubles = rubles;
        this->kopeks = kopeks;
    }

    void setRubles(long rubles) {
        this->rubles = rubles;
    }

    void setKopeks(int kopeks) {
        this->kopeks = kopeks;
    }

    long getRubles() const {
        return rubles;
    }

    int getKopeks() const {
        return kopeks;
    }

    void display() const {
        std::cout << rubles << "," << kopeks;
    }

    Money operator+(const Money& other) const {
        long totalRubles = rubles + other.rubles;
        int totalKopeks = kopeks + other.kopeks;

        if (totalKopeks >= 100) {
            totalRubles += totalKopeks / 100;
            totalKopeks %= 100;
        }

        return Money(totalRubles, totalKopeks);
    }

    Money operator-(const Money& other) const {
        long totalRubles = rubles - other.rubles;
        int totalKopeks = kopeks - other.kopeks;

        if (totalKopeks < 0) {
            totalRubles -= 1;
            totalKopeks += 100;
        }

        return Money(totalRubles, totalKopeks);
    }
};

int main() {
    Money money1(10, 50);
    Money money2(5, 30);

    Money sum = money1 + money2;
    Money difference = money1 - money2;

    std::cout << "Сумма: ";
    sum.display();
    std::cout << std::endl;

    std::cout << "Разность: ";
    difference.display();
    std::cout << std::endl;

    return 0;
}
