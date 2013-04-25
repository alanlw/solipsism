#include "gameplay.h"
#include <qapplication.h>
#include <QGraphicsTextItem> //For pauses messages, etc.


GamePlay::GamePlay(QWidget *parent) : QWidget(parent){


    //setFocus();
    //cout << "Has focus? " << hasFocus() << endl;



    //=========================================================================
    //This is temporary, I need to think of a better way to store/access/etc.
    //level data.
    //
    //Load my level
    GameLevel * myLevel = new GameLevel("sample_map01.gif");
    for (int n = 0; n < 12; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        myLevel->getMonsters().push_back(myContradiction);
    }
    for (int n = 0; n < 12; n++){
        SoundArgumentMonster* mySoundArgument = new SoundArgumentMonster();
        myLevel->getMonsters().push_back(mySoundArgument);
    }
    for (int n = 0; n < 12; n++){
        AnxietyMonster* myAnxiety = new AnxietyMonster();
        myLevel->getMonsters().push_back(myAnxiety);
    }
    myLevels.push_back(myLevel);
    cout << "Level 0 Loaded." << endl;


    myLevel = NULL;
    myLevel = new GameLevel("sample_map02.gif");

    for (int n = 0; n < 15; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        myLevel->getMonsters().push_back(myContradiction);
    }
    myLevels.push_back(myLevel);
    cout << "Level 1 Loaded." << endl;

    myLevel = NULL;
    myLevel = new GameLevel("sample_map03.jpg");
    //myLevel = new GameLevel("sample_map03.jpg");

    for (int n = 0; n < 20; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        myLevel->getMonsters().push_back(myContradiction);
    }
    myLevels.push_back(myLevel);
    cout << "Level 2 Loaded." << endl;

    //=========================================================================

    //We need a scene and a view to do graphics in QT
    gamePlayScene = new QGraphicsScene(this);
    gamePlayView = new QGraphicsView( gamePlayScene, this );



    levelLoaded = false;
    viewRectX = 0;
    viewRectY = 0;
    gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);


    myPlayer = new GamePlayer();
    gamePlayScene->addItem(myPlayer);

    //Load Player onto Screen
    //gamePlayScene->addItem(myPlayer);

    //myPlayer->setX(WINDOW_MAX_X - 200);
    //myPlayer->setY(WINDOW_MAX_Y);
    gamePaused = true; //So I can't just move around the player to start.

    connect(this, SIGNAL(levelCleared()), this, SLOT(nextLevel()));

    /**Start on level 0*/
    levelPlaying = 0;


    /**************************************************************************
      gamePlayScene
      ************************************************************************/

    gamePlayView->setWindowTitle( "Side Scroller Game");
    

    //Set timer for animation.
    scrollTimer = new QTimer(this);
    scrollTimer->setInterval(10);

    attackTimer = new QTimer();
    attackTimer->setInterval(10);


    //For scrolling of screen
    connect(scrollTimer, SIGNAL(timeout()), this, SLOT(scrollWindow()));
    //For attack animations
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(animateAttacks()));
    //When a player loses all lives, the game is over.
    connect(scrollTimer, SIGNAL(timeout()), this, SLOT(animateMonsters()));
    connect(myPlayer, SIGNAL(allLivesLost()), this, SLOT(gameOver()));

    levelLoaded = false;
    gamePaused = false;

    score = 0;

    show();
}

GamePlay::~GamePlay(){
    delete gamePlayScene;

    delete gamePlayView;

    delete scrollTimer;

    //delete myLevel;
}
void GamePlay::show(){
    gamePlayView->show();
}

bool GamePlay::loadLevel(GameLevel *level){

    //Set levelLoaded to false until we finish loading content.
    levelLoaded = false;

    if(level == NULL){
        return false;
    }
    //I must remove the player here so the player isn't deleted when I call
    //clear().
    gamePlayScene->removeItem(myPlayer);
    gamePlayScene->clear();

    //Change background image to level's appropriate image.
    gamePlayView->setBackgroundBrush(*level->getBgImage());


    viewRectX = 0;
    viewRectY = 0;
    gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);

    //Load Player onto Screen
    gamePlayScene->addItem(myPlayer);
    myPlayer->setX(WINDOW_MAX_X - 200);
    myPlayer->setY(WINDOW_MAX_Y);



    //Load Monsters

    cout << "Are there monsters to add?" << endl;
    for(int i = 0; i < level->getMonsters().size(); i++){
        cout << "There are " << i+1 << " monsters to add." << endl;
        gamePlayScene->addItem(level->getMonsters()[i]);

        //cout << qrand()%300 << endl;
        //cout << qrand()%300 << endl;

        int sceneWidth = gamePlayScene->width();
        cout << "sceneWidth = " << sceneWidth << endl;
        level->getMonsters()[i]->setX(qrand()%sceneWidth + 200); //These are arbitrary values for now.
        //cout << "Scene width: " << gamePlayScene->width() << endl;
        level->getMonsters()[i]->setY(qrand()%500);
    }

    scrollTimer->start();
    attackTimer->start();

    levelLoaded = true;
    cout << "Level loaded: " << levelPlaying << endl;

    return true;
}

void GamePlay::pauseGame(){
    //Launch some window too?
    if(!levelLoaded){
        return;
    }


    pauseMessage = new QGraphicsTextItem();
    QFont labelFont("Arial", 24, QFont::Bold);
    pauseMessage->setPlainText("Game Paused! \nPress ESC again to continue.");
    pauseMessage->setFont(labelFont);
    gamePlayScene->addItem(pauseMessage);
    gamePaused = true;
    scrollTimer->stop();
    attackTimer->stop();


    pauseMessage->setX(viewRectX);
    pauseMessage->setY(100);
    pauseMessage->setZValue(10); //I must set this high enough that it goes
                                 //on top of stuff!
    pauseMessage->show();
}
void GamePlay::unPauseGame(){
    if(!levelLoaded){
        return;
    }
    pauseMessage->hide();
    gamePaused = false;
    scrollTimer->start();
    attackTimer->start();
}

