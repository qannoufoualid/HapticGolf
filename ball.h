#ifndef BALL_H
#define BALL_H

#include <QDebug>
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
    void updateMovement();
    void checkCollisions(Course course);

    Point getPos();

private:
    Point m_pos;
    const double ACCELERATION = 0.99;
    Point m_direction;
    double m_velocity;
};

#endif // BALL_H
