#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* ballLabel = new QLabel("balle");
    ballLabel->setPixmap(QPixmap(QString(":/images/ball")));
    ui->verticalLayout->addWidget(ballLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
