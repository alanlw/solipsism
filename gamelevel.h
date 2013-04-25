#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QVector>

#include <QString>
#include <iostream>

#include "monster.h"

using namespace std;

/**
  GameLevel contains all the data necessary to load a paritular game level
  onto a scene.
*/
class GameLevel{

public:
    /** Default constructor*/
    GameLevel();
    /** Constructor with path to level image file*/
    GameLevel(QString imageFileName, QString myLevelName = "New Level");
    /** Destructor*/
    ~GameLevel();

    //=========================================================================
    // Accessor Functions
    //=========================================================================
    /** Get bgImgae*/
    QPixmap * getBgImage();
    /** Get monsters*/
    QVector<Monster*>& getMonsters();

    /** Get counter value*/
    int getCounter() const;
    void setCounter(int n);

    /** Get opening screen pixmap*/
    QPixmap * getOpeningScreen();
    /** Get closing screen pixmap*/
    QPixmap * getClosingScreen();



private:
    /** The Level Name*/
    QString levelName;

    /** The Background Image*/
    QPixmap * bgImage;

    /** A level transition to display at the start of the level*/
    QPixmap* openingScreen;
    /** A level transition to display at the end of the level*/
    QPixmap* closingScreen;

    /** Pointer to monsters in level*/
    QVector<Monster*> monsters;

    /** A counter for working with timers and functions*/
    int counter;



protected:

};

#endif // GAMELEVEL_H
