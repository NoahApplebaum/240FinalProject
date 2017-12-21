# 240FinalProject
Four lane intersection traffic simulator written in C++.

Reads from simulator.cfg

If makefile has issues run:
g++ -Wall -Wno-deprecated -std=c++11 Simulator.cpp FileReader.cpp Intersection.cpp Light.cpp Vehicle.cpp NamedQueue.cpp random.h 


totalTicks=100.0
probRight=0.25
probLeft=0.25
probStraight=0.5
ticksOnGreen=6.0
ticksOnYellow=2.0
ticksOnRed=8.0
probOfVehicle=0.5
probOfCar=0.4
probOfSUV=0.4
probOfTruck=0.2

