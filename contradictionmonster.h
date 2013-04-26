#ifndef CONTRADICTIONMONSTER_H
#define CONTRADICTIONMONSTER_H

#include "monster.h"

/**
    A Monster in this game.

    Contradictions are very robust and will take multiple attacks.
    to destroy. Contact with a Contradiction reduces hitpoints.
  */
class ContradictionMonster : public Monster{
public:
    /** Constructor*/
    ContradictionMonster();
    /** Destructor*/
    ~ContradictionMonster();

    /** Overloaded move function, makes this Monster not move at all*/
    void move();

protected:

private:
};

#endif // CONTRADICTIONMONSTER_H
