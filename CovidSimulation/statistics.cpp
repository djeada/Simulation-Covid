#include "statistics.h"

statistics::statistics(){
    num_vulnerable = 0;
    num_infected = 0;
    num_dead = 0;
}

void statistics::increaseNum_infected(){
    num_infected++;
}

void statistics::increaseNum_dead(){
    num_dead++;
}

void statistics::increaseNum_vulnerable(){
    num_vulnerable++;
}

int statistics::getNum_infected(){
    return num_infected;
}

int statistics::getNum_dead(){
    return num_dead;
}

int statistics::getNum_vulnerable(){
    return num_vulnerable;
}
