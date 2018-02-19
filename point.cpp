#include "Point.h"

Point::Point()
{
    m_posX = 0;
    m_posY = 0;
}

Point::Point(double fX, double fY)
{
    m_posX = fX;
    m_posY = fY;
}

Point::~Point()
{

}



double Point::getX()
{
    return m_posX;
}

double Point::getY()
{
    return m_posY;
}

void Point::updateX(double newX)
{
    m_posX = newX;
}

void Point::updateY(double newY)
{
    m_posY = newY;
}

void Point::updatePos(double newX, double newY)
{
    m_posX = newX;
    m_posY = newY;
}

