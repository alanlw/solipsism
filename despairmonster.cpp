#include "despairmonster.h"



DespairMonster::DespairMonster(){

    monsterImage->load("graphics/monsters/despair01.png");

    setPixmap(*monsterImage);
    hitPoints = 1;
    collisionDamage = 35;
    scoreVal = 21;

    monsterType = "DespairMonster";

    this->setOffset(-30, -30);

}
DespairMonster::~DespairMonster(){

}

void DespairMonster::move(int x, int y){
    //cout << "In move with 2 parameters." << endl;
    if (x < 0){
        this->moveBy(3,0);
    }
    else if(x > 0){
        this->moveBy(-3, 0);
    }
    if (y < 0){
        this->moveBy(0,3);
    }
    else if (y > 0){
        this->moveBy(0, -3);
    }
}
