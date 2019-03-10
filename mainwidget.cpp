#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>

#define CIRCLE_SIZE 50
#define MOTHER_SPEED 15

mainwidget::mainwidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 1732, 937, this);
    scene->setStickyFocus(true);
    scene->setBackgroundBrush(QPixmap(":/images/fon.png"));
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

    scene->addItem(new mother(scene->height()));

    animationTimer = new QTimer(this);
    connect(animationTimer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    animationTimer->start(1000/60);

    generatorTimer = new QTimer(this);
    connect(generatorTimer, SIGNAL(timeout()),
            this, SLOT(onGenerate()));
    generatorTimer->start(1000);

}

mainwidget::~mainwidget()
{
    delete ui;
}

void mainwidget::onGenerate()
{
    scene->addItem(new Bug(scene->sceneRect().width()));
}

Bug::Bug(int xspread): QGraphicsPixmapItem (nullptr){
    setPixmap(QPixmap(":/images/1.png"));
    setPos(rand()%(xspread - pixmap().width()), 0);
}

void Bug::advance(int phase){
    if (phase){
    moveBy(0, yspeed);
    }
}

mother::mother(int sceneHeight) : QGraphicsPixmapItem (nullptr){
    setPixmap(QPixmap(":/images/22.png"));
    setPos(0, sceneHeight-pixmap().height());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void mother::advance(int phase){
    if(phase){
        moveBy(xspeed, 0);
    }
}

void mother::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left:
        xspeed = - MOTHER_SPEED;
        break;
    case Qt::Key_Right:
        xspeed = MOTHER_SPEED;
        break;
    default:
        break;
    }
}

void mother::keyReleaseEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left:
        xspeed = 0;
        break;
    case Qt::Key_Right:
        xspeed = 0;
        break;
    default:
        break;
    }
}
