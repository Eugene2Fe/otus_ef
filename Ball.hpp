#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(const Point& center, const Velocity& velocity,
         uint8_t red, uint8_t green, uint8_t blue,
         double radius, bool isCollidable)
        : center_(center),
          velocity_(velocity),
          red_(red),
          green_(green),
          blue_(blue),
          radius_(radius),
          isCollidable_(isCollidable)     {}

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

private:
    Point center_;
    Velocity velocity_;
    int red_, green_, blue_;
    double radius_;
    bool isCollidable_;
};
