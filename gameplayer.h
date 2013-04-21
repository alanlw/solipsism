#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <iostream>

using namespace std;

class GamePlayer : public QGraphicsPixmapItem {
public:
    GamePlayer();
    ~GamePlayer();

    int getLives() const;
    int getHitPoints() const;

    void setLives(int n);
    void setHitPoints(int n);

private:
    /**Image of the player*/
    QPixmap * playerImage;

    /**Number of lives*/
    int lives;
    /**Number of hitpoints*/
    int hitPoints;

protected:

};

#endif // GAMEPLAYER_H
