#ifndef MEANWORDSMONSTER_H
#define MEANWORDSMONSTER_H

#include "monster.h"
#include <QGraphicsTextItem>

/**
    Mean words are attacks launched by AnxietyMonsters.
 */
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
    void move(int x=0, int y=0);

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
