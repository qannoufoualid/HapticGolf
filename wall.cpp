#include "wall.h"


Wall::Wall(Point firstPt, Point secondPt, bool vertical) :
    m_firstPt(firstPt),
    m_secondPt(secondPt),
    m_vertical(vertical)
{

}

Wall::~Wall()
{

}

Point Wall::getFirstPoint()
{
    return m_firstPt;
}

Point Wall::getSecondPoint()
{
    return m_secondPt;
}

bool Wall::isVertical()
{
    return m_vertical;
}
