#ifndef COURSE_H
#define COURSE_H
#include <vector>


class Course
{
public:
    Course(double teePosX, double teePosY, double holePosX, double holePosY, std::vector<Wall> walls);
    ~Course();

    double* getTee();
    double* getHole();
    std::vector<Wall> getWalls();

private:
    double m_teePosX;
    double m_teePosY;
    double m_holePosX;
    double m_holePosY;
    std::vector<Wall> m_walls;
};

#endif // COURSE_H
