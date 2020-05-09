#ifndef SIMULATION_H
#define SIMULATION_H

/* One person is not enough.
 * We want to create many people and
 * simulate interactions between them.
 * To make the simulation more realistic we take
 * into consideration a lot of parameters.
*/

#include "person.h"

#include <QVector>
#include <QPointF>
#include <bits/stdc++.h>
#include <QGraphicsScene>

//how long will healthy people live
#define INFINITY INT_MAX

//general simulation parameters
#define NUM_PEOPLE 300
#define PERCENT_OF_QUARANTINE 0.5
#define HOSPITAL_CAPACITY 0.05
#define PERCENT_OF_COOPERATIVE 0.7

//likelihood of infection when exposed
#define INFECTION_PROBABILITY 0.8

//disease dynamics
#define NORMAL_FR 0.01 //you can still get help
#define SATURATED_FR 0.2
#define INFECTION_TIME 1000 //how many iterations infection lasts

//how many sick people at a time can
//the health system handle before collapsing.
#define SATURATION_TRESHOLD (NUM_PEOPLE / 20)

class Simulation
{
    public:
        Simulation(QVector<Person> p, Statistics* s);
        QVector<Person> update();

    private:
        QVector<Person> population;
        void checkTheBoundaries(Person p);
        void checkContactWithOthers();
        Statistics* current_stats;
};

//roll a ruged dice, returns true if the event occured
//false otherwise
bool didItHappen(float probability);

//returns a random integer picked from a range <start, end>
int randomInRange(int start, int end);

//returns -1 or 1, similiar to a dice roll
int headOrTail();


#endif
