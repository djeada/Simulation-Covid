#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>

#include "person.h"

class board : public QObject{
    Q_OBJECT
public:
    board(QGraphicsScene* s);
private:
    QColor chooseColor(Person p);
};

#endif // BOARD_H
