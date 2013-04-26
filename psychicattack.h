#ifndef PSYCHIC_ATTACK_H
#define PSYCHIC_ATTACK_H
#include "attack.h"

#include <QObject>
#include <QMouseEvent>

/**
    By clicking on certain monsters, the player can reduce these monster's
    health and eventually make them disappear. An animation of a rippling
    purple circles will represent this object.
  */
class PsychicAttack : public Attack{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    PsychicAttack();
    /** Destructor*/
    ~PsychicAttack();
protected:

private:

public slots:

};

#endif // PSYCHIC_ATTACK_H
