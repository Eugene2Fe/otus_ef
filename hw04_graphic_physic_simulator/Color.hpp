#pragma once
#include "iostream"

class Color {
  public:
    Color() : r(0), g(0), b(0) {}
    Color(double red, double green, double blue) : r(red), g(green), b(blue) {};
    // Перегружаем оператор ввода
    friend std::istream& operator>>(std::istream& stream, Color& color) {
        return stream >> color.r >> color.g >> color.b;
    }


  private:
    double r{};
    double g{};
    double b{};
};
