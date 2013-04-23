#ifndef SOUNDARGUMENTMONSTER_H
#define SOUNDARGUMENTMONSTER_H

#include "monster.h"

class SoundArgumentMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    SoundArgumentMonster();
    /** Destructor*/
    ~SoundArgumentMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes SoundArgumentMonster move in
        random cardinal directions about playing area. */
    void move();

protected:

private:
    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;


};
#endif // SOUNDARGUMENTMONSTER_H
