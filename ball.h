#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball(double posX, double posY);
    ~Ball();

    void collideWith(Wall w);
    void strike(double dir, double speed);
    void updateVelocity();

private:
    const double ACCELERATION = 0.8;
    double m_posX;
    double m_posY;
    double m_direction;
    double m_velocity;
};

#endif // BALL_H
