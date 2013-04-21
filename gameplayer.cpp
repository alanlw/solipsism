#include "gameplayer.h"

GamePlayer::GamePlayer(){
    playerImage = new QPixmap();
    if(playerImage->load("graphics/player/brain_in_vat.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*playerImage);
    playerImage->scaledToWidth(100);

    lives = 3;
    hitPoints = 100;

    //Player is born mortal.
    invincible = 0;

    playerTimer = new QTimer();
    playerTimer->setInterval(100);

    connect(playerTimer, SIGNAL(timeout()), this, SLOT(reduceInvincible()));
}
GamePlayer::~GamePlayer(){

}

int GamePlayer::getLives() const{
    return lives;
}

int GamePlayer::getHitPoints() const{
    return hitPoints;
}

int GamePlayer::getInvincible() const{
    return invincible;
}
void GamePlayer::takeDamge(int n){
    if(!invincible){
        hitPoints -= n;
    }

}
void GamePlayer::tempInvincible(int numCycles){
    //cout << "In tempInvincible" << endl;
    invincible = numCycles;
    this->setOpacity(0.5);
    playerTimer->start();
}

void GamePlayer::setLives(int n){
    lives = n;
}
void GamePlayer::setHitPoints(int n){
    hitPoints = n;
}

void GamePlayer::reduceInvincible(){
    if(invincible > 0){
        invincible--;
        //Blinking effect.
        if(invincible % 2 == 0){
            this->setOpacity(0.5);
        }
        else{
            this->setOpacity(1.0);
        }
    }
    else{
        playerTimer->stop();
        this->setOpacity(1.0);
    }
    //cout << invincible << endl;
}
