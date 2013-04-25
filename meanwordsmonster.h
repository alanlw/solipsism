#ifndef MEANWORDSMONSTER_H
#define MEANWORDSMONSTER_H

#include "monster.h"
#include <QGraphicsTextItem>

class MeanWordsMonster : public Monster{
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    MeanWordsMonster();
    /** Destructor*/
    ~MeanWordsMonster();

    //=========================================================================
    // Animation Functions
    //=========================================================================
    /** Overloaded move() function. Makes MeanWordsMonster move in
        random cardinal directions about playing area. */
    void move();

    //=======================================================================
    // Accessor and Mutator Functions
    //=======================================================================

protected:

private:

    /** Counting so that I can move monster and change direction
        intentionally.*/
    int moveCounter;

    /** Is this Monster moving in the clockwise direction?*/
    bool moveClockwise;

    MoveDirection myDir;

};

#endif // MEANWORDSMONSTER_H
