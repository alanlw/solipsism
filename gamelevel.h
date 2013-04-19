#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <QPixmap>

#include <QString>
#include <iostream>

using namespace std;

/**
  GameLevel contains all the data necessary to load a paritular game level
  onto a scene.
*/
class GameLevel{

public:
    /**Default constructor*/
    GameLevel();
    /**Constructor with path to level image file*/
    GameLevel(QString imageFileName);
    /**Destructor*/
    ~GameLevel();

    /**Get bgImgae*/
    QPixmap * getBgImage();
private:
    /**The Background Image*/
    QPixmap * bgImage;

protected:

};

#endif // GAMELEVEL_H
