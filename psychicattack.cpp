#include "psychicattack.h"
#include <iostream>

using namespace std; //to make cout statements more convenient.

PsychicAttack::PsychicAttack(){
    if(attackImage->load("graphics/attacks/psychic_attack.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
}
PsychicAttack::~PsychicAttack(){

}
