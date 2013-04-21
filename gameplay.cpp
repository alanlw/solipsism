#include "gameplay.h"
#include <qapplication.h>

//Temporary
#include "contradictionmonster.h"

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
    scrollTimer = new QTimer(this);
    scrollTimer->setInterval(10);


    //For scrolling of screen
    connect(scrollTimer, SIGNAL(timeout()), this, SLOT(scrollWindow()));

    myPlayer = new GamePlayer();
    gamePlayScene->addItem(myPlayer);

    myPlayer->setX(WINDOW_MAX_X);
    myPlayer->setY(WINDOW_MAX_Y);

    //Let's try adding a contradiction monster too...
    ContradictionMonster* myContradiction = new ContradictionMonster();
    gamePlayScene->addItem(myContradiction);
    myContradiction->setX(850);
    myContradiction->setY(350);

    show();
}

GamePlay::~GamePlay(){
    delete gamePlayScene;

    delete gamePlayView;

    delete scrollTimer;

    delete myLevel;
}
void GamePlay::show(){
    scrollTimer->start();
    gamePlayView->show();
}

void GamePlay::movePlayer(MoveDirection dir){

    //cout << "Player: " << myPlayer->x() << ", viewRectX: " << viewRectX << endl;

    switch(dir){
    case UP:
        if(myPlayer->y() - 10 >= 0 ){
            myPlayer->moveBy(0, -10);
        }
        break;
    case LEFT:
        if(myPlayer->x() >= viewRectX){
            myPlayer->moveBy(-5,0);
        }
        break;
    case DOWN:
        if(myPlayer->y() + 10 <= 460){
            myPlayer->moveBy(0, 10);
        }
        break;
    case RIGHT:
        if(myPlayer->x() <= viewRectX+WINDOW_MAX_X*2 - 150){
            myPlayer->moveBy(5,0);
        }
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
