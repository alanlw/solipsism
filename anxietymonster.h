#ifndef ANXIETYMONSTER_H
#define ANXIETYMONSTER_H

#include "monster.h"

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
    void move();

protected:

private:

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;

    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;

    MoveDirection myDir;

};
#endif // ANXIETYMONSTER_H
