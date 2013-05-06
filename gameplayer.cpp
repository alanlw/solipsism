#include "gameplayer.h"

#define DEFAULT_HITPOINTS 100
GamePlayer::GamePlayer(){
    playerImage = new QPixmap();
    playerImage->load("graphics/player/brain_in_vat.png");
    setPixmap(*playerImage);
    playerImage->scaledToWidth(100);

    setOffset(-75, -65);

    lives = 3;
    hitPoints = DEFAULT_HITPOINTS;
    collisionDamage = 5;

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
int GamePlayer::getCollisionDamage() const{
    return collisionDamage;
}
void GamePlayer::takeDamge(int n){
    if(!invincible){
        hitPoints -= n;
    }
    if (hitPoints <= 0){
        lives--;
        emit lifeLost();

        if (lives <= 0){
            emit allLivesLost();
            //this->setEnabled(false);
            return;
        }

        setHitPoints(DEFAULT_HITPOINTS);


    }


}
void GamePlayer::tempInvincible(int numCycles){
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
}
