#include <cmath>
#include <stdexcept>

#include "simulation.h"
#include "person.h"

#include <ctime>
#include <utility>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>
#include <QDebug>

Simulation::Simulation(QVector<Person> p){
    population = p;
}

QVector<Person> Simulation::update(float time) {
    for(auto& p : population){
        int x = p.getLocation().getX() + time*p.getLocation().getVX();
        int y = p.getLocation().getY() + time*p.getLocation().getVY();
        p.getLocation().setX(x);
        p.getLocation().setY(y);
        checkTheBoundaries(p);
    }
    checkContactWithOthers();
    return population;
}

void Simulation::checkTheBoundaries(Person &p){
    if(p.getLocation().getX() - (PERSON_SIZE/2) < 0 && p.getLocation().getVX() < 0)
        p.getLocation().toggleVX();

    else if(p.getLocation().getX() + (PERSON_SIZE/2) >= SCENE_WIDTH && p.getLocation().getVX() > 0)
        p.getLocation().toggleVX();

    if(p.getLocation().getY() - (PERSON_SIZE/2) < 0 && p.getLocation().getVY() < 0)
        p.getLocation().toggleVY();

    else if(p.getLocation().getY() + (PERSON_SIZE/2) >= SCENE_HEIGHT && p.getLocation().getVY() > 0)
        p.getLocation().toggleVY();
}

void Simulation::checkContactWithOthers(){
    for(int i = 0; i < population.size()-1; ++i)
        for(int j = i+1; j < population.size(); ++j)
            if(population[i].get_distance(population[j]) < CLOSE_ENOUGH)
                population[i].try_infect(population[j]);
}
