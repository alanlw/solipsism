#include "attack.h"

Attack::Attack(){
    attackImage = new QPixmap();

    attackDuration = 10;
    attackCountDown = 0;
    attackDamage = 0;

}
Attack::~Attack(){

}
int Attack::getAttackDuration() const{
    return attackDuration;
}
int Attack::getAttackCountDown() const{
    return attackCountDown;
}
int Attack::getAttackDamage() const{
    return attackDamage;
}

void Attack::setAttackDuration(int n){
    attackDuration = n;
}

void Attack::setAttackCountDown(int n){
    attackCountDown = n;

}
void Attack::setAttackDamage(int n){
    attackDamage = n;
}
