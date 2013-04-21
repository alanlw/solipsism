#include "psychicattack.h"
#include <iostream>

using namespace std; //to make cout statements more convenient.

PsychicAttack::PsychicAttack(){
    cout << "In PsychicAttack constructor beginning" << endl;

    if(attackImage->load("graphics/attacks/psychic_attack.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }


    setPixmap(*attackImage);
    cout << "In PsychicAttack constructor end" << endl;
}
PsychicAttack::~PsychicAttack(){

}
