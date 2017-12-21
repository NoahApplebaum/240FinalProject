// This is the generic vehicle

#ifndef __VEHICLE__
#define __VEHICLE__

class Vehicle{

    protected:

        int passes;     // For use in determining intersection behavior
        int type;      // from 0 to 2: Car, SUV, Truck
        int direction; // from -1 to 1: Left, Straight, Right
        int arrival;   // clock tick when the segment was spawned
        int departure; // clock tick when the segment left

    public:
        
        // (De)Constructor Methods
        Vehicle(int myType, int myDirection, int myArrival);

        // Getter Methods
        int getType();
        int getLength();
        int getDirection();
        int getArrival();
        int getDeparture();
        int getPasses();

        // Setter Methods
        void setDeparture(int departure);

        //Other
        void iteratePass();
};

#endif