#ifndef WALL_H
#define WALL_H
#include "point.h"
#include "walltype.h"

/**
 * @brief Classe  qui encapsule l'entité Mur.
 */
class Wall
{
public:
    /**
     * @brief Créer un mur avec un point de depart, point d'arrivé et un type de mur.
     * @param firstPt point de depart
     * @param secondPt point d'arrivé
     * @param wallType le type du mur.
     */
    Wall(Point firstPt, Point secondPt, WallType wallType);
    ~Wall();

    /**
     * @brief Getter du point de depart
     * @return point de depart
     */
    Point getFirstPoint();
    /**
     * @brief getter du point d'arrivé
     * @return  point d'arrivé
     */
    Point getSecondPoint();
    /**
     * @brief Getter du type de mur.
     * @return type de mur
     */
    WallType getWallType();

private:
    /**
     * @brief Position de depart
     */
    Point m_firstPt;
    /**
     * @brief position d'arrivé
     */
    Point m_secondPt;

    /**
     * @brief Type de mur.
     */
    WallType m_wallType;
};

#endif // WALL_H
