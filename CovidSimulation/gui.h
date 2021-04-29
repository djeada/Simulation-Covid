#ifndef GUI_H
#define GUI_H

/* This class is a template for opening window gui.
  Project title, buttons and their events are set here.
*/

#include "button.h"
#include <QGraphicsScene>
#include <QGraphicsView>

#define TITLE_FONT_SIZE 50
#define TITLE "Covid19 Simulation"

class Gui : public QGraphicsView {
  Q_OBJECT
public:
  Gui();
  QGraphicsScene *scene;
public slots:
  void start();
  void openSimulation();
  QGraphicsScene *getScene();
  bool isReady();

public:
signals:
  bool signal_a();

private:
  Button *createButton(QString name, int byPos);
  void createTitleText();
  bool flag = false;
};

#endif // GUI_H
