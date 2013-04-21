#include "gameplay.h"
#include <qapplication.h>


GamePlay::GamePlay(QWidget *parent) : QWidget(parent){



    //setFocus();
    cout << "Has focus? " << hasFocus() << endl;

    //Load my level
    myLevel = new GameLevel("sample_map01.gif");
    ContradictionMonster* myContradiction = new ContradictionMonster();
    myLevel->getMonsters().push_back(myContradiction);

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

    //Load Player onto Screen
    myPlayer = new GamePlayer();
    gamePlayScene->addItem(myPlayer);

    myPlayer->setX(WINDOW_MAX_X);
    myPlayer->setY(WINDOW_MAX_Y);

    //Load Monsters

    cout << "Are there monsters to add?" << endl;
    for(int i = 0; i < myLevel->getMonsters().size(); i++){
        cout << "There are " << i+1 << " monsters to add." << endl;
        gamePlayScene->addItem(myLevel->getMonsters()[i]);

        cout << qrand()%300 << endl;
        cout << qrand()%300 << endl;

        int sceneWidth = gamePlayScene->width();
        myLevel->getMonsters()[i]->setX(qrand()%sceneWidth + 800); //These are arbitrary values for now.
        //cout << "Scene width: " << gamePlayScene->width() << endl;
        myLevel->getMonsters()[i]->setY(qrand()%300);
    }

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


    if (monsterCollision()){
        //"Bump back" player a little bit so he can escape being locked in
        //collided position.
        myPlayer->moveBy(-15, 0);
        return;
    }
    //cout << "Player: " << myPlayer->x() << ", viewRectX: " << viewRectX << endl;

    switch(dir){
    case UP:
        if(myPlayer->y() - 10 >= 0 ){
            myPlayer->moveBy(0, -10);
        }
        break;
    case LEFT:
        if(myPlayer->x() >= viewRectX){
            myPlayer->moveBy(-10,0);
        }
        break;
    case DOWN:
        if(myPlayer->y() + 10 <= 460){
            myPlayer->moveBy(0, 10);
        }
        break;
    case RIGHT:
        if(myPlayer->x() <= viewRectX+WINDOW_MAX_X*2 - 150){
            myPlayer->moveBy(10,0);
        }
        break;
    default:
        return;
    }
}

bool GamePlay::monsterCollision(){
    for(int i = 0; i < myLevel->getMonsters().size(); i++){
        if (myPlayer->collidesWithItem(myLevel->getMonsters()[i])){
            return true;
        }
    }
    return false;
}

/*---------------------------------------------
               Slot Definitions
----------------------------------------------*/

void GamePlay::scrollWindow(){


    if (viewRectX<= myLevel->getBgImage()->width() - WINDOW_MAX_X*2){
        viewRectX++;
        gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);


        if(!monsterCollision()){
            //Do not move so player gets "pushed back" by item.
            //Keep the Player on the screen too!
            myPlayer->moveBy(1,0);
        }
        else{
            //"Bump back" player a little bit so he can escape being locked in
            //collided position.
            myPlayer->moveBy(-5, 0);
        }
    }
    else{

        //Once we reach the end of the map, then stop and display start menu for now.
        //displayStartMenu();
    }



}
