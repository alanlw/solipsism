#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <iostream>

using namespace std;

class Monster : public QGraphicsPixmapItem {
public:
    Monster();
    virtual ~Monster();

    bool isAlive() const;
    int getHitPoints() const;
    int getCollisionDamage() const;

    void setLives(int n);
    void setHitPoints(int n);

protected:
    /**Image of the monster*/
    QPixmap * monsterImage;

    /**Is the monster alive?*/
    bool alive;
    /**Number of hitpoints*/
    int hitPoints;
    /**How much damage does the monster do to players?*/
    int collisionDamage;

private:

};
#endif // MONSTER_H
