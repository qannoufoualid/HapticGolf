#include "ball.h"

Ball::Ball(Point p) :
    m_pos(p),
    m_direction(Point(0, 0)),
    m_velocity(0)
{

}

Ball::~Ball()
{

}

void Ball::collideWith(Wall w)
{

}

void Ball::strike(Point dir, double velocity)
{
    m_direction = dir;
    m_velocity = velocity;
}

void Ball::updateVelocity()
{
    m_velocity *= ACCELERATION;
}

