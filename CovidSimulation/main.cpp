#include "mainwindow.h"
#include "gui.h"
#include "simulation.h"
#include "initial_conditions.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>

#define COUNTRY "Germany"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    //get initial conditions for the simulation
    Initial_conditions my_initial_conditions(COUNTRY);

    //create the scene for the graphics
    QGraphicsScene *scene = new  QGraphicsScene();

    //create a view to visualize the scene
    QGraphicsView  *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(SCENE_WIDTH,SCENE_HEIGHT);
    scene->setSceneRect(0,0,SCENE_WIDTH,SCENE_HEIGHT);
    scene->setBackgroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));

    QTimer timer;

    QVector<Person> population = populate(my_initial_conditions);

    Statistics* current_stats = new Statistics(my_initial_conditions.getNumCases(),
                             my_initial_conditions.getNumDeaths(),
                             my_initial_conditions.getPopulation() - my_initial_conditions.getNumCases() - my_initial_conditions.getNumDeaths());

    Simulation simulation(population, current_stats);
    QTimer::connect(&timer, &QTimer::timeout,
          [&]()
          {
            scene->clear();
            population = simulation.update();

            for(auto& p : population){
                auto position = p.getLocation();
                QColor color = p.chooseColor();
                scene->addRect(position->getCorX()-(PERSON_SIZE/2), position->getCorY()-(PERSON_SIZE/2),
                               PERSON_SIZE, PERSON_SIZE, { color }, { color });
            }
            scene->update();
            if(current_stats->getNum_vulnerable() == 0){
                timer.stop();
            }
        }
    );

    timer.start(50);

    return a.exec();
}

