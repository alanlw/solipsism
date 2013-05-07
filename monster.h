/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QTimer>
#include <iostream>

using namespace std;

/** For controlling movements*/
enum MoveDirection {NONE, LEFT, RIGHT, UP, DOWN };

/**
  Base class to derive enemy objects for in this game.
  */
class Monster : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================

    /** Constructor*/
    Monster();
    /** Destructor*/
    virtual ~Monster();

    //=========================================================================
    // Accessor and Mutator Functions
    //=========================================================================

    /** @return Is the Monster alive?*/
    bool isAlive() const;
    /** @return Get the Monster's hitpoints*/
    int getHitPoints() const;
    /** @return Get the amount of damage the Monster does when it collides
      with a player*/
    int getCollisionDamage() const;
    /** @return Get the number of points scored by vanquishing this Monster.*/
    int getScoreVal() const;
    /** @return Is this monster temporarily invincible because it was just attacked?*/
    int getInvincible() const;
    /** @return Get the monster's type*/
    string getMonsterType() const;
    /** @return The move counter's value*/
    int getMoveCounter();

    /** Set the Monster's hitpoints*/
    void setHitPoints(int n);

    /** Apply damage to the Monster*/

    //=========================================================================
    // Functions activated by interactions with other in-game objects.
    //=========================================================================
    /** @post Player takes n damage.
        @param n The amount of damage the player takes */
    void takeDamage(int n);
    /** @post Player will not take damage temporarily.
        Make monster temporarily invincible (after taking damage)
        so that it takes some effort to defeat it.*/
    void tempInvincible(int numCycles);

    /** Move monster as its attributes dictate.
    Called by animateMonster() slot.
    */
    //virtual void move();
    /** Move a monster that is player aware. Parameters passed should be
      the player and monster's position differences.*/
    virtual void move(int x = 0, int y = 0);

protected:
    /** Image of the monster*/
    QPixmap * monsterImage;
    /** ...Or if we want to use an animation...*/
    vector<QPixmap *> monsterImages;

    /** Is the monster alive?*/
    bool alive;
    /** Number of hitpoints*/
    int hitPoints;
    /** How much damage does the monster do to players?*/
    int collisionDamage;
    /** How many points does the player get for defeating this monster?*/
    int scoreVal;

    /** For temporary invincibility after hitting an obstacle.
       will count down to 0 (no longer invincible) with monsterTimer.*/
    int invincible;
    /** For timing how long monster can be invincible*/
    QTimer* monsterTimer;

    /** Counting calls to move function for making moves*/
    int moveCounter;
    /** Name of monster type so it is easy to apply appropriate calculations
        to appropriate monsters in calculations.
        */
    string monsterType;

private:

private slots:
    /** @post reduce the counter before Monster is no longer invincible.
        According to the monsterTimer, reduce invincible*/
    void reduceInvincible();

};
#endif // MONSTER_H
