#ifndef SOUNDARGUMENTMONSTER_H
#define SOUNDARGUMENTMONSTER_H

#include "monster.h"
#include "gameplay.h"

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
    GamePlay* g_; //I need a pointer to the GamePlay object so I can
                  //move monster appropriately.

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;

    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;
    MoveDirection myDir;

};
#endif // SOUNDARGUMENTMONSTER_H
