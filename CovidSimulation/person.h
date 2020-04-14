#ifndef PERSON_H
#define PERSON_H

#include "simulator.h"
#include "mobility_model.h"
#include "location.h"

//describes how it moves
class MobilityModel;

class Person {
        //are they staying at home
        bool quarantine_cooperetive;

        //how much time they still have
        int disease_counter;

        //what stage of diesease they are in
        stages_of_disease status;
    public:
        Person();
        Person(bool cooperetivness, stages_of_disease x);
        void progress_diesease();
        double get_distance(Person other_person);
        bool infect();
        bool try_infect(Person other_person);
        bool is_alive();
        bool will_move();

        enum stages_of_disease getDiseaseStatus();

        Location* current_location;
        Location* home_location;

        Location getLocation();
        Location getHome();
};

#endif // PERSON_H
