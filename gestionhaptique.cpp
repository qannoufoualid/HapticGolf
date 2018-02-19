#include "gestionhaptique.h"
#include <QApplication>
#include "mainwindow.h"
#include <QDebug>

GestionHaptique::GestionHaptique(MainWindow *fen): mFenetre(fen)
{

    //Initialisation de la souris
    mSouris = new CImmMouse();


        // if (!mSouris->Initialize(qApp->applicationPid(),  fen->effectiveWinId()  ))
    if (!mSouris->Initialize(qWinAppInst(),  (HWND)mFenetre->effectiveWinId()  ))
    {qDebug()<<"===>Erreur chargement souris "<<mSouris;
        delete mSouris;
        mSouris = NULL;
        qApp->quit();
    }


    ////////////////////////////////////
    ////////////////////////////////////
    //Création d'effet par programme
    ////////////////////////////////////
    ////////////////////////////////////

        mProjet = new CImmProject();
        if (mProjet->OpenFile("C:/Users/M2IHM/Desktop/XYSpring.ifr", mSouris))
       {//le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
            qDebug()<<"Projet ifr charg�";
        }
        else
        {
            qDebug()<<"===>Erreur chargement projet IFR avec code "<<CIFCErrors::GetLastErrorCode() ;
        }
    }

    GestionHaptique::~GestionHaptique()
    {
        if (mProjet)
            delete mProjet;
        if (mSouris)
            delete mSouris;
    }

        CImmProject *GestionHaptique::GetProjet() const
        {
            return mProjet;
        }



