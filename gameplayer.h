#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <QTimer>
#include <iostream>

using namespace std;

class GamePlayer : public QObject, public QGraphicsPixmapItem {

 Q_OBJECT

public:
    GamePlayer();
    ~GamePlayer();

    int getLives() const;
    int getHitPoints() const;
    int getInvincible() const;

    void setLives(int n);
    void setHitPoints(int n);

    void takeDamge(int n);
    void tempInvincible(int numCycles);

private:
    /**Image of the player*/
    QPixmap * playerImage;

    /**Number of lives*/
    int lives;
    /**Number of hitpoints*/
    int hitPoints;

    /**For temporary invincibility after hitting an obstacle.
       will count down to 0 (no longer invincible) with playerTimer.*/
    int invincible;
    /**For timing how long player can be invincible*/
    QTimer* playerTimer;

private slots:
    /**According to the playerTimer, reduce invincible*/
    void reduceInvincible();

protected:

signals:
    /**When a single life is lost (will I reset the player's position, or
    bring the player back to the beginning of the level?*/
    void lifeLost();
    /**When all of a player's lives are lost. (Losing condition?) */
    void allLivesLost();

};

#endif // GAMEPLAYER_H
