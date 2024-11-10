#include "Ball.hpp"
#include <cmath>

void Ball::setVelocity(const Velocity& velocity) {
    velocity_ = velocity;
}

Velocity Ball::getVelocity() const {
    return velocity_;
}

void Ball::draw(Painter& painter) const {
    painter.draw(center_, radius_, Color(red_, green_, blue_));
}

void Ball::setCenter(const Point& center) {
    center_ = center;
}

Point Ball::getCenter() const {
    return center_;
}

double Ball::getRadius() const {
    return radius_;
}

double Ball::getMass() const {
    return 4.0 / 3.0 * M_PI * std::pow(radius_, 3);
}

bool Ball::isCollidable() const {
    return isCollidable_;
}