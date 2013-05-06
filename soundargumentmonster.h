#ifndef SOUNDARGUMENTMONSTER_H
#define SOUNDARGUMENTMONSTER_H

#include "monster.h"

/**
    Sound Arguments move in clockwise square formations triggered at fixed
    intervals by a timer. Contact with a player will reduce player health.
    Can be destroyed by player.
  */
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
    void move(int x, int y);

protected:

private:

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;

    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;

    MoveDirection myDir;

};
#endif // SOUNDARGUMENTMONSTER_H
