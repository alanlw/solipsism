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

private:
    //For testing, of course.
    QPixmap * testImage;

protected:

};

#endif // GAMEPLAYER_H
