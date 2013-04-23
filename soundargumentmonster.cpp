#include "soundargumentmonster.h"
#include "gameplay.h"

SoundArgumentMonster::SoundArgumentMonster(){
    if(monsterImage->load("graphics/monsters/Sulfuric_Acid_Molecule_VdW.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*monsterImage);
    hitPoints = 30;
    collisionDamage = 7;
    scoreVal = 7;

    moveCounter = 0;
}
SoundArgumentMonster::~SoundArgumentMonster(){

}

void SoundArgumentMonster::move(){
    //Move monster appropriately. First find a direction to move in.
    MoveDirection toMove;
    //qrand() % ((high + 1) - low) + low;
    int toMoveInt = (qrand() % ((4 + 1) - 1) + 1);
    switch(toMoveInt){
    case 1:
        toMove = UP;
        break;
    case 2:
        toMove = LEFT;
        break;
    case 3:
        toMove = DOWN;
        break;
    case 4:
        toMove = RIGHT;
        break;
    default:
        toMove = NONE;
        break;
    }

    switch(toMove){
    case UP:
        break;
    case LEFT:
        break;
    case DOWN:
        break;
    case RIGHT:
        break;
    default:
        return;
    }

    /* I will need to find the conditions necessary to make sure this
       monster does not go too far out of the scene.

    switch(toMove){
    case UP:
        if(myPlayer->y() - 10 >= 0 ){
            myPlayer->moveBy(0, -10);
        }
        break;
    case LEFT:
        if(myPlayer->x() >= viewRectX){
            myPlayer->moveBy(-10,0);
        }
        break;
    case DOWN:
        if(myPlayer->y() + 10 <= 460){
            myPlayer->moveBy(0, 10);
        }
        break;
    case RIGHT:
        if(myPlayer->x() <= viewRectX+WINDOW_MAX_X*2 - 150){
            myPlayer->moveBy(10,0);
        }
        break;
    default:
        return;
    }
    */

}
