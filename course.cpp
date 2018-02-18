#include "course.h"

Course::Course(Point tee, Point hole, std::vector<Wall> walls) :
    m_teePos(tee),
    m_holePos(hole),
    m_walls(walls)
{

}

Course::~Course()
{

}

Point Course::getTee()
{
    return m_teePos;
}

Point Course::getHole()
{
    return m_holePos;
}

std::vector<Wall> Course::getWalls()
{
    return m_walls;
}
