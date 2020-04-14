#ifndef GUI_H
#define GUI_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "button.h"

#define TITLE_FONT_SIZE 50
#define TITLE "Covid19 Simulation"

class gui: public QGraphicsView{
    Q_OBJECT
public:
    gui();
    QGraphicsScene* scene;
public slots:
    void start();
    void openSimulation();
private:
    Button* createButton(QString name, int byPos);
    void createTitleText();
};

#endif // GUI_H
