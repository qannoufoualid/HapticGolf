#ifndef GESTIONHAPTIQUE_H
#define GESTIONHAPTIQUE_H

//Compilation en mode non unicode
#undef UNICODE

#include <ifc.h>
#include <QPoint>
#include <QMainWindow>

class MainWindow;

class GestionHaptique
{
public:
    GestionHaptique(MainWindow *fen);
    ~GestionHaptique();


    CImmProject *GetProjet() const;

private:
    CImmMouse *mSouris;
    CImmProject  *mProjet;
    MainWindow *mFenetre;
};

#endif // GESTIONHAPTIQUE_H
