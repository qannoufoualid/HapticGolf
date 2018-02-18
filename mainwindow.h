#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
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

public slots:

    void clickBall();

private:
    Ui::MainWindow *ui;
    Course* m_course;
    Ball* m_ball;
};

#endif // MAINWINDOW_H
