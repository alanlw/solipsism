#include "gameplay.h"
#include <qapplication.h>
#include <QGraphicsTextItem> //For pauses messages, etc.
#include <QTime>

#define STARTING_SCROLLTIMER_INTERVAL 20


GamePlay::GamePlay(QWidget *parent) : QWidget(parent){


    //setFocus();
    //cout << "Has focus? " << hasFocus() << endl;
    populateLevels();

    //We need a scene and a view to do graphics in QT
    gamePlayScene = new QGraphicsScene(this);
    gamePlayView = new QGraphicsView( gamePlayScene, this );



    levelLoaded = false;
    viewRectX = 0;
    viewRectY = 0;
    gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);


    //Welcoming Screen to Game
    QPixmap * welcome = new QPixmap;
    if(welcome->load("graphics/menus/welcome.png")){
        cout << "success..." << endl;
    }
    else{
        cout << "failed." << endl;
    }
    gamePlayView->setBackgroundBrush(*welcome);



    myPlayer = new GamePlayer();
    gamePlayScene->addItem(myPlayer);
    myPlayer->hide();

    //Load Player onto Screen
    //gamePlayScene->addItem(myPlayer);

    //myPlayer->setX(WINDOW_MAX_X - 200);
    //myPlayer->setY(WINDOW_MAX_Y);
    gamePaused = true; //So I can't just move around the player to start.

    connect(this, SIGNAL(levelCleared()), this, SLOT(nextLevel()));

    /**Start on level 0*/
    levelPlaying = 0;

    //myLevel = NULL;


    /**************************************************************************
      gamePlayScene
      ************************************************************************/

    gamePlayView->setWindowTitle( "Side Scroller Game");
    

    //Set timer for animation.
    scrollTimer = new QTimer(this);
    scrollTimer->setInterval(STARTING_SCROLLTIMER_INTERVAL); //We will reduce this which each level...

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

