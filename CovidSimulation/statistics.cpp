#include "statistics.h"

Statistics::Statistics() {
  num_vulnerable = 0;
  num_infected = 0;
  num_dead = 0;
}
Statistics::Statistics(int infected, int dead, int vulnerable) {
  num_vulnerable = vulnerable;
  num_infected = infected;
  num_dead = dead;
}

void Statistics::set_saturation(bool flag) { saturation = flag; }

void Statistics::increaseNum_infected() { num_infected++; }

void Statistics::increaseNum_dead() { num_dead++; }

void Statistics::increaseNum_vulnerable() { num_vulnerable++; }

void Statistics::decreaseNum_infected() { num_infected--; }

void Statistics::decreaseNum_dead() { num_dead--; }

void Statistics::decreaseNum_vulnerable() { num_vulnerable--; }

int Statistics::getNum_infected() { return num_infected; }

int Statistics::getNum_dead() { return num_dead; }

int Statistics::getNum_vulnerable() { return num_vulnerable; }

bool Statistics::isTheSystemSaturated() { return saturation; }
