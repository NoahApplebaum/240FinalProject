// This is the intersection main simulator file

// Diagram and labels of intersection
/*******************************************************************************

+---------------------+
| A = Inbound Lanes   |
+----------+----------+----------+----------+----------+----------+
| Name     | Straight | North    | East     | South    | West     |
+----------+----------+----------+----------+----------+----------+
|  A1      | T3       | ——       | T3       | ——       | ——       |
|  A2      | T1       | ——       | ——       | T1       | ——       |
|  A3      | T2       | ——       | ——       | ——       | T2       |
|  A4      | T4       | T4       | ——       | ——       | ——       |
+----------+----------+----------+----------+----------+----------+

+---------------------+
| B = Outbound Lanes  |
+----------+----------+----------+----------+----------+----------+
| Name     | Straight | North    | East     | South    | West     |
+----------+----------+----------+----------+----------+----------+
|  B1      | NO       | ——       | ——       | ——       | ——       |
|  B2      | NO       | ——       | ——       | ——       | ——       |
|  B3      | NO       | ——       | ——       | ——       | ——       |
|  B4      | NO       | ——       | ——       | ——       | ——       |
+----------+----------+----------+----------+----------+----------+

+---------------------+
| T = Intersections   |
+----------+----------+----------+----------+----------+----------+
| Name     | Straight | North    | East     | South    | West     |
+----------+----------+----------+----------+----------+----------+
|  T1      | NO       | ——       | ——       | T3       | B1       |
|  T2      | NO       | B2       | ——       | ——       | T1       |
|  T3      | NO       | ——       | T4       | B4       | ——       |
|  T4      | NO       | T2       | B3       | ——       | ——       |
+----------+----------+----------+----------+----------+----------+

*******************************************************************************/

// Import Classes
/******************************************************************************/

// Classes from C++
#include <iostream>
#include <queue>

// Recommended for C++11 Which I'm using array iteration from
#include <array>

// Classes we made
#include "Vehicle.h"
#include "Light.h"
#include "Intersection.h"
#include "FileReader.h"


/******************************************************************************/

// Main simulator method
/******************************************************************************/
int main(){

    FileReader myReader;

    double myProbRight = myReader.getProbRight();
    double myProbLeft = myReader.getProbLeft();
    double myProbStraight = myReader.getProbStraight();
    double myProbVehicle = myReader.getProbVehicle();
    double myProbCar = myReader.getProbCar();
    double myProbSUV = myReader.getProbSUV();
    double myProbTruck  = myReader.getProbTruck();

    int myTotalTicks = myReader.getTotalTicks();

    Intersection myIntersection(myProbRight, myProbLeft, myProbStraight, 
    myProbVehicle, myProbCar, myProbSUV, myProbTruck);

    for(int i = 0; i < myTotalTicks; i++){
        std::cout << "Tick " << i+1 << std::endl;
        std::cout << "==============================================" << std::endl;
        myIntersection.tick();
        std::cout << "==============================================" << std::endl;
    }

/******************************************************************************/


return 0;
}
