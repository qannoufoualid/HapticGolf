#include "wall.h"


Wall::Wall(Point firstPt, Point secondPt) :
    m_firstPt(firstPt),
    m_secondPt(secondPt)
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
