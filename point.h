#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double fX, double fY);
    ~Point();
    double getX();
    double getY();
    void updateX(double newX);
    void updateY(double newY);
    void updatePos(double newX, double newY);

private:
    double m_posX;
    double m_posY;
};

#endif // POINT_H
