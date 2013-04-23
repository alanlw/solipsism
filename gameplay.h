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

    //Game Control Related Functions
    //=========================================================================
    /*
      Load the specified level into the gamePlayScene.
      @param level A pointer to the level to be loaded.
    */
    bool loadLevel(GameLevel* level);
    void pauseGame();
    void unPauseGame();

    //Functions Triggered by User Input
    //=========================================================================

    /**Function called when movement keys are pressed*/
    void movePlayer(MoveDirection dir);
    /**Function called to attack with the mouse*/
    void clickAttack(QMouseEvent *e);


    //Accessor Functions
    //=========================================================================

    /**Return myPlayer's hitpoints. Needed for ScoreWidget.*/
    int getPlayerHitpoints();
    /**Return myPlayer's lives. Needed for ScoreWidget. */
    int getPlayerLives();
    /**Return the score. Needed for ScoreWidget*/
    int getScore();
    /**Is a level currently loaded?*/
    bool getLevelLoaded();
    /**Is the game paused?*/
    bool getGamePaused();


protected:

    void mousePressEvent(QMouseEvent *e);

    /**Return true if player is colliding with a monster.*/
    bool monsterCollision();

    /**Return true if attack is colliding with a monster Will need to write this later...*/
    bool attackCollision();



private:
    /** To display gameplay */
    QGraphicsScene* gamePlayScene;

    /** To display a pause message in game*/
    QGraphicsTextItem * pauseMessage;

    /** What the user sees */
    QGraphicsView *gamePlayView;
    /**x coordinate of scrolling view*/
    int viewRectX;
    /**y coordinate of scrolling view*/
    int viewRectY; //I'm probably not going to be updating this.

    /** To hold my level data*/
    QVector<GameLevel*> myLevels;
        //Temporary, just to make this easier to test.
        //GameLevel * myLevel;

    /**Is the level loaded?*/
    bool levelLoaded;
    /**Is the game paused?*/
    bool gamePaused;

    /**The index of the level the player is playing*/
    int levelPlaying;




    //Animation Related Fields
    //=========================================================================

    /**For scrolling animation*/
    QTimer* scrollTimer;
    /**For attacking animation*/
    QTimer* attackTimer;

    //Objects in the Game
    //=========================================================================
    /**Store the attacks that I "summon"*/
    QVector<Attack*> myAttacks;

    /** Data of player*/
    GamePlayer* myPlayer;



    //Score-Keeping
    //=========================================================================

    /**Current game score*/
    int score;


public slots:
    /** Scroll the window according to scrollTimer*/
    void scrollWindow();

    /** Animate attacks according to attackTimer*/
    void animateAttacks();

    /** When the player clicks the start button, launch game appropriately.*/
    void launchGame();

    /** When player loses lives, stop the game.*/
    void gameOver();

    /** When the player clears a level, we want to advance the player to a new level if possible.*/
    void nextLevel();

signals:
    /**Emit this signal so that the ScoreWidget can check the GamePlay widget
      for score updates*/
    void updateScore();

    /**Emit this signal when a level is cleared so that a new level can be
      loaded.*/
    void levelCleared();


};

#endif // GAMEPLAY_H
