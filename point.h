#ifndef POINT_H
#define POINT_H

/**
 * @brief Classe qui encapsule l'entité Point.
 */
class Point
{
public:
    /**
     * @brief Constructeur par default.
     */
    Point();
    /**
     * @brief Construire un point des coordonnés x et y.
     * @param fX coordonnée x.
     * @param fY coordonnée y.
     */
    Point(double fX, double fY);
    ~Point();
    /**
     * @brief Getter de x
     * @return
     */
    double getX();
    /**
     * @brief getter de y
     * @return y.
     */
    double getY();
    /**
     * @brief permet de mettre à jour x
     * @param newX le nouveau x
     */
    void updateX(double newX);
    /**
     * @brief permet de mettre à jour y
     * @param newY le nouveau y
     */
    void updateY(double newY);
    /**
     * @brief Permet de mettre à jour x et y.
     * @param newX le nouveau x
     * @param newY le nouveau y
     */
    void updatePos(double newX, double newY);

    /**
     * @brief Permet de calculer la distance qui sépare le point courant vers un autre point.
     * @param p l'autre point.
     * @return la distance
     */
    double distanceTo(Point p);

private:
    /**
     * @brief coordonnée x
     */
    double m_posX;
    /**
     * @brief coordonnée y
     */
    double m_posY;
};

#endif // POINT_H
