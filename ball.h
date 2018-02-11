#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball(double posX, double posY);
    ~Ball();

    void collideWith(Wall w);
    void strike(double dir, double speed);
    void updateSpeed();

private:
    double m_posX;
    double m_posY;
    double m_direction;
    double m_speed;
};

#endif // BALL_H
