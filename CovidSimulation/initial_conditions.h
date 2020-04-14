#ifndef INITIAL_CONDITIONS_H
#define INITIAL_CONDITIONS_H
#include <QFile>
#include <QStringList>
#include <QStringRef>
#include <QDebug>
#include <QMessageBox>
#include <QVector>

class initial_conditions
{
     QString country;
     int population;
     int num_cases;
     int num_deaths;
     int percent_of_Quarantine;
     int hospital_capacity;
public:
    initial_conditions(QString selected_country);
    void setPopulation(QString str);
    void setCasesAndDeaths(QString str);
};

#endif // INITIAL_CONDITIONS_H
