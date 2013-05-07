/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <QTimer>
#include <iostream>

using namespace std;

/**
  This is the class for the User-controlled avatar in the game.
  */
class GamePlayer : public QObject, public QGraphicsPixmapItem {

 Q_OBJECT

public:
    //=========================================================================
    // Constructors and Destructors
    //=========================================================================
    /** Constructor*/
    GamePlayer();
    /** Destructor*/
    ~GamePlayer();

    //=========================================================================
    // Accessor and Mutator Functions
    //=========================================================================
    /** @return Number of lives remaining.*/
    int getLives() const;
    /** @return Number of hitpoints remaining.*/
    int getHitPoints() const;
    /** @return Is the player invincible*/
    int getInvincible() const;
    /** @return Damage a monster takes from colliding with player*/
    int getCollisionDamage() const;

    /** @param n value to set GamePlayer's lives to
        @post GamePlayer's lives updated to n */
    void setLives(int n);
    /** @param n value to set GamePlayer's hitPoints to
        @post GamePlayer's lives updated to n */
    void setHitPoints(int n);
    /** @param n value to reduce GamePlayer's hitPoints by
        @post Gameplayer's hitpoints reduced by n*/

    //=========================================================================
    // Functions called when GamePlayer interacts with other game objects
    //=========================================================================
    void takeDamge(int n);
    /** @param numCycles Duration of time to make GamePlayer invincible for
        @post GamePlayer is temporarily invincible*/
    void tempInvincible(int numCycles);

private:
    /** Image of the player*/
    QPixmap * playerImage;

    /** Number of lives*/
    int lives;
    /** Number of hitpoints*/
    int hitPoints;
    /** Amount of damage a player will do to a monster on collission*/
    int collisionDamage;

    /** For temporary invincibility after hitting an obstacle.
        will count down to 0 (no longer invincible) with playerTimer.*/
    int invincible;
    /** For timing how long player can be invincible*/
    QTimer* playerTimer;

private slots:
    /** According to the playerTimer, reduce invincible*/
    void reduceInvincible();

protected:

signals:
    /** When a single life is lost (will I reset the player's position, or
        bring the player back to the beginning of the level?*/
    void lifeLost();
    /** When all of a player's lives are lost. (Losing condition?) */
    void allLivesLost();

};

#endif // GAMEPLAYER_H
