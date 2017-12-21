#include "Clock.h"

Clock::Clock(){
    currentTick = 0;
}

int Clock::getCurrentTicks(){
    return currentTick;
}

int Clock::tick(){
    currentTick += 1;
    return currentTick;
}

