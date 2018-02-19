#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup modèle
    std::vector<Wall> walls = {
        Wall(Point(10,10), Point(500,10), TOP),
        Wall(Point(10,10), Point(10,500), LEFT),
        Wall(Point(500,10), Point(500,500), RIGHT),
        Wall(Point(10,500), Point(500,500), BOTTOM)
    };
    this->m_course = new Course(Point(50,50), Point(250,250), walls);
    this->m_ball = new Ball(m_course->getTee());
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
    m_ball->checkCollisions(*m_course);
    qInfo() << m_ball->getVelocity();
    if(m_ball->isStopped() && m_ball->checkIfInHole(m_course->getHole(), 30)){
        m_course->setPlayerWon(true);
    }else{
        m_course->setPlayerWon(false);
    }

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
    p.drawEllipse(QPoint(m_course->getHole().getX(), m_course->getHole().getY()), 30, 30);


    if(m_course->isPlayerWon()){

        QFont font;
        font.setPixelSize(40);

        p.setFont(font);

        p.setPen(Qt::black);
        p.setBrush(Qt::black);
        p.drawText(QPoint(80, 80), "You Won");
    }


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

