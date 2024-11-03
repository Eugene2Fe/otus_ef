#pragma once
#include "Point.hpp"
#include <cmath>
#include <iostream>

class Velocity {
  public:
    inline Velocity() = default;

    // TODO: комментарии
    inline Velocity(double abs, double angle) {
        const double x = std::cos(angle);
        const double y = std::sin(angle);
        vec = Point{x, y} * abs;
    }


    // Перегружаем оператор ввода
    friend std::istream& operator>>(std::istream& stream, Velocity& velocity) {
        return stream >> velocity.vx >> velocity.vy;

    inline Velocity(const Point& vector) {
        setVector(vector);
    }

    inline void setVector(const Point& vector) {
        vec = vector;
    }

    inline Point vector() const {
        return vec;
    }

  private:
    Point vec;
};
