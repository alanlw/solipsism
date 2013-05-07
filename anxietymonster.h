/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef ANXIETYMONSTER_H
#define ANXIETYMONSTER_H

#include "monster.h"

/**
    Anxieties move randomly about the map. If they collide with an
    Contradiction Monster, they die. Can be destroyed by player. Anxieties
    generate Mean Words.
  */
class AnxietyMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    AnxietyMonster();
    /** Destructor*/
    ~AnxietyMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes AnxietyMonster move in
        random cardinal directions about playing area. */
    void move(int x, int y);

protected:

private:


    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;


};
#endif // ANXIETYMONSTER_H
