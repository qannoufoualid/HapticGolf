#ifndef BALL_H
#define BALL_H

#include "point.h"
#include "wall.h"
#include "course.h"


class Ball
{
public:
    Ball(Point p);
    ~Ball();

    void collideWith(Wall w);
    void collideWith(Point hole);
    void strike(Point dir, double velocity);
    void updateVelocity();
    void checkCollisions(Course course);

private:
    Point m_pos;
    const double ACCELERATION = 0.9;
    Point m_direction;
    double m_velocity;
};

#endif // BALL_H
