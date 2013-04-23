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
