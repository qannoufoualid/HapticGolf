#ifndef POINT_H
#define POINT_H


class point
{
public:
    point();
    point(double fX, double fY);
    ~point();
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
