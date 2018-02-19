#ifndef WALL_H
#define WALL_H
#include "point.h"
#include "walltype.h"

class Wall
{
public:
    Wall(Point firstPt, Point secondPt, WallType wallType);
    ~Wall();

    Point getFirstPoint();
    Point getSecondPoint();
    WallType getWallType();

private:
    Point m_firstPt;
    Point m_secondPt;

    WallType m_wallType;
};

#endif // WALL_H
