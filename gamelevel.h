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

private:
    /** The Level Name*/
    QString levelName;

    /** The Background Image*/
    QPixmap * bgImage;

    /** A Level Transition Item to display*/
    QGraphicsPixmapItem* transitionItem;

    /** Pointer to monsters in level*/
    QVector<Monster*> monsters;

protected:

};

#endif // GAMELEVEL_H
