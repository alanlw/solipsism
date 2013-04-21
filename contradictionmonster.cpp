#include "contradictionmonster.h"

ContradictionMonster::ContradictionMonster(){
    if(monsterImage->load("graphics/monsters/contradiction.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*monsterImage);
    hitPoints = 2;

}
ContradictionMonster::~ContradictionMonster(){

}
