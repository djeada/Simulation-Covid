#include "myrect.h"
#include <QTimer>

QColor chooseColor(Person *p);
MyRect::MyRect(QGraphicsScene *s, Person *p){
    myPerson = p;
    setBrush(chooseColor(p));
    setRect(p->getLocation().getX(),p->getLocation().getY(),WIDTH,HEIGHT);
    //add the item to the scene
    s->addItem(this);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void MyRect::move(){
    setPos(this->x()+myPerson->getLocation().getVX(),this->y()+myPerson->getLocation().getVY());
    updateLocations();
    checkTheBoundaries();
}

void MyRect::updateLocations(){
    myPerson->getLocation().setX(this->scenePos().x());
    myPerson->getLocation().setY(this->scenePos().y());
}

void MyRect::checkTheBoundaries(){
    if(this->scenePos().y() < 10){
        //qInfo() << sceneTransform().map(QPointF(0, 0)).y();
        myPerson->getLocation().toggleVY();
    }
    if (this->scenePos().x() < 10){
        myPerson->getLocation().toggleVX();
    }
    if (this->scenePos().x() > SCENE_WIDTH + 20){
       myPerson->getLocation().toggleVX();
    }
    if (this->scenePos().y() > SCENE_HEIGHT + 20){
       myPerson->getLocation().toggleVY();
    }
}

QColor chooseColor(Person *p){
    if(p->getDiseaseStatus() == VULNERABLE)
        return Qt::green;
    if(p->getDiseaseStatus() == INFECTED)
        return Qt::red;
    return Qt::black;
}

