#include "ball.h"

Ball::Ball(Point p) :
    m_pos(p),
    m_direction(Point(0, 0)),
    m_velocity(0)
{

}

Ball::~Ball()
{

}

void Ball::collideWith(Wall w)
{
    if (w.isVertical()) {
        m_direction = Point(-m_direction.getX(), m_direction.getY());
    } else {
        m_direction = Point(m_direction.getX(), -m_direction.getY());
    }
}

void Ball::collideWith(Point hole)
{
    //Win
}

void Ball::strike(Point dir, double velocity)
{
    m_direction = dir;
    m_velocity = velocity;
}

void Ball::updateVelocity()
{
    m_velocity *= ACCELERATION;
}

void Ball::checkCollisions(Course course)
{
    if (m_pos.getX() <= (course.getHole().getX() + 10) || m_pos.getY() <= (course.getHole().getY() + 10)){
        collideWith(course.getHole());
    } else {
        for (int i = 0; i <= course.getWalls().size(); i++) {
            if (course.getWalls()[i].isVertical() || m_pos.getY() == course.getWalls()[i].getFirstPoint().getY()) {
                collideWith(course.getWalls()[i]);
            } else if (!course.getWalls()[i].isVertical() || m_pos.getX() == course.getWalls()[i].getFirstPoint().getX()) {
                collideWith(course.getWalls()[i]);
            }
        }
    }
}

