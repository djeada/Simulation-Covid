#include "person.h"

Person::Person(){
    quarantine_cooperetive = false;
    status = VULNERABLE;
    disease_counter = INFINITY;
    current_location = new Location();
    home_location= new Location();
}

Person::Person(bool cooperetivness, stages_of_disease x){
    quarantine_cooperetive = cooperetivness;
    status = x;
    disease_counter = INFECTION_TIME;
    current_location = new Location();
    if(quarantine_cooperetive){
        home_location = current_location;
    }
    else {
        home_location= new Location();
    }
}

//if you are vulnerable it infects you
bool Person::infect(){
    if(status == VULNERABLE) {
        status = INFECTED;
        return true;
    }
    return false;
}

//they will only move if they dont want to stay in quranteen and they are alive
//some cooperative people will also rarely move in close proximity to their houses
//for shoping or to the doctor
bool Person::will_move(){
    if(this->is_alive() && !quarantine_cooperetive){
        return true;
    }
    if(randomInRange(0, 100) < 10) {
        return true;
    }
    return false;
}

bool Person::try_infect(Person other_person){
    if(other_person.status == INFECTED) {
        return false;
    }
    if(current_location->get_distance(other_person.getLocation()) > INFECTION_PROXIMITY) {
        return false;
    }
    if(try_event(INFECTION_PROBABILITY)) {
        return infect();
    }
    return false;
}

void Person::progress_diesease() {
    if(status == INFECTED) {
        disease_counter--;
        if (disease_counter <= 0){
            //now you either become immune or dead
            double fatality_rate = NORMAL_FATALITY_RATE;
            if (saturated) {
                fatality_rate = SATURATED_FATALITY_RATE;
            }
            if(try_event(fatality_rate)){
                status = DEAD;
            }
            else {
                status = DEAD;
            }
        }
    }
}

enum stages_of_disease Person::getDiseaseStatus(){
    return status;
}

Location Person::getLocation(){
    return *current_location;
}

Location Person::getHome(){
    return *home_location;
}

bool Person::is_alive() {
    return status != DEAD;
}
