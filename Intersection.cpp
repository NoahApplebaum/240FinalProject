#include "Intersection.h"

Intersection::Intersection(double myProbRight, double myProbLeft,
    double myProbStraight, double myProbVehicle, double myProbCar,
    double myProbSUV, double myProbTruck){
        probRight = myProbRight;
        probLeft = myProbLeft;
        probStraight = myProbStraight;
        probVehicle = myProbVehicle;
        probCar = myProbCar;
        probSUV = myProbSUV;
        probTruck = myProbTruck;

        A1.setName("A1");
        A2.setName("A2");
        A3.setName("A3");
        A4.setName("A4");

        B1.setName("B1");
        B2.setName("B2");
        B3.setName("B3");
        B4.setName("B4");

        T1.setName("T1");
        T2.setName("T2");
        T3.setName("T3");
        T4.setName("T4");
    }

void Intersection::spawnVehicle(NamedQueue myQueue){

    // this will be the user input possibility			
	  double proA = probCar;
	  double proB = probSUV;
	  double proC = probTruck;

	  // scale them because I don't know how to generate doubles
	  int intProA = (int)(proA * 100);
	  int intProB = (int)(proB * 100);
	  int intProC = (int)(proC * 100);
	  std::cout << intProA << std::endl;
	  std::cout << intProB << std::endl;
	  std::cout << intProC << std::endl;

	  // first one is the randome number from 0 to 100, the second one is what type of car to gen
	  int carRanNum = 0;	
      int carToGen = 0;

      for (int i = 0; i < 100; i++) {
      	
      	std::cout << carRanNum << std::endl;

      	if ( 0 <= carRanNum && carRanNum < intProA) {
      		carToGen = 0;
      	}
      	else if (intProA <= carRanNum && carRanNum < intProA+intProB) {
      		carToGen = 1;
      	}
      	else {
      		carToGen = 2;
      	}
      	std::cout << carToGen << std::endl;
      }

    // Make a new vehicle
    Vehicle newVehicle(carToGen,1,0); // needs proper args based on Random class and these chances

    // Add the vehicles pointers
    for(int i = 0; i < newVehicle.getLength(); i++){ // put # of ptrs = length
        myQueue.queue.push(&newVehicle); // not 100% sure, but think this is correct
    }
}

bool Intersection::generateArrival(NamedQueue myQueue){
    
    
    // do a random thing
    
    //if random results in NULL
        //add a null ptr to myQueue.queue

    //Else generate a vehicle
        // spawnVehicle(myQueue.queue)

    if(false){ // Random chance to make vehicle goes here
        spawnVehicle(myQueue);
        return true;
    }else{
        // Add a null pointer
        myQueue.queue.push(NULL);
        return false;
    }

    
}

bool Intersection::movePointer(NamedQueue A, NamedQueue B){
    if(A.queue.front() != NULL){
        A.queue.front()->iteratePass(); // Make passes = passes + 1
        B.queue.push(A.queue.front()); // Take front of A and push it to B
        A.queue.pop(); // Remove front of A
        return true;
    }else{
        // It was a NULL
        A.queue.pop(); // Kill it
        return false;
    }
}

void Intersection::tick(){
    // Generate Arrivals
    generateArrival(A1);
    std::cout << "Generated arrival for " << A1.name << std::endl;
    generateArrival(A2);
    std::cout << "Generated arrival for " << A2.name << std::endl;
    generateArrival(A3);
    std::cout << "Generated arrival for " << A3.name << std::endl;
    generateArrival(A4);
    std::cout << "Generated arrival for " << A4.name << std::endl;

    // Update lights (unsure if this is needed)
    // so this is a temp thing
    lightNS.setLightColor(0); // Red
    lightEW.setLightColor(2); // Green

    // Attempt to move all lanes
    std::cout << "Attempt to go from " << A1.name << std::endl;
    go(A1);
    std::cout << "Attempt to go from " << A2.name << std::endl;
    go(A2);
    std::cout << "Attempt to go from " << A3.name << std::endl;
    go(A3);
    std::cout << "Attempt to go from " << A4.name << std::endl;
    go(A4);

    std::cout << "Attempt to go from " << T1.name << std::endl;
    go(T1);
    std::cout << "Attempt to go from " << T2.name << std::endl;
    go(T2);
    std::cout << "Attempt to go from " << T3.name << std::endl;
    go(T3);
    std::cout << "Attempt to go from " << T4.name << std::endl;
    go(T4);
}

