#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup modèle
    std::vector<Wall> walls = {
        Wall(Point(10,10), Point(500,10), false),
        Wall(Point(10,10), Point(10,500), true),
        Wall(Point(500,10), Point(500,500), false),
        Wall(Point(10,500), Point(500,500), true)
    };
    this->m_course = new Course(Point(50,50), Point(250,250), walls);
    this->m_ball = new Ball(m_course->getTee());
    this->m_ball->strike(Point(1,1), 1);
    // A LIBERER

    gestion_haptique = new GestionHaptique(this);

    ui->setupUi(this);

    this->m_zoneDessin = new QPixmap(this->size());
    this->m_zoneDessin->fill();

    m_timer.setInterval(0);
    m_timer.start();

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, *this->m_zoneDessin);
}


void MainWindow::update()
{
    updateBall();
    qApp->processEvents(QEventLoop::AllEvents);
}

void MainWindow::setGestion_haptique(GestionHaptique *value)
{
    gestion_haptique = value;
}

GestionHaptique *MainWindow::getGestion_haptique() const
{
    return gestion_haptique;
}

void MainWindow::updateBall()
{
    this->m_ball->updateMovement();
    redrawCourse();
    repaint();
}

void MainWindow::redrawCourse()
{
    this->m_zoneDessin->fill(Qt::white);
    QPainter p(this->m_zoneDessin);

    p.setPen(Qt::gray);
    p.setBrush(Qt::gray);
    p.drawEllipse(QPoint(m_ball->getPos().getX(), m_ball->getPos().getY()), 15, 15);
    p.setBrush(Qt::NoBrush);

    p.setPen(Qt::red);
    for (int i = 0; i < m_course->getWalls().size(); i++) {
        Wall w = m_course->getWalls()[i];
        p.drawLine(QPoint(w.getFirstPoint().getX(), w.getFirstPoint().getY()), QPoint(w.getSecondPoint().getX(), w.getSecondPoint().getY()));
    }

    p.setBrush(Qt::black);
    p.setPen(Qt::black);
    p.drawEllipse(QPoint(m_course->getHole().getX(), m_course->getHole().getY()), 15, 15);

    p.setPen(Qt::NoPen);
    p.setBrush(Qt::NoBrush);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{

    if (e->buttons() == Qt::LeftButton)
    {
        gestion_haptique->getRessort()->Start();
        mDebut = e->pos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
        mFin = e->pos();
        Point result = Point(mFin.x() - mDebut.x(), mFin.y() - mDebut.y());
        double norme = std::sqrt(result.getX()*result.getX()+ result.getY()*result.getY());
        Point inverse = Point(-result.getX(), -result.getY());

        double denominator = std::abs(inverse.getX());
        if(std::abs(inverse.getX()) < std::abs(inverse.getY())){
            denominator = std::abs(inverse.getY());
        }

        if(denominator != 0)
         inverse = Point(inverse.getX()/denominator, inverse.getY()/denominator);
        else
         inverse = Point(0, 0);

        m_ball->strike(inverse, norme * 0.1);
        gestion_haptique->getRessort()->Stop();

}

