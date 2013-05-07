/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

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
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
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
    /** Set counter value*/
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


    /** Pointer to monsters in level*/
    QVector<Monster*> monsters;

    /** A counter for working with timers and functions*/
    int counter;



protected:

};

#endif // GAMELEVEL_H
