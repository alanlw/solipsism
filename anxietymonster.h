#ifndef ANXIETYMONSTER_H
#define ANXIETYMONSTER_H

#include "monster.h"

/**
    Anxieties move randomly about the map. If they collide with an
    Contradiction Monster, they die. Can be destroyed by player. Anxieties
    generate Mean Words.
  */
class AnxietyMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    AnxietyMonster();
    /** Destructor*/
    ~AnxietyMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes AnxietyMonster move in
        random cardinal directions about playing area. */
    void move(int x, int y);

protected:

private:


    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;


};
#endif // ANXIETYMONSTER_H
