#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include "point.h"
#include "wall.h"

/**
 * @brief Classe qui encapsule l'entité Course.
 */
class Course
{
public:
    /**
     * @brief Construire une course avec un tee, un trou et des murs.
     * @param tee le tee
     * @param hole le trou
     * @param walls un vecteur des murs.
     */
    Course(Point tee, Point hole, std::vector<Wall> walls);
    ~Course();

    /**
     * @brief Getter de tee.
     * @return le centre du tee.
     */
    Point getTee();

    /**
     * @brief Getter du trou.
     * @return Le centre du trou.
     */
    Point getHole();

    /**
     * @brief Getter du vecteur des murs.
     * @return vecteur des murs.
     */
    std::vector<Wall> getWalls();

    /**
     * @brief Setter de playerWon.
     * @param won true si le joueur à mis la balle dans le trou.
     */
    void setPlayerWon(bool won);
    /**
     * @brief Getter de playerWon.
     * @return true si le joueur à mis la balle dans le trou.
     */
    bool isPlayerWon();
private:
    /**
     * @brief Position du centre du tee.
     */
    Point m_teePos;
    /**
     * @brief Position du centre du hole.
     */
    Point m_holePos;

    /**
     * @brief Vecteur des murs.
     */
    std::vector<Wall> m_walls;

    /**
     * @brief true si le joueur a gagné, false sinon.
     */
    bool playerWon = false;
};

#endif // COURSE_H
