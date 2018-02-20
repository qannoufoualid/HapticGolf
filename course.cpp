#include "course.h"


 static const int TROU_RAYON=30;

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

void Course::setPlayerWon(bool won){
    this->playerWon = won;
}

bool Course::isPlayerWon(){
    return this->playerWon;
}
