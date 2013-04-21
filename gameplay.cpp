#include "gameplay.h"
#include <qapplication.h>


GamePlay::GamePlay(QWidget *parent) : QWidget(parent){



    //setFocus();
    //cout << "Has focus? " << hasFocus() << endl;

    //Load my level
    myLevel = new GameLevel("sample_map01.gif");

    for (int n = 0; n < 15; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        myLevel->getMonsters().push_back(myContradiction);
    }

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

    attackTimer = new QTimer();
    attackTimer->setInterval(10);


    //For scrolling of screen
    connect(scrollTimer, SIGNAL(timeout()), this, SLOT(scrollWindow()));
    //For attack animations
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(animateAttacks()));


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
        cout << "sceneWidth = " << sceneWidth << endl;
        myLevel->getMonsters()[i]->setX(qrand()%sceneWidth + 800); //These are arbitrary values for now.
        //cout << "Scene width: " << gamePlayScene->width() << endl;
        myLevel->getMonsters()[i]->setY(qrand()%300);
    }

    score = 0;

    //When a player loses all lives, the game is over.
    connect(myPlayer, SIGNAL(allLivesLost()), this, SLOT(gameOver()));


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
    attackTimer->start();
    gamePlayView->show();
}

void GamePlay::movePlayer(MoveDirection dir){

    if (!myPlayer->isEnabled()){
        return;
    }
    if (monsterCollision()){
        //"Bump back" player a little bit so he can escape being locked in
        //collided position.
        //myPlayer->moveBy(-15, 0);
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
void GamePlay::clickAttack(QMouseEvent *e){
    QPoint myPoint = e->pos(); //so errors don't complain.
    myPoint.setX(myPoint.x() + viewRectX - 35);
    myPoint.setY(myPoint.y() - 65);
    //Right here I am only correcting the symptom... I must find how to
    //get the actual scene coordinate instead of just correcting for the
    //global window one.  Maybe this is a result of getting the QMouseEvent
    //from MainWindow, but I haven't been able to successfully get it from
    //somewhere else yet (nor do I know I would want to)

    cout << "ATTACK!! (" << myPoint.x() << ", " << myPoint.y() << ") " << endl;

    //Now I will want to either create, or move some attack object here so I
    //can do collision calculations with the other objects.

    //Do I want to make this less specific to a psychic attack later?
    PsychicAttack* tempAtk = new PsychicAttack();
    myAttacks.push_back(tempAtk);
    tempAtk->setPos(myPoint);
    tempAtk->setAttackCountDown(tempAtk->getAttackDuration());
    gamePlayScene->addItem(tempAtk);



}

int GamePlay::getPlayerHitpoints(){
    return myPlayer->getHitPoints();
}

int GamePlay::getPlayerLives(){
    return myPlayer->getLives();
}
int GamePlay::getScore(){
    return score;
}

bool GamePlay::monsterCollision(){
    if(myPlayer->getInvincible()){
        return false;
    }
    for(int i = 0; i < myLevel->getMonsters().size(); i++){
        if (myPlayer->collidesWithItem(myLevel->getMonsters()[i])){


            //Apply collision damage to player.
            myPlayer->takeDamge(myLevel->getMonsters()[i]->getCollisionDamage());
            if(!myPlayer->getInvincible()){
                myPlayer->tempInvincible(15);
            }

            return true;
        }
    }
    return false;
}

/*---------------------------------------------
               Slot Definitions
----------------------------------------------*/

void GamePlay::scrollWindow(){

    //Will it make this game significantly slower to do this here?
    emit updateScore();

    if (viewRectX<= myLevel->getBgImage()->width() - WINDOW_MAX_X*2){
        viewRectX++;
        gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);


        if(!monsterCollision()){
            //Do not move so player gets "pushed back" by item.
            //Keep the Player on the screen too!
            myPlayer->moveBy(1,0);
        }
        else{
            //"Bump back" player a little bit when he hits something while
            //scrolling.
            myPlayer->moveBy(-15, 0);
        }
    }
    else{

        //Once we reach the end of the map, then stop and display start menu for now.
        //displayStartMenu();
    }
}

void GamePlay::animateAttacks(){
    // Must connect this.

    //For every attack...
    for(int i = 0; i < myAttacks.size(); i++){
        if(myAttacks[i]->getAttackCountDown() == 0){
            //'Destroy' attack.
            gamePlayScene->removeItem(myAttacks[i]);

            //Is it unwise to delete here?
            delete myAttacks[i];
            myAttacks.remove(i);


        }
        else{
            myAttacks[i]->
                    setAttackCountDown(myAttacks[i]->getAttackCountDown() - 1);
           //I can insert movement animation here.
            if (myAttacks[i]->getAttackCountDown() % 2 == 0){
                myAttacks[i]->moveBy(20, 0);
            }
            else{
                myAttacks[i]->moveBy(-20, 0);
            }
        }
    }
}

void GamePlay::gameOver(){
    emit updateScore();
    cout << "Game Over!" << endl;
    scrollTimer->stop();
}
