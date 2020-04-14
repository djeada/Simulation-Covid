#include "initial_conditions.h"

QVector<int> findLocation(QString sample, const char &findIt);

initial_conditions::initial_conditions(QString str, QString selected_country)
{
    country = selected_country;

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
      char delimeter = ',';
      QVector<int> results = findLocation(s,delimeter);
      deaths.append(s.mid(results[3], results[4]));// appends first column to list, ',' is separator
      infected.append(s.mid(results[2], results[3]));
    }
    file.close();

    qDebug() << deaths;

}

QVector<int> findLocation(QString sample, const char &findIt){
    QVector<int> characterLocations;
    for(int i =0; i < sample.size(); i++)
        if(sample[i] == findIt)
            characterLocations.append(i);
    return characterLocations;
}
