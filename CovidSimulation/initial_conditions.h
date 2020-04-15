#ifndef INITIAL_CONDITIONS_H
#define INITIAL_CONDITIONS_H

#include <QVector>
#include "person.h"

/* Initial conditions for the simulation are taken from real data.
  Two csv files are submitted, one for total population of the country,
  and the second for active cases/deaths from covid-19.
*/

class Initial_conditions
{
     QString country;
     int population;
     int num_cases;
     int num_deaths;
public:
    Initial_conditions(QString selected_country);
    void setPopulation(QString str);
    void setCasesAndDeaths(QString str);
    int getNumCases();
    int getNumDeaths();
    int getPopulation();
};

QVector<Person> populate(Initial_conditions my_initial_conditions);

#endif // INITIAL_CONDITIONS_H
