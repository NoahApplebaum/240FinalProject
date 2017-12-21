// There are four of these

#ifndef __LIGHT__
#define __LIGHT__

#include <string>

class Light{

    protected:
        int greenTicks; // the number of ticks for a green light
        int yellowTicks; // the number of ticks for a yellow light
        int redTicks; // the number of ticks for a red light
        int lightColor; // 0 = red, 1 = yellow, 2 = green.
        int ticksLeft;

    public:

        // (De)Constructors
        Light();
        Light(int newGreenTicks, int newRedTicks, int startingLightColor);

        void setGreenTicks(int newGreenTicks);
        void setYellowTicks(int newYellowTicks); 
        void setRedTicks(int newRedTicks);
        void setLightColor(int newColor);
        void updateLightColor(); // updates the lightcolor if the ticksLeft go to zero
        void updateTicksLeft(); // updates the ticks left

        int getGreenTicks();
        int getYellowTicks();
        int getRedTicks();
        int getLightColor(); // returns either a 0,1,2.
        int getTicksLeft(); // returns how many yellow ticks are left
};
#endif