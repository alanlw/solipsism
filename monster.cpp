#include "monster.h"

Monster::Monster(){

    monsterImage = new QPixmap();
    alive = true;
    hitPoints = 1;
    collisionDamage = 0;
    scoreVal = 0;

    //Monster is born mortal
    invincible = 0;

    monsterTimer = new QTimer();
    monsterTimer->setInterval(100);

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
void Monster::takeDamge(int n){
    if(!invincible){
        hitPoints -= n;
    }
    if (hitPoints <= 0){
        //Perform operations here to kill monster, remove from
        //the array of the living, etc.

        this->hide();
    }


}
void Monster::tempInvincible(int numCycles){
    //cout << "In tempInvincible" << endl;
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
    //cout << invincible << endl;
}
