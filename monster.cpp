#include "monster.h"

Monster::Monster(){

    monsterImage = new QPixmap();
    alive = true;
    hitPoints = 1;
    collisionDamage = 0;
    scoreVal = 0;

    //Monster is born mortal
    invincible = 0;

    monsterType = "Monster";

    monsterTimer = new QTimer();
    monsterTimer->setInterval(100);
    moveCounter = 0;

    connect(monsterTimer, SIGNAL(timeout()), this, SLOT(reduceInvincible()));
}
Monster::~Monster(){

}
int Monster::getHitPoints() const{
    return hitPoints;
}
int Monster::getCollisionDamage() const{
    return collisionDamage;
}
int Monster::getScoreVal() const{
    return scoreVal;
}
int Monster::getInvincible() const{
    return invincible;
}
string Monster::getMonsterType() const{
    return monsterType;
}
int Monster::getMoveCounter(){
    return moveCounter;
}

void Monster::takeDamage(int n){
    if(!invincible){
        hitPoints -= n;
    }


}
void Monster::tempInvincible(int numCycles){
    invincible = numCycles;
    this->setOpacity(0.5);
    monsterTimer->start();
}

void Monster::reduceInvincible(){
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
        monsterTimer->stop();
        this->setOpacity(1.0);
    }
}
void Monster::move(){
    moveCounter++;
}
