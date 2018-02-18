#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ClickableLabel* ballLabel = new ClickableLabel();
    ballLabel->setPixmap(QPixmap(QString(":/images/ball")).scaled(30,30,Qt::KeepAspectRatio));
    ui->verticalLayout->addWidget(ballLabel);

    connect(ballLabel, SIGNAL(clicked()), this, SLOT(clickBall()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickBall()
{
    qInfo() << "Click balle";
}
