#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "gamelevel.h"
#include "gameplayer.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QBoxLayout>

#include <QPushButton>
#include <QKeyEvent>
#include <QMouseEvent>

/** For controlling player avatar's movement*/
enum MoveDirection {NONE, LEFT, RIGHT, UP, DOWN };

#define WINDOW_MAX_X 300
#define WINDOW_MAX_Y 300

class GamePlay : public QWidget{
    Q_OBJECT

public:
    GamePlay(QWidget *parent);
    ~GamePlay();

    void show();

    /**Function called when movement keys are pressed*/
    void movePlayer(MoveDirection dir);
protected:

private:
    /** To display gameplay */
    QGraphicsScene* gamePlayScene;


    /** What the user sees */
    QGraphicsView *gamePlayView;
    /**x coordinate of scrolling view*/
    int viewRectX;
    /**y coordinate of scrolling view*/
    int viewRectY; //I'm probably not going to be updating this.

    /**For animation*/
    QTimer* myTimer;

    /** Data of player*/
    GamePlayer* myPlayer;

    /** To hold my level data*/
    QVector<GameLevel*> myLevels;
        //Temporary, just to make this easier to test.
        GameLevel * myLevel;


public slots:
    /** Scroll the window according to myTimer*/
    void scrollWindow();


};

#endif // GAMEPLAY_H
