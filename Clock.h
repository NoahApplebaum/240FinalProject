#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <iostream>

class Clock{

protected:

    int currentTick;

public:

    Clock();

    int getCurrentTicks();
    int tick(); // iterates tick

};
#endif
