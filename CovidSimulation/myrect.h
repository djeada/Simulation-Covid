#ifndef MYRECT_H
#define MYRECT_H
#include "person.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>

//consants
#define WIDTH 10
#define HEIGHT 10

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
    //QGraphicsScene *scene;
    Person* myPerson;
public:
    MyRect(QGraphicsScene *s, Person *p);
    void updateLocations();
    void checkTheBoundaries();
public slots:
    void move();
};

#endif // MYRECT_H
