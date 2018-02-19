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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);


    GestionHaptique *getGestion_haptique() const;

    void setGestion_haptique(GestionHaptique *value);

public slots:
    void update();

private:
    GestionHaptique * gestion_haptique;
    QPoint	mDebut, mFin;
    void updateBall();
    void redrawCourse();

    QTimer m_timer;

    Ui::MainWindow *ui;
    QPixmap* m_zoneDessin;

    Course* m_course;
    Ball* m_ball;
};

#endif // MAINWINDOW_H
