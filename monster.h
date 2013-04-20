#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <iostream>

using namespace std;

class Monster : public QGraphicsPixmapItem {
public:
    GamePlayer();
    ~GamePlayer();

    bool isAlive() const;
    int getHitPoints() const;

    void setLives(int n);
    void setHitPoints(int n);

private:
    //For testing, of course.
    QPixmap * monsterImage;

    /**Is the monster alive?*/
    bool isAlive;
    /**Number of hitpoints*/
    int hitPoints;

protected:

};
#endif // MONSTER_H
