#include "contradictionmonster.h"

ContradictionMonster::ContradictionMonster(){
    monsterImage->load("graphics/monsters/contradiction.png");

    setPixmap(*monsterImage);
    hitPoints = 50;
    collisionDamage = 50;
    scoreVal = 10;

    monsterType = "ContradictionMonster";
}
ContradictionMonster::~ContradictionMonster(){
}
void ContradictionMonster::move(){

}
