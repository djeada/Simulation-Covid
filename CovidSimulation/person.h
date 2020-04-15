#ifndef PERSON_H
#define PERSON_H

#include "location.h"
#include "statistics.h"
#include <QColor>

/* Main model for our simulation.
 * Each person holds vital infromations, about their health
 * and current position.
 * Behaviours of movement, infection and disease progress are
 * modeled here.
*/

#define CLOSE_ENOUGH 1 //locations less than this distance are in danger
#define PERSON_SIZE 10
#define MAX_HOME_DIST 5 //avg maximum distance from home before they start coming back

//diesease has three possible stages
enum stages_of_disease {HEALTHY, INFECTED, DEAD};

class Person {
        //how far from home can they go before coming back
        int max_home_dist;

        //are they staying at home
        bool quarantine_cooperative;

        //how much time they still have
        int disease_counter;

        //what stage of diesease they are in
        stages_of_disease status;
    public:
        Person();
        Person(bool cooperetivness, stages_of_disease x);
        void progress_diesease(Statistics  *current_stats);
        void try_infect(Person &other_person, Statistics *current_stats);
        bool is_alive();
        bool will_move();

        enum stages_of_disease getDiseaseStatus();
        void setDiseaseStatus(enum stages_of_disease x);
        void setInitialDiseaseCounter();
        void setMaxHomeDistance();
        void setHomeLocation();
        void setDirection(Location l);
        void shouldGoHome();

        Location* current_location;
        Location* home_location;

        Location* getLocation();
        Location* getHome();

        double get_distance(Location l);
        double get_distance_to_person(Person other_person);


        QColor chooseColor();
};

#endif // PERSON_H
