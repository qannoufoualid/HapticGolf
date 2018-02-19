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
    static Point inverse(Point p, Point origin){
        return Point(origin.getX()+(origin.getX()- p.getX()), origin.getY()+(origin.getY()- p.getY()));
    }

private:
    double m_posX;
    double m_posY;
};

#endif // POINT_H
