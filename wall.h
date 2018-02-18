#ifndef WALL_H
#define WALL_H
#include "point.h"

class Wall
{
public:
    Wall(Point firstPt, Point secondPt, bool vertical);
    ~Wall();

    Point getFirstPoint();
    Point getSecondPoint();

    bool isVertical();

private:
    Point m_firstPt;
    Point m_secondPt;

    bool m_vertical;
};

#endif // WALL_H
