#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include "point.h"
#include "wall.h"

class Course
{
public:
    Course(Point tee, Point hole, std::vector<Wall> walls);
    ~Course();

    Point getTee();
    Point getHole();
    std::vector<Wall> getWalls();

private:
    Point m_teePos;
    Point m_holePos;
    std::vector<Wall> m_walls;
};

#endif // COURSE_H
