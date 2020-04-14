#include "mainwindow.h"
#include "myrect.h"
#include "initial_conditions.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QFileInfo>
#include <QFileDialog>

class QFileDialogTester : public QWidget
{
public:
  void openFile()
  {
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Document",
          QDir::currentPath(),
          "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
    qDebug() << filename;

    if( !filename.isNull() )
    {
      qDebug() << "selected file path : " << filename.toUtf8();
    }
  }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFileDialogTester test;
    //test.openFile();

    QString str = "C:/Users/patri/OneDrive/Dokumente/CovidSimulation/data/4.14.2020.2020";
    initial_conditions my(str, "Germany");
    //create a scene
    QGraphicsScene *scene = new  QGraphicsScene();

    //Create initial population
    QVector<Person*> population;
    for(int i = 0; i < 30; i++){
        //Person* tempHuman = new Person(true,VULNERABLE);
        population.append(new Person(true,INFECTED));
    }
    for(int i = 0; i < 70; i++){
        //Person* tempHuman = new Person(true,VULNERABLE);
        population.append(new Person(true,VULNERABLE));
    }

    QVector<MyRect*> itemVal;
    for(int i = 0; i < 100; i++){
        //MyRect* tempItem =  new MyRect(scene, population[i]);
        itemVal.append(new MyRect(scene, population[i]));
    }

    //create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(1200,800);
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));


    return a.exec();
}


