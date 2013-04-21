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


//Temporary
#include "contradictionmonster.h"
#include "psychicattack.h"

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

    /**Function called to attack with the mouse*/
    void clickAttack(const QPoint& pos);

    /**Return myPlayer's hitpoints. Needed for ScoreWidget.*/
    int getPlayerHitpoints();
    /**Return myPlayer's lives. Needed for ScoreWidget. */
    int getPlayerLives();
    /**Return the score. Needed for ScoreWidget*/
    int getScore();


protected:

    /**Return true if player is colliding with a monster.*/
    bool monsterCollision();

private:
    /** To display gameplay */
    QGraphicsScene* gamePlayScene;


    /** What the user sees */
    QGraphicsView *gamePlayView;
    /**x coordinate of scrolling view*/
    int viewRectX;
    /**y coordinate of scrolling view*/
    int viewRectY; //I'm probably not going to be updating this.

    /**For scrolling animation*/
    QTimer* scrollTimer;
    /**For attack animations*/
    QTimer* attackTimer; //This still needs to be initialized, etc.!!
    /**For monster animations*/
    QTimer* monsterTime; //This still needs to be initialized, etc.!!

    /** Data of player*/
    GamePlayer* myPlayer;

    /** To hold my level data*/
    QVector<GameLevel*> myLevels;
        //Temporary, just to make this easier to test.
        GameLevel * myLevel;


    /**Current game score*/
    int score;


public slots:
    /** Scroll the window according to scrollTimer*/
    void scrollWindow();

    /** When player loses lives, stop the game.*/
    void gameOver();

signals:
    void updateScore();


};

#endif // GAMEPLAY_H
