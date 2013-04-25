#include "contradictionmonster.h"

ContradictionMonster::ContradictionMonster(){
    if(monsterImage->load("graphics/monsters/contradiction.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*monsterImage);
    hitPoints = 50;
    collisionDamage = 50;
    scoreVal = 10;

    monsterType = "ContradictionMonster";
}
ContradictionMonster::~ContradictionMonster(){
    //Anything needed that is not already done in Monster?
}

void ContradictionMonster::move(){

}
