#include "depressionmonster.h"

DepressionMonster::DepressionMonster(){

    monsterImage->load("graphics/monsters/depression.png");

    setPixmap(*monsterImage);
    hitPoints = 30;
    collisionDamage = 25;
    scoreVal = 31;

    this->setOffset(-320, -200);
    monsterType = "DepressionMonster";

    setOpacity(0.5);

}
DepressionMonster::~DepressionMonster(){

}

void DepressionMonster::move(int x, int y){
		
		setOpacity(0.5);

    //cout << "In move with 2 parameters." << endl;
    if (x < 0){
        this->moveBy(2,0);
    }
    else if(x > 0){
        this->moveBy(-4, 0);
    }
    if (y < 0){
        this->moveBy(0,2);
    }
    else if (y > 0){
        this->moveBy(0, -2);
    }
}
