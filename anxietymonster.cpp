#include "anxietymonster.h"
#include "meanwordsmonster.h"

AnxietyMonster::AnxietyMonster(){

    QPixmap* temp = new QPixmap();
    temp->load("graphics/monsters/anxiety01.png");
    monsterImages.push_back(temp);
    temp = new QPixmap();
    temp->load("graphics/monsters/anxiety02.png");
    monsterImages.push_back(temp);
    temp = new QPixmap();
    temp->load("graphics/monsters/anxiety03.png");
    monsterImages.push_back(temp);

    setPixmap(*monsterImages[0]);
    hitPoints = 30;
    collisionDamage = 7;
    scoreVal = 7;

    //Use a random counter so that all these items aren't syncronized.
    int high = 100;
    int low = 0;
    moveCounter = qrand() % ((high + 1) - low) + low;;

    monsterType = "AnxietyMonster";

}
AnxietyMonster::~AnxietyMonster(){


}

void AnxietyMonster::move(int x, int y){

    //I am not using player awareness for this item so to get rid of warnings:
    x = x; y = y;

    setPixmap(*monsterImages[qrand()%3]);


    int high = 10;
    int low = -10;
    int randX = qrand() % ((high + 1) - low) + low;
    int randY = qrand() % ((high + 1) - low) + low;
    moveBy(randX, randY);

    //Keep within boundaries.
    //cout << "scenePos()" << scenePos().x() << ", " << scenePos().y() << endl;
    if(scenePos().y() < 50){
        moveBy(0, 10);
    }
    if(scenePos().y() >= 550){
        moveBy(0, -10);
    }


    moveCounter++;



}
