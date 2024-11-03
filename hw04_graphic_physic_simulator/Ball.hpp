#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(const Point& center, const Velocity& velocity, Color color, double radius, bool isCollidable):
          center_(center),
          velocity_(velocity),
          color_(color),
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
    Color color_;
    double radius_;
    bool isCollidable_;
};
