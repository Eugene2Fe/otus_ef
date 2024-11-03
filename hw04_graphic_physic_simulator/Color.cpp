#include "Color.hpp"
#include "iostream"

Color::Color() = default;

Color::Color(double red, double green, double blue)
    : r{red}, g{green}, b{blue} {}

    // Перегружаем оператор ввода
    friend std::istream& operator>>(std::istream& stream, Color& color) {
        return stream >> color.red >> color.green >> color.blue; }

double Color::red() const {
    return r;
}

double Color::green() const {
    return g;
}

double Color::blue() const {
    return b;
}
