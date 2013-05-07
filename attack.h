/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef ATTACK_H
#define ATTACK_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

/**
  The Attack class is used as a base class for implementations of various
  Mouse-based click attacks.

  */
class Attack : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    Attack();
    /** Destructor*/
    virtual ~Attack();
    //=========================================================================
    // Accessors and Mutators
    //=========================================================================

    /** @return Get duration of this Attack*/
    int getAttackDuration() const;
    /** @return Get how much time remains before this Attack is complete*/
    int getAttackCountDown() const;

    /** @return Get amount of damage Attack does to players*/
    int getAttackDamage() const;

    /** Set the duration of Attack*/
    void setAttackDuration(int n);
    /** Set the value of the attackCountDown.
        This can be used to speed up or slow down a particular attack.*/
    void setAttackCountDown(int n);
    /** Set the attackDamage of Attack.
        This can be used to make an attack stronger than usual.*/
    void setAttackDamage(int n);

protected:
    /** Image to be displayed for this attack*/
    QPixmap* attackImage;

    /** Duration of this attack.*/
    int attackDuration;
    /** Amount of time that remains before this attack is complete.*/
    int attackCountDown;
    /** Amount of damage this attack will do to players. */
    int attackDamage;

private:

};

#endif // ATTACK_H
