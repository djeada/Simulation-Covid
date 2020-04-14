#ifndef SIMULATION_H
#define SIMULATION_H

#include <QVector>
#include <QPointF>
#include <QSizeF>
#include "person.h"

#define CLOSE_ENOUGH 1 //locations less than this distance are in danger
#define PERSON_SIZE 10

class Simulation
{
    public:
        Simulation(QVector<Person> p);
        QVector<Person> update(float time);

    private:
        QVector<Person> population;
        void checkTheBoundaries(Person &p);
        void checkContactWithOthers();
};

#endif
