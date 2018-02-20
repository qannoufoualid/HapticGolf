#include "ball.h"

static const int RAYON = 15;

Ball::Ball(Point p) :
    m_pos(p),
    m_direction(Point(0, 0)),
    m_velocity(0)
{

}

Ball::~Ball()
{

}

bool Ball::collideWith(Wall wall)
{
    switch(wall.getWallType()){
        case TOP :
            if(getPos().getY() < wall.getFirstPoint().getY()){
                return true;
            }
        break;
        case BOTTOM :
            if(getPos().getY() > wall.getFirstPoint().getY()){
                return true;
            }
        break;
        case RIGHT :
            if(getPos().getX() > wall.getFirstPoint().getX()){
                return true;
            }
        break;
        case LEFT :
            if(getPos().getX() < wall.getFirstPoint().getX()){
                return true;
            }
        break;

    }

    return false;
}

void Ball::strike(Point dir, double velocity)
{
    m_direction = dir;
    m_velocity = velocity;
}

void Ball::updateMovement()
{
    m_velocity *= ACCELERATION;
    if(m_velocity < 5e-3) m_velocity = 0;
    m_pos.updatePos(m_pos.getX() + (m_direction.getX() * m_velocity), m_pos.getY() + (m_direction.getY() * m_velocity));
}

bool Ball::checkCollisions(Course course)
{
        for (int i = 0; i < course.getWalls().size(); i++) {
            if (collideWith(course.getWalls()[i]) && (course.getWalls()[i].getWallType() == TOP || course.getWalls()[i].getWallType() == BOTTOM ) ) {
                changeDirection(false);
                return true;
            } else if (collideWith(course.getWalls()[i]) && (course.getWalls()[i].getWallType() == LEFT || course.getWalls()[i].getWallType() == RIGHT ) ) {
                changeDirection(true);
                return true;
            }
        }
        return false;
}


void Ball::changeDirection(bool isVertical){
    if(!isVertical)
        m_direction = Point(m_direction.getX(), -m_direction.getY());
    else
        m_direction = Point(-m_direction.getX(), m_direction.getY());
}

bool Ball::checkIfInHole(Point hole, double diameter){
    if(getPos().distanceTo(hole) + 15 < diameter){
        return true;
    }
    return false;
}

double Ball::getVelocity(){
    return m_velocity;
}

Point Ball::getPos()
{
    return m_pos;
}

bool Ball::isStopped(){
    return m_velocity == 0;
}

