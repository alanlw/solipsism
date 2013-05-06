#ifndef DESPAIRMONSTER_H
#define DESPAIRMONSTER_H
#include "monster.h"
/**
    DespairMonsters follow the player and do continual damage as long
    as they are in contact with the player. They are destroyed by clicking
    just like any other monster.
  */
class DespairMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    DespairMonster();
    /** Destructor*/
    ~DespairMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes DespairMonster move in
        random cardinal directions about playing area. */
    void move(int x, int y);

protected:

private:

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;


};
#endif // DESPAIRMONSTER_H
