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
    /** Constructor*/
    Monster();
    /** Destructor*/
    virtual ~Monster();

    /** Is the Monster alive?*/
    bool isAlive() const;
    /** Get the Monster's hitpoints*/
    int getHitPoints() const;
    /** Get the amount of damage the Monster does when it collides
      with a player*/
    int getCollisionDamage() const;
    /** Get the number of points scored by vanquishing this Monster.*/
    int getScoreVal() const;
    /** Is this monster temporarily invincible because it was just attacked?*/
    int getInvincible() const;


    /** Set the Monster's hitpoints*/
    void setHitPoints(int n);

    /** Apply damage to the Monster*/
    void takeDamge(int n);
    /** Make monster temporarily invincible (after taking damage)
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
    /** According to the monsterTimer, reduce invincible*/
    void reduceInvincible();

};
#endif // MONSTER_H