bool Intersection::go(NamedQueue myQueue){
    std::cout << "Go called on " << myQueue.name << std::endl;
    // Needs to check what the lane is
        // if lane is A1 or A3 (I think...) check EW light
        // if lane is A2 or A4 check NS light
            // then go into the intersection T# as appropriate

        // If it's one of the T lanes check the car's direction and make the
        // proper turn

        // We don't use this method on the B lanes since they just stack up
        // and hold our cars for examining at the end


    // Incoming Lanes
    //=========================================================================/
    if(myQueue.name == "A1" && A1.queue.empty()){
        if(checkLight(A1, lightEW)){
            std::cout << myQueue.name << " went at light" << std::endl;
            return movePointer(A1,T3); // Went at light
        }else{
            std::cout << myQueue.name << " stopped at light" << std::endl;
            return false; // Stopped at light
        }
    }

    if(myQueue.name == "A2" && A2.queue.empty()){
        if(checkLight(A2, lightNS)){
            std::cout << myQueue.name << " went at light" << std::endl;
            return movePointer(A2,T1); // Went at light
        }else{
            std::cout << myQueue.name << " stopped at light" << std::endl;
            return false; // Stopped at light
        }
    }

    if(myQueue.name == "A3" && A3.queue.empty()){
        if(checkLight(myQueue, lightEW)){
            std::cout << myQueue.name << " went at light" << std::endl;
            return movePointer(A3,T2); // Went at light
        }else{
            std::cout << myQueue.name << " stopped at light" << std::endl;
            return false; // Stopped at light
        }
    }

    if(myQueue.name == "A4" && A4.queue.empty()){
        if(checkLight(myQueue, lightNS)){
            std::cout << myQueue.name << " went at light" << std::endl;
            return movePointer(A4,T4); // Went at light
        }else{
            std::cout << myQueue.name << " stopped at light" << std::endl;
            return false; // Stopped at light
        }
    }
    //=========================================================================/

    // Intersections
    //=========================================================================/

    // T1
    if(myQueue.name == "T1" && T1.queue.empty()){
        if(T1.queue.front()->getPasses() == 1){ // From A2
            if(T1.queue.front()->getDirection() == 1){ // Right
                std::cout << myQueue.name << " went right" << std::endl;
                return movePointer(T1, B1);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T1, T3);
            }
        }else if(T1.queue.front()->getPasses() == 2){ // From A3
            if(T1.queue.front()->getDirection() == -1){ // Left
                return movePointer(T1, T3);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T1, B1);
            }
        }else{ // Passes = 3 (Left turned from A4, T4, T2)
            std::cout << myQueue.name << " went left after coming from A4" << std::endl;
            return movePointer(T1, B1);
        }
    }

    // T2
    if(myQueue.name == "T2" && T2.queue.empty()){
        if(T2.queue.front()->getPasses() == 1){ // From A3
            if(T2.queue.front()->getDirection() == 1){ // Right
                std::cout << myQueue.name << " went right" << std::endl;
                return movePointer(T2, B2);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T2, T1);
            }
        }else if(T2.queue.front()->getPasses() == 2){ // From A4
            if(T2.queue.front()->getDirection() == -1){ // Left
                return movePointer(T2, T1);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T2, B2);
            }
        }else{ // Passes = 3 (Left turned from A1, T3, T4)
            std::cout << myQueue.name << " went left after coming from A1" << std::endl;
            return movePointer(T2, B2);
        }
    }

    // T3
    if(myQueue.name == "T3" && T3.queue.empty()){
        if(T3.queue.front()->getPasses() == 1){ // From A3
            if(T3.queue.front()->getDirection() == 1){ // Right
                std::cout << myQueue.name << " went right" << std::endl;
                return movePointer(T3, B4);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T3, T4);
            }
        }else if(T3.queue.front()->getPasses() == 2){ // From A4
            if(T3.queue.front()->getDirection() == -1){ // Left
                return movePointer(T3, T4);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T3, B4);
            }
        }else{ // Passes = 3 (Left turned from A3, T2, T1)
            std::cout << myQueue.name << " went left after coming from A3" << std::endl;
            return movePointer(T3, B4);
        }
    }

    // T4
    if(myQueue.name == "T4" && T4.queue.empty()){
        if(T4.queue.front()->getPasses() == 1){ // From A3
            if(T4.queue.front()->getDirection() == 1){ // Right
                std::cout << myQueue.name << " went right" << std::endl;
                return movePointer(T4, B3);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T4, T2);
            }
        }else if(T4.queue.front()->getPasses() == 2){ // From A4
            if(T4.queue.front()->getDirection() == -1){ // Left
                return movePointer(T4, T2);
            }else{ // Straight
                std::cout << myQueue.name << " went straight" << std::endl;
                return movePointer(T4, B3);
            }
        }else{ // Passes = 3 (Left turned from A2, T1, T3)
            std::cout << myQueue.name << " went left after coming from A2" << std::endl;
            return movePointer(T4, B3);
        }
    }

    std::cout << "No matches!?!" << std::endl;

    //=========================================================================/
}

bool Intersection::checkLight(NamedQueue myQueue, Light myLight){
    if(myLight.getLightColor() == 0){
        std::cout << "Checked light, was Red" << std::endl;
        return false;
    }else if(myLight.getLightColor() == 2){
        std::cout << "Checked light, was Green" << std::endl;
        return true;
    }else{ // It has to be yellow
    std::cout << "Checked light, was Yellow" << std::endl;

    // not implemented yet
    return false;
    }
}
