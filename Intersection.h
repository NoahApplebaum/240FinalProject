#ifndef __INTERSECTION__
#define __INTERSECTION__

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

#include <queue> // for holding the segments
#include <string>
#include "Vehicle.h"
#include "Light.h"
#include "random.h"
#include "NamedQueue.h"
#include <iostream>

class Intersection{

    protected:

        // Declaration of variables
        //=====================================================================/

        // The two light objects which control the traffic flow
        Light lightNS; // The North/South bound light
        Light lightEW; // The East/West bound light

        // Inbound lanes (where vehicles are spawned)
        NamedQueue A1;
        NamedQueue A2;
        NamedQueue A3;
        NamedQueue A4;

        // Outbound lanes (Where vehicles end up)
        NamedQueue B1;
        NamedQueue B2;
        NamedQueue B3;
        NamedQueue B4;

        // Intersections (Where vehicles turn or go straight)
        NamedQueue T1;
        NamedQueue T2;
        NamedQueue T3;
        NamedQueue T4;

        // Config variables

        // Directions: Total should not exceed 1
        double probRight;
        double probLeft;
        double probStraight;

        // Vehicle probabilities
        double probVehicle;
        double probCar;
        double probSUV;
        double probTruck;

        //=====================================================================/

    public:

        // Declaration of Methods
        //=====================================================================/

        // Constructor
        Intersection(double myProbRight, double myProbLeft,
        double myProbStraight, double myProbVehicle, double myProbCar,
        double myProbSUV, double myProbTruck);

        // Spawn method: spawn a vehicle and add the right # of pointers to
        // the given queue (Ex. 2 for a car)
        void spawnVehicle(NamedQueue myQueue);

        // Randomly add a null ptr or run spawnVehicle
        bool generateArrival(NamedQueue myQueue);

        // Move method: moves a pointer, if present, from A to B
        bool movePointer(NamedQueue A, NamedQueue B);

        // Tick method: does all the things that need to happen per tick
        void tick();

        // Go method, attempts to move to the next lane
        bool go(NamedQueue myQueue);

        // Checklight

        bool checkLight(NamedQueue myQueue, Light myLight);

        //=====================================================================/
};
#endif
