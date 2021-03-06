#include "soundargumentmonster.h"

SoundArgumentMonster::SoundArgumentMonster(){


    monsterImage->load("graphics/monsters/Sulfuric_Acid_Molecule_VdW.png");

    setPixmap(*monsterImage);
    hitPoints = 30;
    collisionDamage = 17;
    scoreVal = 7;

    //Use a random counter so that all these items aren't syncronized.
    int high = 100;
    int low = 0;
    moveCounter = qrand() % ((high + 1) - low) + low;;
    myDir = UP; //Monster will begin moving in a square starting with
                //the RIGHT direction (it will turn RIGHT to start.)

    monsterType = "SoundArgumentMonster";

}
SoundArgumentMonster::~SoundArgumentMonster(){


}

void SoundArgumentMonster::move(int x, int y){

    //I am not using player awareness for this item so to get rid of warnings:
    x = x; y = y;

    //Travel a fixed distance, and then turn if it is time.
    //I will use 100 as this fixed distance for now.
    if (moveCounter % 100 == 0){
        switch(myDir){
        case LEFT:
            myDir = UP;
            break;
        case UP:
            myDir = RIGHT;
            break;
        case RIGHT:
            myDir = DOWN;
            break;
        case DOWN:
            myDir = LEFT;
            break;
        default:
            ;
        }
    }

    //Now move.

    int travelLength = 1;
    if (moveClockwise){
        ; //Do nothing
    }
    else{
        travelLength *= -1;
    }

    switch(myDir){
    case LEFT:
        moveBy(-1*travelLength, 0);
        break;
    case UP:
        moveBy(0, travelLength);
        break;
    case RIGHT:
        moveBy(travelLength, 0);
        break;
    case DOWN:
        moveBy(0, -1*travelLength);
        break;
    default:
        ;
    }
    moveCounter++;
}
