#ifndef DEPRESSIONMONSTER_H
#define DEPRESSIONMONSTER_H
#include "monster.h"
/**
    DepressionMonsters follow the player and do continual damage as long
    as they are in contact with the player. They are destroyed by clicking
    just like any other monster.
  */
class DepressionMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    DepressionMonster();
    /** Destructor*/
    ~DepressionMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes DepressionMonster move in
        random cardinal directions about playing area. */
    void move();

protected:

private:

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;

    MoveDirection myDir;

};
#endif // DEPRESSIONMONSTER_H
