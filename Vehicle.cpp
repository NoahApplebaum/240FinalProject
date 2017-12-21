#include "Vehicle.h"

// Constructors
/******************************************************************************/
Vehicle::Vehicle(int myType, int myDirection, int myArrival) {
	type = myType;
	direction = myDirection;
	arrival = myArrival;
	passes = 0;
}

/******************************************************************************/

// Getter Methods
/******************************************************************************/
int Vehicle::getType(){
	return type;
}

int Vehicle::getLength(){
	return type + 2;
}

int Vehicle::getDirection(){
	return direction;
}

int Vehicle::getArrival(){
	return arrival;
}

int Vehicle::getDeparture(){
	return departure;
}

int Vehicle::getPasses(){
	return passes;
}

void Vehicle::setDeparture(int time){
	departure = time;
}

void Vehicle::iteratePass(){
	passes += 1;
}
/******************************************************************************/