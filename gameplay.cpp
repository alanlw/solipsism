#include "gameplay.h"
#include <qapplication.h>

GamePlay::GamePlay(QWidget *parent) : QWidget(parent){



    //setFocus();
    cout << "Has focus? " << hasFocus() << endl;

    //Load my level
    myLevel = new GameLevel("sample_map01.gif");

    //We need a scene and a view to do graphics in QT
    gamePlayScene = new QGraphicsScene(this);

    gamePlayView = new QGraphicsView( gamePlayScene, this );


    viewRectX = 0;
    viewRectY = 0;
    gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);


    /**************************************************************************
      gamePlayScene
      ************************************************************************/

    gamePlayView->setWindowTitle( "Side Scroller Game");
    gamePlayView->setBackgroundBrush(*myLevel->getBgImage());
    

    //Set timer for animation.
    myTimer = new QTimer(this);
    myTimer->setInterval(10);


    //For scrolling of screen
    connect(myTimer, SIGNAL(timeout()), this, SLOT(scrollWindow()));

    myPlayer = new GamePlayer();
    gamePlayScene->addItem(myPlayer);

    myPlayer->setX(WINDOW_MAX_X);
    myPlayer->setY(WINDOW_MAX_Y);


    show();
}

GamePlay::~GamePlay(){
    delete gamePlayScene;

    delete gamePlayView;

    delete myTimer;

    delete myLevel;
}
void GamePlay::show(){
    myTimer->start();
    gamePlayView->show();
}

void GamePlay::movePlayer(MoveDirection dir){
    switch(dir){
    case UP:
        myPlayer->moveBy(0,-5);
        break;
    case LEFT:
        myPlayer->moveBy(-5,0);
        break;
    case DOWN:
        myPlayer->moveBy(0,5);
        break;
    case RIGHT:
        myPlayer->moveBy(5,0);
        break;
    default:
        return;
    }
}

/*---------------------------------------------
               Slot Definitions
----------------------------------------------*/

void GamePlay::scrollWindow(){

    if (viewRectX<= myLevel->getBgImage()->width() - WINDOW_MAX_X*2){
        viewRectX++;
        gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);

        //Keep the Player on the screen too!
        myPlayer->moveBy(1,0);
    }
    else{
        //Once we reach the end of the map, then stop and display start menu for now.
        //displayStartMenu();
    }



}
