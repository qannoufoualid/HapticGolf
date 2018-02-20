#ifndef GESTIONHAPTIQUE_H
#define GESTIONHAPTIQUE_H

//Compilation en mode non unicode
#undef UNICODE

#include <ifc.h>
#include <QPoint>
#include <QMainWindow>

class MainWindow;

/**
 * @brief Permet de gérer les effets de l'haptique.
 */
class GestionHaptique
{
public:
    /**
     * @brief Constructeur avec la fenêtre principal du jeu.
     * @param fenêtre du jeu.
     */
    GestionHaptique(MainWindow *fen);
    ~GestionHaptique();

    /**
     * @brief Getter du projet haptique
     * @return
     */
    CImmProject *GetProjet() const;

    /**
     * @brief Getter de l'effet haptique
     * @return
     */
    CImmSpring* getRessort() const;


private:
    /**
     * @brief Souris haptique
     */
    CImmMouse *mSouris;
    /**
     * @brief Projet haptique
     */
    CImmProject  *mProjet;

    /**
     * @brief Fenêtre principal
     */
    MainWindow *mFenetre;

    /**
     * @brief Effet ressort.
     */
    CImmSpring* mRessort;
};

#endif // GESTIONHAPTIQUE_H
