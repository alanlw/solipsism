#ifndef CONTRADICTIONMONSTER_H
#define CONTRADICTIONMONSTER_H

#include "monster.h"

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
