#include "board.h"
#include "simulation.h"
#include "simulator.h"
#include <QTimer>
#include <QDebug>

board::board(QGraphicsScene* scene) {
    QVector<Person> population;

    for(int i = 0; i < 100; ++i)
        population.append({true,INFECTED});

    Simulation simulation(population);
    QTimer timer;
    QTimer::connect(&timer, &QTimer::timeout,
          [&]()
          {

            scene->clear();
            population = simulation.update(1);

            for(auto& p : population){
                auto position = p.getLocation();
                //QColor color = chooseColor(p);
                QColor color = Qt::green;
                scene->addRect(position.getX()-(PERSON_SIZE/2), position.getY()-(PERSON_SIZE/2),
                               PERSON_SIZE, PERSON_SIZE, { color }, { color });
            }
            scene->update();
        }
    );

     timer.start(50);
}

QColor chooseColor(Person p){
    if(p.getDiseaseStatus() == VULNERABLE)
        return Qt::green;
    if(p.getDiseaseStatus() == INFECTED)
        return Qt::red;
    return Qt::black;
}

