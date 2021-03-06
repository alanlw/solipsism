
#include "meanwordsmonster.h"

MeanWordsMonster::MeanWordsMonster(){


    monsterImage->load("graphics/monsters/meanwords.png");

    setPixmap(*monsterImage);
    hitPoints = 10;
    collisionDamage = 5;
    scoreVal = 3;

    //Use a random counter so that all these items aren't syncronized.
    myDir = UP; //Monster will begin moving in a square starting with
                //the RIGHT direction (it will turn RIGHT to start.)

    monsterType = "MeanWordsMonster";

}
MeanWordsMonster::~MeanWordsMonster(){


}

void MeanWordsMonster::move(int x, int y){

    //I am not using player awareness for this item so to get rid of warnings:
    x = x; y = y;

    moveBy(-2, 0);
    moveCounter++;
}
