#include "gui.h"
#include "board.h"
#include <QGraphicsTextItem>

gui::gui(){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    scene->setBackgroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));
    setScene(scene);
    show();
}

void gui::openSimulation(){
    scene->clear();
    board simulation_board(scene);
}

void gui::start(){
    // create the title text
    createTitleText();

    // create the play button
    Button* startButton = createButton("Start", 275);
    connect(startButton,SIGNAL(clicked()),this,SLOT(openSimulation()));

    // create the quit button
    Button* quitButton = createButton("Quit", 450);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));

}

void gui::createTitleText(){
    QGraphicsTextItem* titleText = new QGraphicsTextItem(TITLE);
    QFont titleFont("comic sans", TITLE_FONT_SIZE);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);
}

Button* gui::createButton(QString name, int byPos){
    Button* button = new Button(name);
    int bxPos = this->width()/2 - button->boundingRect().width()/2;
    button->setPos(bxPos,byPos);
    scene->addItem(button);
    return button;
}

