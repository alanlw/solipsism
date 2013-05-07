/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef PSYCHIC_ATTACK_H
#define PSYCHIC_ATTACK_H
#include "attack.h"

#include <QObject>
#include <QMouseEvent>

/**
    By clicking on certain monsters, the player can reduce these monster's
    health and eventually make them disappear. An animation of a rippling
    purple circles will represent this object.
  */
class PsychicAttack : public Attack{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    PsychicAttack();
    /** Destructor*/
    ~PsychicAttack();
protected:

private:

public slots:

};

#endif // PSYCHIC_ATTACK_H
