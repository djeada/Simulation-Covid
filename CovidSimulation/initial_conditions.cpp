#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "initial_conditions.h"
#include "simulation.h"

QVector<int> findLocation(QString sample, const char &findIt);
QString substring( QString str, int start, int end);
bool contains(QString a, QString b);

Initial_conditions::Initial_conditions(QString selected_country) {
    country = selected_country;

    QString str = "C:/Users/patri/OneDrive/Dokumente/CovidSimulation/data/population.2020";
    setPopulation(str);

    str = "C:/Users/patri/OneDrive/Dokumente/CovidSimulation/data/4.14.2020.2020";
    setCasesAndDeaths(str);
}

void Initial_conditions::setPopulation(QString str){
    //open the file
    QFile file(str);
    try{
        file.open(QIODevice::ReadOnly);
    }
    catch (...){
        QMessageBox Msgbox;
        Msgbox.setText(file.errorString());
        Msgbox.exec();
    }

    QTextStream s1(&file);
    QStringList lpopulation;
    while (!s1.atEnd()){
      QString s=s1.readLine(); // reads line from file
      if(contains(s, country) && contains(s,"Total")){
          char delimeter = ',';
          QVector<int> results = findLocation(s,delimeter);
          lpopulation.append(substring(s, results[results.size()-3]+2, results[results.size()-2]-2));// appends first column to list, ',' is separator
      }
    }
    file.close();

    population = lpopulation[1].toInt();
}

void Initial_conditions::setCasesAndDeaths(QString str){
    //open the file
    QFile file(str);
    try{
        file.open(QIODevice::ReadOnly);
    }
    catch (...){
        QMessageBox Msgbox;
        Msgbox.setText(file.errorString());
        Msgbox.exec();
    }

    QTextStream s1(&file);
    QStringList deaths, infected;

    while (!s1.atEnd()){
      QString s=s1.readLine(); // reads line from file
      if(contains(s, country)){
          char delimeter = ',';
          QVector<int> results = findLocation(s,delimeter);
          deaths.append(substring(s, results[4]+1, results[5]-1));// appends first column to list, ',' is separator
          infected.append(substring(s, results[3]+1, results[4]-1));
      }
    }
    file.close();
    num_cases  = infected[1].toInt();
    num_deaths = deaths[1].toInt();
}

int Initial_conditions::getNumCases(){
    return num_cases;
}

int Initial_conditions::getNumDeaths(){
    return num_deaths;
}

int Initial_conditions::getPopulation(){
    return population;
}

bool contains(QString a, QString b){
    return  a.toStdString().find(b.toStdString()) != std::string::npos;
}

QString substring( QString str, int start, int end){
    QString result = "";
    for(int i = start; i <= end; i++){
        result += str[i];
    }
    return result;
}

QVector<int> findLocation(QString sample, const char &findIt){
    QVector<int> characterLocations;
    for(int i =0; i < sample.size(); i++)
        if(sample[i] == findIt)
            characterLocations.append(i);
    return characterLocations;
}

QVector<Person> populate(Initial_conditions my_initial_conditions){
    QVector<Person> population;
    assert (my_initial_conditions.getPopulation() > 0);
    int num_of_infected = (int)my_initial_conditions.getNumCases()*NUM_PEOPLE/my_initial_conditions.getPopulation();
    int num_of_dead = (int)my_initial_conditions.getNumDeaths()*NUM_PEOPLE/my_initial_conditions.getPopulation();
    int num_of_vulnerable = NUM_PEOPLE - num_of_dead - num_of_infected;
    assert (num_of_vulnerable >= 0 && num_of_vulnerable  <= NUM_PEOPLE);
    bool chance_of_cooperation;
    for(int i = 0; i < num_of_infected; ++i){
        chance_of_cooperation = didItHappen(PERCENT_OF_COOPERATIVE);
        population.append({chance_of_cooperation,INFECTED});
    }
    for(int i = 0; i < num_of_dead; ++i){
        chance_of_cooperation = didItHappen(PERCENT_OF_COOPERATIVE);
        population.append({chance_of_cooperation,DEAD});
    }
    for(int i = 0; i < num_of_vulnerable; ++i){
        chance_of_cooperation = didItHappen(PERCENT_OF_COOPERATIVE);
        population.append({chance_of_cooperation,HEALTHY});
    }
    return population;
}

