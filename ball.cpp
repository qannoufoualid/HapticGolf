#include "ball.h"

Ball::Ball(Point p) :
    m_pos(p),
    m_direction(0),
    m_velocity(0)
{

}

Ball::~Ball()
{

}

void Ball::collideWith(Wall w)
{

}

void Ball::strike(double dir, double velocity)
{
    m_direction = dir;
    m_velocity = velocity;
}

void Ball::updateVelocity()
{
    m_velocity *= ACCELERATION;
}

