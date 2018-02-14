#include "point.h"

point::point()
{
    m_posX = 0;
    m_posY = 0;
}

point::point(double fX, double fY)
{
    m_posX = fX;
    m_posY = fY;
}

double point::getX()
{
    return m_posX;
}

double point::getY()
{
    return m_posY;
}

void point::updateX(double newX)
{
    m_posX = newX;
}

void point::updateY(double newY)
{
    m_posY = newY;
}

void point::updatePos(double newX, double newY)
{
    m_posX = newX;
    m_posY = newY;
}
