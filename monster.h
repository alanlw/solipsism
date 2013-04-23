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
    Monster();
    virtual ~Monster();

    bool isAlive() const;
    int getHitPoints() const;
    int getCollisionDamage() const;
    int getScoreVal() const;
    int getInvincible() const;

    void setLives(int n);
    void setHitPoints(int n);

    void takeDamge(int n);
    void tempInvincible(int numCycles);

protected:
    /**Image of the monster*/
    QPixmap * monsterImage;

    /**Is the monster alive?*/
    bool alive;
    /**Number of hitpoints*/
    int hitPoints;
    /**How much damage does the monster do to players?*/
    int collisionDamage;
    /**How many points does the player get for defeating this monster?*/
    int scoreVal;

    /**For temporary invincibility after hitting an obstacle.
       will count down to 0 (no longer invincible) with monsterTimer.*/
    int invincible;
    /**For timing how long monster can be invincible*/
    QTimer* monsterTimer;

private:

private slots:
    /**According to the monsterTimer, reduce invincible*/
    void reduceInvincible();

};
#endif // MONSTER_H
