#ifndef __NAMED_QUEUE__
#define __NAMED_QUEUE__

#include <queue>
#include <string>
#include "Vehicle.h"

class NamedQueue{
    public:
        void setName(std::string myName);
        std::queue<Vehicle*> queue;
        std::string name;
};
#endif
