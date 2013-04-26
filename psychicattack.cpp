#include "psychicattack.h"
#include <iostream>

using namespace std; //to make cout statements more convenient.

PsychicAttack::PsychicAttack(){

    attackDuration = 10;

    attackImage->load("graphics/attacks/psychic_attack.png");



    setPixmap(*attackImage);

    attackDamage = 10;
}
PsychicAttack::~PsychicAttack(){

}
