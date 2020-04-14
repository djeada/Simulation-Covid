#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 100
#define FONT_SIZE 35

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    Button(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
    void setText(QString name);
    void drawButton();
};

#endif // BUTTON_H
