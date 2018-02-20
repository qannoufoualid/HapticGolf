#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <vector>
#include <QPoint>

#include "ball.h"
#include "course.h"
#include "wall.h"
#include "gestionhaptique.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief La fenêtre principal.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief Fonction qui gere l'evenement d'appuie.
     * @param e event d'appuie
     */
    void mousePressEvent(QMouseEvent *e);
    /**
     * @brief Fonction qui gere l'evenement release.
     * @param e event de release
     */
    void mouseReleaseEvent(QMouseEvent *e);
    /**
     * @brief paintEvent
     * @param event
     */
    void paintEvent(QPaintEvent *event);

    /**
     * @brief Getter du gestionnaire d'haptique.
     * @return le gestionnaire d'haptique.
     */
    GestionHaptique *getGestion_haptique() const;

    /**
     * @brief Setter du gestionnaire d'haptique.
     * @param value
     */
    void setGestion_haptique(GestionHaptique *value);

public slots:
    /**
     * @brief Mettre à jour les elements de la fenetre
     */
    void update();

private:
    /**
     * @brief Gestionnaire d'haptique
     */
    GestionHaptique * gestion_haptique;

    /**
     * @brief Premier point cliqué
     */
    QPoint	mDebut;
    /**
     * @brief 2éme point cliqué
     */
    Qpoint mFin;
    /**
     * @brief Mettre à jour la balle
     */
    void updateBall();

    /**
     * @brief Dessiner la course
     */
    void redrawCourse();

    /**
     * @brief Timer pour executer la fonction update
     */
    QTimer m_timer;

    /**
     * @brief ui du mainwindow
     */
    Ui::MainWindow *ui;
    /**
     * @brief La zone de dessin
     */
    QPixmap* m_zoneDessin;

    /**
     * @brief La course
     */
    Course* m_course;
    /**
     * @brief La balle.
     */
    Ball* m_ball;
};

#endif // MAINWINDOW_H
