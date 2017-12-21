#include "Light.h"

Light::Light(){
    greenTicks = 0;
    yellowTicks = 0;
    redTicks = 0;
    lightColor = 0;
    ticksLeft = 0;
}

Light::Light(int newGreenTicks, int newRedTicks, int startingLightColor){

    greenTicks = newGreenTicks;
    if (newGreenTicks > newRedTicks) {
    	yellowTicks = newGreenTicks - newRedTicks;
    }
    else {
    	yellowTicks = newRedTicks - newGreenTicks;
    }
    redTicks = newRedTicks;
    lightColor = startingLightColor;
    if (startingLightColor == 0) {
    	ticksLeft = redTicks;
    }
    else if (startingLightColor == 1) {
    	ticksLeft = yellowTicks;
    }
    else {
    	ticksLeft = greenTicks;
    }
}

void Light::setGreenTicks(int newGreenTicks) {
	greenTicks = newGreenTicks;
}

void Light::setYellowTicks(int newYellowTicks) {
	yellowTicks = newYellowTicks;
}

void Light::setRedTicks(int newRedTicks) {
	redTicks = newRedTicks;
}

void Light::setLightColor(int newColor) {
	lightColor = newColor;
}

void Light::updateLightColor(){
	
	// If the ticksLeft go to 0, we switch light
    if (ticksLeft == 0) {
    	lightColor = (lightColor+2) % 3;
    	if (lightColor == 0) {
    		ticksLeft = redTicks;
    	}
    	if (lightColor == 1) {
    		ticksLeft = yellowTicks;
    	}
    	if (lightColor == 2) {
    		ticksLeft = greenTicks;
    	}
    }
}

void Light::updateTicksLeft(){
   	ticksLeft -= 1;
}


int Light::getGreenTicks() {
	return greenTicks;
}

int Light::getYellowTicks() {
	return yellowTicks;
}

int Light::getRedTicks() {
	return redTicks;
}

int Light::getLightColor(){
    return lightColor;
}

int Light::getTicksLeft(){
    return ticksLeft;
}