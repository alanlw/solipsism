/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef MEANWORDSMONSTER_H
#define MEANWORDSMONSTER_H

#include "monster.h"
#include <QGraphicsTextItem>

/**
    Mean words are attacks launched by AnxietyMonsters.
 */
class MeanWordsMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    MeanWordsMonster();
    /** Destructor*/
    ~MeanWordsMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes MeanWordsMonster move in
        random cardinal directions about playing area. */
    void move(int x=0, int y=0);

    //=======================================================================
    // Accessor and Mutator Functions
    //=======================================================================

protected:

private:

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;

    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;

    MoveDirection myDir;

};

#endif // MEANWORDSMONSTER_H
