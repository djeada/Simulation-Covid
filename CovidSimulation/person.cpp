#include "person.h"
#include "simulation.h"

Person::Person(){
    quarantine_cooperative = true;
    status = HEALTHY;
    disease_counter = (int)INFINITY;
    current_location = new Location();
    home_location = new Location();
    max_home_dist = MAX_HOME_DIST;
}

Person::Person(bool cooperativness, stages_of_disease x){
    quarantine_cooperative = cooperativness;
    status = x;
    current_location = new Location();
    setHomeLocation();
    setInitialDiseaseCounter();
    setMaxHomeDistance();
}

void Person::setInitialDiseaseCounter(){
    if(status == HEALTHY){
        disease_counter = INFINITY;
        return;
    }
    if(status == INFECTED){
        disease_counter = INFECTION_TIME;
        return;
    }
    disease_counter = 0;
    return;
}

void Person::setMaxHomeDistance()
{
    if(quarantine_cooperative){
        max_home_dist = MAX_HOME_DIST + randomInRange(-2,2);
    }
    else {
        max_home_dist = MAX_HOME_DIST + randomInRange(10,100);
    }
}

void Person::setHomeLocation()
{
    if(quarantine_cooperative){
        home_location = current_location;
    }
    else {
        home_location= new Location();
    }
}

void Person::setDirection(Location l){
    double dx = l.getCorX() - current_location->getCorX();
    double dy = l.getCorY() - current_location->getCorY();
    double theta = atan2(dy,dx);
    current_location->setCorVX(cos(theta));
    current_location->setCorVY(sin(theta));
}

void Person::shouldGoHome(){
    if(get_distance(*home_location) > max_home_dist){
        setDirection(*home_location);
    }
}

double Person::get_distance(Location l){
    double dx = l.getCorX() - getLocation()->getCorX();
    double dy = l.getCorY() - getLocation()->getCorY();
    return sqrt((dx*dx)+(dy*dy));
}

double Person::get_distance_to_person(Person other_person){
    double dx = other_person.getLocation()->getCorX() - getLocation()->getCorX();
    double dy = other_person.getLocation()->getCorY() - getLocation()->getCorY();
    return sqrt((dx*dx)+(dy*dy));
}

//they will only move if they dont want to stay in quranteen and they are alive
//some cooperative people will also rarely move in close proximity to their houses
//for shoping or to the doctor
bool Person::will_move(){
    if(status == HEALTHY && !quarantine_cooperative)
        return true;
    else if(status != DEAD)
        if(didItHappen(0.3))
            return true;
    return false;
}

void Person::try_infect(Person &other_person, Statistics *current_stats){
    if(other_person.getDiseaseStatus() == HEALTHY && status == INFECTED) {
        if(didItHappen(INFECTION_PROBABILITY)){
            other_person.setDiseaseStatus(INFECTED);
            current_stats->increaseNum_infected();
            current_stats->decreaseNum_vulnerable();
        }
    }
}

void Person::progress_diesease(Statistics *current_stats) {
    if(status == INFECTED) {
        disease_counter--;
        if (disease_counter <= 0){
            double fatality_rate = NORMAL_FR;
            if (current_stats->isTheSystemSaturated()) {
                fatality_rate = SATURATED_FR;
            }
            if(didItHappen(fatality_rate)){
                status = DEAD;
                current_stats->increaseNum_dead();
                current_stats->decreaseNum_infected();
            }
            else {
                status = HEALTHY;
                disease_counter = INFINITY;
                current_stats->increaseNum_vulnerable();
                current_stats->decreaseNum_infected();
            }
        }
    }
}

enum stages_of_disease Person::getDiseaseStatus(){
    return status;
}

void Person::setDiseaseStatus(enum stages_of_disease x){
    status = x;
}

QColor Person::chooseColor(){
    if(status == HEALTHY)
        return Qt::green;
    if(status == INFECTED)
        return Qt::red;
    return Qt::black;
}

Location* Person::getLocation(){
    return current_location;
}

Location* Person::getHome(){
    return home_location;
}

bool Person::is_alive() {
    return status != DEAD;
}
