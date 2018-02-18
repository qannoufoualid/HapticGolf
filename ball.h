#ifndef BALL_H
#define BALL_H

#include "point.h"
#include "wall.h"


class Ball
{
public:
    Ball(Point p);
    ~Ball();

    void collideWith(Wall w);
    void strike(Point dir, double velocity);
    void updateVelocity();

private:
    Point m_pos;
    const double ACCELERATION = 0.9;
    Point m_direction;
    double m_velocity;
};

#endif // BALL_H