void GamePlay::movePlayer(MoveDirection dir){

    if (!myPlayer->isEnabled()){
        return;
    }
    if (!getLevelLoaded()){
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

    //cout << "ATTACK!! (" << myPoint.x() << ", " << myPoint.y() << ") " << endl;

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
bool GamePlay::getLevelLoaded(){
    return levelLoaded;
}
bool GamePlay::getGamePaused(){
    return gamePaused;
}
QGraphicsView* GamePlay::getGamePlayView(){
    return gamePlayView;
}
int GamePlay::getViewRectX(){
    return viewRectX;
}
int GamePlay::getViewRectY(){
    return viewRectY;
}

bool GamePlay::monsterCollision(){
    if(myPlayer->getInvincible()){
        return false;
    }
    for(int i = 0; i < myLevels[levelPlaying]->getMonsters().size(); i++){
        if (myPlayer->collidesWithItem(myLevels[levelPlaying]->getMonsters()[i])){


            //Apply collision damage to player.
            myPlayer->takeDamge(myLevels[levelPlaying]->getMonsters()[i]->getCollisionDamage());
            if(!myPlayer->getInvincible()){
                myPlayer->tempInvincible(15);
            }

            return true;
        }
    }
    return false;
}

bool GamePlay::attackCollision(){
    if(!getLevelLoaded()){
        return false;
    }
    for(int i = 0; i < myAttacks.size(); i++){
        for(int j = 0; j < myLevels[levelPlaying]->getMonsters().size(); j++){
            if(myAttacks[i]->collidesWithItem(myLevels[levelPlaying]->getMonsters()[j])){
                //cout << "Attack hit monster." << endl;

                myLevels[levelPlaying]->getMonsters()[j]->takeDamge(myAttacks[i]->getAttackDamage());

                //Check if this kills this monster
                if(myLevels[levelPlaying]->getMonsters()[j]->getHitPoints() <= 0){
                    gamePlayScene->removeItem(myLevels[levelPlaying]->getMonsters()[j]);
                    score += myLevels[levelPlaying]->getMonsters()[j]->getScoreVal();
                    delete myLevels[levelPlaying]->getMonsters()[j]; //Will this cause errors?
                    myLevels[levelPlaying]->getMonsters().remove(j);
                    return true;
                }

                if(!myLevels[levelPlaying]->getMonsters()[j]->getInvincible()){
                    myLevels[levelPlaying]->getMonsters()[j]->tempInvincible(2);
                }

                return true;
                //If I return here, that means an attack can only hit one
                //monster at a time. I must decide if this is desirable.
            }
        }
    }
    return false;
}


void GamePlay::mousePressEvent(QMouseEvent *e){
    if(!getLevelLoaded()){
        //Don't register attacks if a level isn't loaded.
        return;
    }
    if(getGamePaused()){
        //Don't register attacks if the game is paused.
        return;
    }
    if(e->button() == Qt::LeftButton){
        //cout << "Left Mouse Button pressed" << endl;
        this->clickAttack(e);
    }

}
/*---------------------------------------------
               Slot Definitions
----------------------------------------------*/

void GamePlay::scrollWindow(){
    //Is this necessary? I am not sure if I have fully solved the level
    //transition crash.
    if(!getLevelLoaded()){
        return;
    }

    //Will it make this game significantly slower to do this here?
    emit updateScore();

    if (viewRectX<= myLevels[levelPlaying]->getBgImage()->width() - WINDOW_MAX_X*2){
        viewRectX++;
        gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);

        //Check if player has run into a monster.
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

        //Check if any monsters are sustaining attacks.
        if(attackCollision()){
            //cout << "    ...will apply appropriate damage" << endl;
        }
    }
    else{

        //Once we reach the end of the map, then stop and display start menu for now.
        //displayStartMenu();

        emit updateScore();
        cout << "How do I only call levelCleared() once?" << endl;
        emit levelCleared();
    }
}

void GamePlay::animateAttacks(){
    //Will this be necessary?
    //I still need to deal with cooling down attacks between levels.
    if(!getLevelLoaded()){
        return;
    }

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
void GamePlay::animateMonsters(){
    //Write this so that monsters are animated via the scroll timer!
    //cout << "In animateMonsters!()" << endl;

   //Loop through monsters and call move() function on each.
    for(int j = 0; j < myLevels[levelPlaying]->getMonsters().size(); j++){
        myLevels[levelPlaying]->getMonsters()[j]->move();
    }
}

void GamePlay::launchGame(){
    if (levelLoaded){
        cout << "A level is already loaded." << endl;
        return;
    }
    cout << "Game launched." << endl;
    loadLevel(myLevels[levelPlaying]);
}

void GamePlay::gameOver(){

    scrollTimer->stop();
    attackTimer->stop();
    gamePaused = true;
    cout << "Game Over!" << endl;

}

void GamePlay::nextLevel(){
    cout << "...here I must do something to advance gameplay." << endl;

    //Add message or pause before proceeding?

    //Temporary!!
    if(levelPlaying < myLevels.size() - 1){

        //If there are more levels to play, play them!
        levelPlaying++;
        loadLevel(myLevels[levelPlaying]);
    }
    else{
        //Surely there is a better way to handle this? Splash screen?
        gameOver();
    }

}
