#include "monster.h"

Monster::Monster(){

    monsterImage = new QPixmap();
    alive = true;
    hitPoints = 1;
    collisionDamage = 0;
}
Monster::~Monster(){

}
int Monster::getCollisionDamage() const{
    return collisionDamage;
}
