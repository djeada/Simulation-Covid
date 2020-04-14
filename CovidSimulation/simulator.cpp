#include "simulator.h"
#include "person.h"
#include "location.h"

bool saturated = false;

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

//true if probability is greater than 0.5
bool try_event(double probability){
    assert (probability >= 0.0 && probability < 1.0);
    const int resolution = 1000000; //it should be big
    double  rnnum = randomInRange(0, resolution);
    rnnum /= (double)resolution;
    return rnnum <= probability;
}

void sim_main() {
    /*
    //set up the simulation
    Person people[NUM_PEOPLE];
    int infection_history[SIM_HOURS];

    //zero out the history, starting with zero infected
    memset(infection_history, 0, sizeof(infection_history));

    //initial infections, infecting first people
    for(int i = 0; i < INITIAL_INFECTIONS; i++){
    people[i].status = INFECTED;
}
    int max_infected_at_once = 0;
    for (int i = 0; i < SIM_HOURS; i++){
        //redraw the UI, so you can see it happen
        if((i%2) == 0){
            //ui_redraw(people, NUM_PEOPLE, infection_history, SIM_HOURS);
        }

        //move people
        for(int p=0; p < NUM_PEOPLE; p++){
            if(people[p].is_alive()) {
                people[p].mobility_model->move();
                people[p].progress_diesease();
            }
        }

        //try to infect
        for(int p=0; p < NUM_PEOPLE; p++){
            if(people[p].is_alive()){
                for(int p2=0; p2 < NUM_PEOPLE; p2++){
                    if(p != p2 && people[p2].is_alive()){
                        people[p].try_infect(people[p2]);
                    }
                }
            }
        }

        //report status (how many people are in each state)
        int num_infected = 0;
        int num_immune = 0;
        int num_dead = 0;
        int num_vulnerable = 0;

        for(int p = 0; p < NUM_PEOPLE; p++){
            if(!people[p].is_alive()){
                num_dead++;
            }
            if(people[p].status == INFECTED) {
                num_infected++;
            }
            if(people[p].status == IMMUNE) {
                num_immune++;
            }
            if(people[p].status == VULNERABLE){
                num_vulnerable++;
            }
        }
        if (num_infected > max_infected_at_once){
            max_infected_at_once = num_infected;
        }

        //set whether or not the medical system is currently saturated.
        saturated = (num_infected > SATURATION_TRESHOLD);

        if((i % 10) == 0 || num_infected == 0){
            cout << num_vulnerable << "\t" << num_infected << "\t" << num_immune << "\t" << num_dead << "\t" << num_dead*100/NUM_PEOPLE << endl;
        }
        infection_history[i] = num_infected;
        if(num_infected == 0) break;
    }

    cout << "Peak infections " << max_infected_at_once << endl;
    */
}
