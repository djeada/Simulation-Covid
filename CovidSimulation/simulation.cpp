#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <random>

#include "simulation.h"

Simulation::Simulation(QVector<Person> p, Statistics* s){
    population = p;
    current_stats = s;
}

QVector<Person> Simulation::update() {
    for(auto& p : population){
        p.progress_diesease(current_stats);
        if(p.will_move()){
            p.shouldGoHome();
            float x = p.getLocation()->getCorX() + p.getLocation()->getCorVX();
            float y = p.getLocation()->getCorY() + p.getLocation()->getCorVY();
            p.getLocation()->setCorX(x);
            p.getLocation()->setCorY(y);
            checkTheBoundaries(p);
        }
    }
    checkContactWithOthers();

    return population;
}

void Simulation::checkTheBoundaries(Person p){
    if(p.getLocation()->getCorX() - (PERSON_SIZE/2) < 0 && p.getLocation()->getCorVX() < 0){
        p.getLocation()->toggleVX();
        p.getLocation()->randomizeVelocity();
    }
    else if(p.getLocation()->getCorX() + PERSON_SIZE >= SCENE_WIDTH && p.getLocation()->getCorVX() > 0){
        p.getLocation()->toggleVX();
        p.getLocation()->randomizeVelocity();
    }
    if(p.getLocation()->getCorY() - (PERSON_SIZE/2) < 0 && p.getLocation()->getCorVY() < 0){
        p.getLocation()->toggleVY();
        p.getLocation()->randomizeVelocity();
    }

    else if(p.getLocation()->getCorY() + PERSON_SIZE >= SCENE_HEIGHT && p.getLocation()->getCorVY() > 0){
        p.getLocation()->toggleVY();
        p.getLocation()->randomizeVelocity();
    }
}

void Simulation::checkContactWithOthers(){
    for(int i = 0; i < population.size()-1; ++i)
        for(int j = i+1; j < population.size(); ++j)
            if(population[i].get_distance_to_person(population[j]) < CLOSE_ENOUGH)
                population[i].try_infect(population[j], current_stats);
}

int randomInRange(int start, int end){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dist(start,end);
    return dist(*QRandomGenerator::global());
}

int headOrTail(){
    if(randomInRange(-10001, 10000) >= 1){
        return 1;
    }
    return -1;
}

//true if event happended given probability
bool didItHappen(float probability){
    if(randomInRange(0, 100000) > 1000*probability){
        return true;
    }
    return false;
}  
