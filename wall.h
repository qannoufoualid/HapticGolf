#ifndef WALL_H
#define WALL_H


class Wall
{
public:
    Wall(double firstPtX, double firstPtY, double secondPtX, double secondPtY);
    ~Wall();

    double* getFirstPoint();
    double* getSecondPoint();

private:
    double m_firstPtX;
    double m_firstPtY;
    double m_secondPtX;
    double m_secondPtY;
};

#endif // WALL_H
