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

        mRessort = new CImmSpring();
        if (!mRessort->Initialize(mSouris,
                                  10000,
                                  10000,
                                  1,
                                  IMM_EFFECT_AXIS_BOTH,
                                  IMM_EFFECT_MOUSE_POS_AT_START,
                                  IMM_EFFECT_DEFAULT_DIRECTION_X,
                                  IMM_EFFECT_DEFAULT_DIRECTION_Y,
                                  false));

            mProjet = new CImmProject();
            if (mProjet->OpenFile("C:/Users/M2IHM/Desktop/Immersion.ifr", mSouris))
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

            CImmSpring *GestionHaptique::getRessort() const
            {
                return mRessort;
            }



