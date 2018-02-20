#ifndef BALL_H
#define BALL_H

#include <QDebug>
#include "point.h"
#include "wall.h"
#include "course.h"

/**
 * @brief Classe qui encapsule l'entité Ball.
 */
class Ball
{
public:
    /**
     * @brief Pour construire une balle dans une position donnée.
     * @param p
     */
    Ball(Point p);
    ~Ball();

    /**
     * @brief fonction qui permet de verifier est ce que la balle est en collision un mur.
     * @param wall Le mur avec lequel on vérifier est ce que la balle est en collision.
     * @return true si collision, false sinon
     */
    bool collideWith(Wall wall);

    /**
     * @brief Fonction qui permet de tirer la balle vers une direction avec une velocité.
     * @param dir point de direction.
     * @param velocity vitesse de tir
     */
    void strike(Point dir, double velocity);

    /**
     * @brief Fonction qui permet de changer la position de la balle en diminuant la vitesse.
     */
    void updateMovement();

    /**
     * @brief Fonction qui permet de gérer les collisions avec les murs d'une course.
     * @param course la course du jeu.
     */
    bool checkCollisions(Course course);

    /**
     * @brief Getter de la position de la balle.
     * @return Point de la position.
     */
    Point getPos();

    /**
     * @brief Fonction qui permet de changer la direction de la balle.
     * @param isVertical permet d'indiquer le type du mur (true si vertical, false sinon).
     */
    void changeDirection(bool isVertical);

    /**
     * @brief Fonction qui permet de vérifier si la balle est dans le trou.
     * @param hole le trou du jeu.
     * @param diameter le diametre du trou.
     * @return true si dans le trou, false sinon.
     */
    bool checkIfInHole(Point hole, double diameter);

    /**
     * @brief Getter de la velocité.
     * @return la velocité
     */
    double getVelocity();

    /**
     * @brief Permet de savoir si la balle s'est arrêtée.
     * @return true si la balle s'est arrêtée, false sinon.
     */
    bool isStopped();

    /**
     * @brief Rayon de la balle
     */
    static const int RAYON;

private:
    /**
     * @brief Position du centre de la balle.
     */
    Point m_pos;

    /**
     * @brief Constante de l'accéleration.
     */
    const double ACCELERATION = 0.99;

    /**
     * @brief Direction du mouvement de la balle.
     */
    Point m_direction;

    /**
     * @brief Velocit de la balle.
     */
    double m_velocity;
};

#endif // BALL_H
