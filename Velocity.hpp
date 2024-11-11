#pragma once
#include "Point.hpp"
#include <cmath>
#include <iostream>

class Velocity {
    private:
        Point vec;
    public:
        inline Velocity() {
            std::cout << "Default constructor called" << std::endl;
        }

        inline Velocity(double abs, double angle) {
            std::cout << "Constructor with abs and angle called" << std::endl;
            const double x = std::cos(angle);
            const double y = std::sin(angle);
            vec = Point{x, y} * abs;
        }

        inline Velocity(const Point& vector) {
            std::cout << "Constructor with Point vector called" << std::endl;
            setVector(vector);
        }

        inline void setVector(const Point& vector) {
            vec = vector;
        }

        inline Point vector() const {
            return vec;
        }
};
