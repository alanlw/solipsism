#include "anxietymonster.h"

AnxietyMonster::AnxietyMonster(){


    if(monsterImage->load("graphics/monsters/anxiety.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*monsterImage);
    hitPoints = 30;
    collisionDamage = 7;
    scoreVal = 7;

    //Use a random counter so that all these items aren't syncronized.
    int high = 100;
    int low = 0;
    moveCounter = qrand() % ((high + 1) - low) + low;;
    myDir = UP; //Monster will begin moving in a square starting with
                //the RIGHT direction (it will turn RIGHT to start.)

}
AnxietyMonster::~AnxietyMonster(){


}

void AnxietyMonster::move(){

    int high = 10;
    int low = -10;
    int randX = qrand() % ((high + 1) - low) + low;
    int randY = qrand() % ((high + 1) - low) + low;
    moveBy(randX, randY);
    moveCounter++;
}
