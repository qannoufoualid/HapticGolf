#include "wall.h"


Wall::Wall(Point firstPt, Point secondPt, WallType type) :
    m_firstPt(firstPt),
    m_secondPt(secondPt),
    m_wallType(type)
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

WallType Wall::getWallType()
{
    return m_wallType;
}
