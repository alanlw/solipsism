#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QTimer>
#include <iostream>

using namespace std;

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


    /** Set the Monster's hitpoints*/
    void setHitPoints(int n);

    /** Apply damage to the Monster*/

    //=========================================================================
    // Functions activated by interactions with other in-game objects.
    //=========================================================================
    /** @post Player takes n damage.
        @param n The amount of damage the player takes */
    void takeDamge(int n);
    /** @post Player will not take damage temporarily.
        Make monster temporarily invincible (after taking damage)
        so that it takes some effort to defeat it.*/
    void tempInvincible(int numCycles);

    /** Move monster as its attributes dictate.
    Called by animateMonster() slot.
    */
    void move();

protected:
    /** Image of the monster*/
    QPixmap * monsterImage;

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

private:

private slots:
    /** @post reduce the counter before Monster is no longer invincible.
        According to the monsterTimer, reduce invincible*/
    void reduceInvincible();

};
#endif // MONSTER_H
