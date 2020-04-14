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
     int cases;
     int deaths;
     int percent_of_Quarantine;
     int hospital_capacity;
public:
    initial_conditions(QString str,  QString selected_country);
};

#endif // INITIAL_CONDITIONS_H
