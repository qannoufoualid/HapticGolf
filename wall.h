#ifndef WALL_H
#define WALL_H
#include "point.h"

class Wall
{
public:
    Wall(Point firstPt, Point secondPt);
    ~Wall();

    Point getFirstPoint();
    Point getSecondPoint();

private:
    Point m_firstPt;
    Point m_secondPt;
};

#endif // WALL_H
