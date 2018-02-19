#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <vector>

#include "ball.h"
#include "course.h"
#include "wall.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

public slots:

    void update();

private:

    void updateBall();
    void redrawCourse();

    QTimer m_timer;

    Ui::MainWindow *ui;
    QPixmap* m_zoneDessin;

    Course* m_course;
    Ball* m_ball;
};

#endif // MAINWINDOW_H
