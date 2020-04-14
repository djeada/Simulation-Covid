#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <bits/stdc++.h>

//how long will healthy people live
#define INFINITY INT_MAX

//general simulation parameters
#define SIM_HOURS 5000
#define NUM_PEOPLE 1000

//stage of the disease
enum stages_of_disease {VULNERABLE, INFECTED, DEAD};

//how many hours the infection lasts
#define INFECTION_TIME (24*20)

//likelihood of infection when exposed
#define INFECTION_PROBABILITY 0.5

//disease dynamics
#define NORMAL_FATALITY_RATE 0.01 //you can still get help
#define SATURATED_FATALITY_RATE 0.06
#define INFECTION_PROXIMITY 5.0 //how close to infected person you need to be
#define INITIAL_INFECTIONS 5

//how many sick people at a time can the health system handle before collapsing.

#define SATURATION_TRESHOLD (NUM_PEOPLE / 20)

//is the system saturated
extern bool saturated;

//roll the dice, returs true if the event occured
//false otherwise
bool try_event(double probability);

//returns a random number (of T type) picked from a range <start, end>
template<typename T>
T randomInRange(T start, T end);

//returns -1 or 1, similiar to dice roll
int headOrTail();

#endif // SIMULATOR_H
