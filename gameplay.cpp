#include "gameplay.h"
#include <qapplication.h>
#include <QGraphicsTextItem> //For pauses messages, etc.
#include <QTime>
#include <QInputDialog>
#include <QDir>
#include <QLineEdit>
#include <QMessageBox>

#define STARTING_SCROLLTIMER_INTERVAL 20


GamePlay::GamePlay(QWidget *parent) : QWidget(parent){

    //QInput Dialog to get player's name
    bool ok;
    do {
        playerName = QInputDialog::getText(this, tr("Player Sign-in: "),
                                             tr("Enter your name (no spaces please): "), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);

        if(playerName.contains(" ")){
            ok = false;
            continue;
        }
    }while (!(ok && !playerName.isEmpty()));

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
    welcome->load("graphics/menus/welcome.png");

    gamePlayView->setBackgroundBrush(*welcome);


    //Load Player onto Screen
    myPlayer = new GamePlayer();
    gamePlayScene->addItem(myPlayer);
    myPlayer->hide();

    /**Start on level 0*/
    levelPlaying = 0;



    //=========================================================================
    //  gamePlayScene
    //=========================================================================

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

    //For advancing levels
    connect(this, SIGNAL(levelCleared()), this, SLOT(nextLevel()));

    levelLoaded = false; //No level loaded at the start.
    gamePaused = false; //Game does not begin 'paused', but rather unloaded.

    score = 0; //Player's score starts at 0.

    show();
}

void GamePlay::populateLevels(){



    //=========================================================================
    //Load my levels
    //=========================================================================

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
    for (int n = 0; n < 2; n++){
        DepressionMonster* myDepression = new DepressionMonster();
        temp->getMonsters().push_back(myDepression);
    }
    myLevels.push_back(temp);


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

    temp = NULL;
    temp = new GameLevel("level03.jpg");

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

    temp = NULL;
    temp = new GameLevel("sample_map03.jpg");

    for (int n = 0; n < 40; n++){
        ContradictionMonster* myContradiction = new ContradictionMonster();
        temp->getMonsters().push_back(myContradiction);
    }
    for (int n = 0; n < 30; n++){
        SoundArgumentMonster* mySoundArgument = new SoundArgumentMonster();
        temp->getMonsters().push_back(mySoundArgument);
    }
    for (int n = 0; n < 30; n++){
        AnxietyMonster* myAnxiety = new AnxietyMonster();
        temp->getMonsters().push_back(myAnxiety);
    }
    myLevels.push_back(temp);

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

    emit nameEntered();

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

    if(myPlayer != NULL){
        gamePlayScene->removeItem(myPlayer);
    }

    gamePlayScene->clear();

    //Change background image to level's appropriate image.
    gamePlayView->setBackgroundBrush(*level->getBgImage());


    viewRectX = 0;
    viewRectY = 0;
    gamePlayView->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);

    //Load Player onto Screen
    gamePlayScene->addItem(myPlayer);
    myPlayer->show();
    myPlayer->setX(WINDOW_MAX_X - 200);
    myPlayer->setY(WINDOW_MAX_Y);


    //Load Monsters

    for(int i = 0; i < level->getMonsters().size(); i++){
        //cout << "There are " << i+1 << " monsters to add." << endl;
        gamePlayScene->addItem(level->getMonsters()[i]);
        int sceneWidth = level->getBgImage()->width();
        do{
            level->getMonsters()[i]->setX(qrand()%sceneWidth);
        } while(level->getMonsters()[i]->x() >= sceneWidth - 200 ||
                level->getMonsters()[i]->x() < 400);

        level->getMonsters()[i]->setY(qrand()%500);
    }

    scrollTimer->start();
    attackTimer->start();

    levelLoaded = true;

    return true;
}

void GamePlay::pauseGame(){
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
        return;
    }

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
QString GamePlay::getPlayerName(){
    return playerName;
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
        emit levelCleared();
    }
}

void GamePlay::animateAttacks(){
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

   //Loop through monsters and call move() function on each.
    for(int j = 0; j < myLevel->getMonsters().size(); j++){
        myLevel->getMonsters()[j]->move();

        //Generate Attacks
        if(myLevel->getMonsters()[j]->getMonsterType() == "AnxietyMonster"
                && myLevel->getMonsters()[j]->x() - myPlayer->x() < 550){
            if(myLevel->getMonsters()[j]->getMoveCounter() % 100 == 0){

                MeanWordsMonster * temp = new MeanWordsMonster();
                temp->setPos(myLevel->getMonsters()[j]->pos());
                temp->setZValue(1);
                temp->setX(temp->x() - 60);
                gamePlayScene->addItem(temp);
                myLevel->getMonsters().push_back(temp);

            }
        }
        if(myLevel->getMonsters()[j]->getMonsterType() == "DepressionMonster"
                && myLevel->getMonsters()[j]->x() - myPlayer->x() < 900){
            //Send proper information so I can move this monster toward the player.
            int x = (myLevel->getMonsters()[j]->x() - myPlayer->x());
            int y = (myLevel->getMonsters()[j]->y() - myPlayer->y());
            cout << "DepressionMonster in view" << endl;
            myLevel->getMonsters()[j]->move(x, y);
        }

    }
}


void GamePlay::launchGame(){
    if (levelLoaded){
        cout << "A level is already loaded." << endl;
        cout << "Restarting game by reloading first level." << endl;

        gamePaused =false;

        score = 0;
        myPlayer->setLives(3);
        myPlayer->setHitPoints(100);

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
    myLevel = myLevels[0];
    loadLevel(myLevel);
}

void GamePlay::gameOver(){

    emit updateScore();
    scrollTimer->stop();
    attackTimer->stop();
    gamePaused = true;

    emit addScore();

    QString message = "For with much wisdom comes much sorrow;\n the more knowledge, the more grief.";
    message+="\n\nPress 'Start Game' again to restart, or 'Quit' to quit.";
    QMessageBox::warning(this,"Game Over!", message, QMessageBox::Ok);
    cout << "Game Over!" << endl;


}

void GamePlay::nextLevel(){
    if(levelPlaying < myLevels.size() - 1){

        //If there are more levels to play, play them!
        levelPlaying++;
        myLevel = myLevels[levelPlaying];


        for(int i = 0; i < myAttacks.size(); i++){
            gamePlayScene->removeItem(myAttacks[i]);
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
        gameOver();
    }

}
