#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

#include <QTimer>

namespace Ui {
class mainwidget;
}

class mother : public QGraphicsPixmapItem{
public:
    mother(int sceneHeight);

    // QGraphicsItem interface
public:
    void advance(int phase);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    int xspeed = 0;
};

class Bug : public QGraphicsPixmapItem {
public:
    Bug(int xspread);

    // QGraphicsItem interface
public:
    void advance(int phase);
private:
    int yspeed = 2;
};

class mainwidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = nullptr);
    ~mainwidget();
private slots:
    void onGenerate();
private:
    Ui::mainwidget *ui;
    QGraphicsScene* scene;
    QTimer* animationTimer;
    QTimer* generatorTimer;
};

#endif // MAINWIDGET_H
