#include "ball.h"

Ball::Ball(double posX, double posY) :
    m_posX(posX),
    m_posY(posY),
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