void GamePlay::populateLevels(){
    //=========================================================================
    //This is temporary, I need to think of a better way to store/access/etc.
    //level data.
    //
    //Load my level
    GameLevel * temp = new GameLevel("level01.jpg");
    for (int n = 0; n < 10; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        temp->getMonsters().push_back(myContradiction);
    }
    for (int n = 0; n < 15; n++){
        SoundArgumentMonster* mySoundArgument = new SoundArgumentMonster();
        temp->getMonsters().push_back(mySoundArgument);
    }
    for (int n = 0; n < 5; n++){
        AnxietyMonster* myAnxiety = new AnxietyMonster();
        temp->getMonsters().push_back(myAnxiety);
    }
    myLevels.push_back(temp);
    cout << "Level 0 Loaded." << endl;


    temp = NULL;
    temp = new GameLevel("level02.jpg");

    for (int n = 0; n < 15; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        temp->getMonsters().push_back(myContradiction);
    }
    for (int n = 0; n < 20; n++){
        SoundArgumentMonster* mySoundArgument = new SoundArgumentMonster();
        temp->getMonsters().push_back(mySoundArgument);
    }
    for (int n = 0; n < 7; n++){
        AnxietyMonster* myAnxiety = new AnxietyMonster();
        temp->getMonsters().push_back(myAnxiety);
    }
    myLevels.push_back(temp);
    cout << "Level 1 Loaded." << endl;

    temp = NULL;
    temp = new GameLevel("level03.jpg");
    //myLevel = new GameLevel("sample_map03.jpg");

    for (int n = 0; n < 25; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        temp->getMonsters().push_back(myContradiction);
    }
    for (int n = 0; n < 25; n++){
        SoundArgumentMonster* mySoundArgument = new SoundArgumentMonster();
        temp->getMonsters().push_back(mySoundArgument);
    }
    for (int n = 0; n < 15; n++){
        AnxietyMonster* myAnxiety = new AnxietyMonster();
        temp->getMonsters().push_back(myAnxiety);
    }
    myLevels.push_back(temp);
    cout << "Level 2 Loaded." << endl;

    //=========================================================================

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

    //For random numbers.
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    //Set levelLoaded to false until we finish loading content.
    levelLoaded = false;

    if(level == NULL){
        return false;
    }
    //I must remove the player here so the player isn't deleted when I call
    //clear()
    myPlayer->show();
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

        //int sceneWidth = gamePlayScene->width();
        int sceneWidth = level->getBgImage()->width();
        cout << "sceneWidth = " << sceneWidth << endl;
        //cout << "sceneWidth = " << sceneWidth << endl;
        do{
            level->getMonsters()[i]->setX(qrand()%sceneWidth); //These are arbitrary values for now.
        } while(level->getMonsters()[i]->x() >= sceneWidth - 200 ||
                level->getMonsters()[i]->x() < 400);
        cout << level->getMonsters()[i]->x() << endl;


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

bool GamePlay::attackCollision(){
    if(!getLevelLoaded()){
        return false;
    }
    for(int i = 0; i < myAttacks.size(); i++){
        for(int j = 0; j < myLevel->getMonsters().size(); j++){
            if(myAttacks[i]->collidesWithItem(myLevel->getMonsters()[j])){
                //cout << "Attack hit monster." << endl;

                myLevel->getMonsters()[j]->takeDamage(myAttacks[i]->getAttackDamage());

                //Check if this kills this monster
                if(myLevel->getMonsters()[j]->getHitPoints() <= 0){
                    gamePlayScene->removeItem(myLevel->getMonsters()[j]);
                    score += myLevel->getMonsters()[j]->getScoreVal();
                    delete myLevel->getMonsters()[j]; //Will this cause errors?
                    myLevel->getMonsters().remove(j);
                    return true;
                }

                if(!myLevel->getMonsters()[j]->getInvincible()){
                    myLevel->getMonsters()[j]->tempInvincible(2);
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

    //Will it make this game significantly slower to do this here?
    emit updateScore();

    if (viewRectX<= myLevel->getBgImage()->width() - WINDOW_MAX_X*2){
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
        //Clear all attacks to prevent errors.
        for(int i = 0; i < myAttacks.size(); i++){
            gamePlayScene->removeItem(myAttacks[i]);

            delete myAttacks[i];
            myAttacks.remove(i);
        }
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
    if(!getLevelLoaded()){
        return;
    }
    //Write this so that monsters are animated via the scroll timer!
    //cout << "In animateMonsters!()" << endl;

   //Loop through monsters and call move() function on each.
    for(int j = 0; j < myLevel->getMonsters().size(); j++){
        myLevel->getMonsters()[j]->move();

        //Generate Attacks
        if(myLevel->getMonsters()[j]->getMonsterType() == "AnxietyMonster"
                && myLevel->getMonsters()[j]->x() - myPlayer->x() < 550){
            //cout << "Launch attack!" << endl;
            //cout << myLevel->getMonsters()[j]->getMoveCounter() << endl;
            if(myLevel->getMonsters()[j]->getMoveCounter() % 100 == 0){

                //cout << myLevel->getMonsters()[j]->getMoveCounter() << endl;

                MeanWordsMonster * temp = new MeanWordsMonster();
                temp->setPos(myLevel->getMonsters()[j]->pos());
                temp->setZValue(1);
                temp->setX(temp->x() - 60);
                gamePlayScene->addItem(temp);
                myLevel->getMonsters().push_back(temp);

            }
        }

    }
}


void GamePlay::launchGame(){
    if (levelLoaded){
        cout << "A level is already loaded." << endl;
        cout << "Restarting game by reloading first level." << endl;

        GamePlayer* tempPlayer = myPlayer;
        myPlayer = new GamePlayer();
        delete tempPlayer;

        score = 0;

        scrollTimer->setInterval(STARTING_SCROLLTIMER_INTERVAL);

        GameLevel* temp = new GameLevel();
        loadLevel(temp);
        for(int i = 0; i < myLevels.size(); i++){
            delete myLevels[i];
        }
        myLevels.clear();
        populateLevels();
        myLevel = myLevels[0];
        loadLevel(myLevel);
        delete temp;
        return;
    }
    cout << "Game launched." << endl;
    cout << myLevels.size() << endl;
    myLevel = myLevels[0];
    loadLevel(myLevel);
}

void GamePlay::gameOver(){

    emit updateScore();
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
        myLevel = myLevels[levelPlaying];


        for(int i = 0; i < myAttacks.size(); i++){
            gamePlayScene->removeItem(myAttacks[i]);
            //Is it unwise to delete here?
            delete myAttacks[i];
            myAttacks.remove(i);

        }
        //Speed up timer.
        if(!scrollTimer->interval() <= 10){
            scrollTimer->setInterval(scrollTimer->interval() * (2.0/3.0));
        }

        loadLevel(myLevel);
    }
    else{
        //Surely there is a better way to handle this? Splash screen?
        gameOver();
    }

}
