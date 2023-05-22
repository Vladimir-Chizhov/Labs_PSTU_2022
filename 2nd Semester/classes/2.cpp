#include <iostream>
#include <string>

class Country {
private:
    std::string capital;
    int population;
    double area;

public:
    Country(const std::string& capital, int population, double area) {
        this->capital = capital;
        this->population = population;
        this->area = area;
    }

    void setCapital(const std::string& capital) {
        this->capital = capital;
    }

    void setPopulation(int population) {
        this->population = population;
    }

    void setArea(double area) {
        this->area = area;
    }

    std::string getCapital() const {
        return capital;
    }

    int getPopulation() const {
        return population;
    }

    double getArea() const {
        return area;
    }
};

int main() {
    std::string capital;
    int population;
    double area;

    std::cout << "Введите столицу страны: ";
    std::getline(std::cin, capital);

    std::cout << "Введите количество жителей: ";
    std::cin >> population;

    std::cout << "Введите площадь страны: ";
    std::cin >> area;

    Country country(capital, population, area);

    std::cout << "Страна: " << country.getCapital() << std::endl;
    std::cout << "Количество жителей: " << country.getPopulation() << std::endl;
    std::cout << "Площадь: " << country.getArea() << std::endl;

    return 0;
}
