#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup modèle
    std::vector<Wall> walls = {
        Wall(Point(10,10), Point(50,10), false)
    };
    m_course = new Course(Point(0,0), Point(100,100), walls);
    m_ball = new Ball(m_course->getTee());
    // A LIBERER

    ui->setupUi(this);

    ClickableLabel* ballLabel = new ClickableLabel(this);
    ballLabel->setPixmap(QPixmap(QString(":/images/ball")).scaled(30,30,Qt::KeepAspectRatio));
    ballLabel->setGeometry(150,150,ballLabel->height(),ballLabel->width());
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
