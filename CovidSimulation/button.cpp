#include "button.h"
#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>

Button::Button(QString name, QGraphicsItem *parent)
    : QGraphicsRectItem(parent) {
  // draw the main field (rect)
  drawButton();

  // draw the text
  setText(name);

  // allow responding to hover events
  setAcceptHoverEvents(true);
}

void Button::drawButton() {
  setRect(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::darkCyan);
  setBrush(brush);
}

void Button::setText(QString name) {
  text = new QGraphicsTextItem(name, this);
  QFont titleFont("roboto", FONT_SIZE);
  text->setFont(titleFont);
  int xPos = rect().width() / 2 - text->boundingRect().width() / 2;
  int yPos = rect().height() / 2 - text->boundingRect().height() / 2;
  text->setPos(xPos, yPos);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
  // change color to cyan
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::cyan);
  setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
  // change color to dark cyan
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::darkCyan);
  setBrush(brush);
}
