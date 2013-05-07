/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

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


//Header Files for my Moveable Items

#include "monster.h"
#include "contradictionmonster.h"
#include "soundargumentmonster.h"
#include "anxietymonster.h"
#include "meanwordsmonster.h"
#include "depressionmonster.h"
#include "despairmonster.h"
#include "psychicattack.h"



/** For controlling player avatar's movement*/
//enum MoveDirection {NONE, LEFT, RIGHT, UP, DOWN };

#define WINDOW_MAX_X 300
#define WINDOW_MAX_Y 300

/**
  This widget contains the actual implementation of game play, using a view
  that pans over a scene.

  */

class GamePlay : public QWidget{
    Q_OBJECT

public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor */
    GamePlay(QWidget *parent);
    /** Destructor */
    ~GamePlay();
    /** Show */
    void show();

    //=========================================================================
    //Game Control Related Functions
    //=========================================================================
    /**
      Load the specified level into the gamePlayScene.
      @param level A pointer to the level to be loaded.
    */
    bool loadLevel(GameLevel* level);
    /** Pause the game */
    void pauseGame();
    /** Unpause the game */
    void unPauseGame();

    //=========================================================================
    //Functions Triggered by User Input
    //=========================================================================

    /** Function called when movement keys are pressed*/
    void movePlayer(MoveDirection dir);
    /** Function called to attack with the mouse*/
    void clickAttack(QMouseEvent *e);

    //=========================================================================
    //Accessor Functions
    //=========================================================================

    /** @return Return myPlayer's hitpoints. Needed for ScoreWidget.*/
    int getPlayerHitpoints();
    /** @return Return myPlayer's lives. Needed for ScoreWidget. */
    int getPlayerLives();
    /** @return Return the score. Needed for ScoreWidget*/
    int getScore();
    /** @return Is a level currently loaded?*/
    bool getLevelLoaded();
    /** @return Is the game paused?*/
    bool getGamePaused();
    /** @return the player's name*/
    QString getPlayerName();

    /** @return Return gamePlayView*/
    QGraphicsView* getGamePlayView();
    /** @return Return x coordinate of view on scene*/
    int getViewRectX();
    /** @return Return y coordinate of view on scene*/
    int getViewRectY();


protected:
    /** Process mouse events to generate attacks*/
    void mousePressEvent(QMouseEvent *e);

    /** @return Return true if player is colliding with a monster.*/
    bool monsterCollision();

    /** @return Return true if attack is colliding with a monster Will need to write this later...*/
    bool attackCollision();



private:

		//=========================================================================
    //View, Scene and Level Related Fields
    //=========================================================================

    /** To display gameplay */
    QGraphicsScene* gamePlayScene;

    /** To display a pause message in game*/
    QGraphicsTextItem * pauseMessage;

    /** What the user sees */
    QGraphicsView *gamePlayView;
    /** x coordinate of scrolling view*/
    int viewRectX;
    /** y coordinate of scrolling view*/
    int viewRectY; //I'm probably not going to be updating this.

    /** To hold my level data*/
    QVector<GameLevel*> myLevels;
    /** Pointer to the actual level I'm playing*/
    GameLevel* myLevel;
        //Temporary, just to make this easier to test.
        //GameLevel * myLevel;

    QString playerName;

    /** @return Is the level loaded?*/
    bool levelLoaded;
    /** @return Is the game paused?*/
    bool gamePaused;

    /** @return The index of the level the player is playing*/
    int levelPlaying;


    //A helper function, actually load all the objects into the GameLevels.
    void populateLevels();



		//=========================================================================
    //Animation Related Fields
    //=========================================================================

    /** For scrolling animation*/
    QTimer* scrollTimer;
    /** For attacking animation*/
    QTimer* attackTimer;

		//=========================================================================
    //Objects in the Game
    //=========================================================================
    /** Store the attacks that I "summon"*/
    QVector<Attack*> myAttacks;

    /** Data of player*/
    GamePlayer* myPlayer;

		//=========================================================================
    //Score-Keeping
    //=========================================================================

    /** Current game score*/
    int score;


public slots:
    /** Scroll the window according to scrollTimer*/
    void scrollWindow();

    /** Animate attacks according to attackTimer*/
    void animateAttacks();

    /** Function called by timer to move monsters*/
    void animateMonsters();

    /** When the player clicks the start button, launch game appropriately.*/
    void launchGame();

    /** When player loses lives, stop the game.*/
    void gameOver();

    /** When the player clears a level, we want to advance the player to a new level if possible.*/
    void nextLevel();




signals:
    /** Emit this signal so that the ScoreWidget can check the GamePlay widget
      for score updates*/
    void updateScore();

     /** Emit this signal when the player dies to add a score for candidacy to
       the high score list.*/
    void addScore();

    /** Emit this signal when a level is cleared so that a new level can be
      loaded.*/
    void levelCleared();

    /** Emit a sginal when player's name is recieved so that I cna update
        the label on the MainWindow. */
    void nameEntered();



};

#endif // GAMEPLAY_H
