#ifndef __FILEREADER_H__
#define __FILEREADER_H__

//#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>        //for receiving input file, etc.
#include <iostream>      // For cout
#include <stdexcept>     // For exceptions
#include <fstream>       // For parsing input file (ifstream)
#include <cctype>        // For checking for whitespace
#include <unordered_map> // For making the hash map of settings
#include <iomanip>       // For cout.precision(17) (Printing doubles)

class FileReader{

    public:

        // Constructor (can throw exception)
        // Default is "simulator.cfg"
        FileReader(std::string file="simulator.cfg", bool debugMode=false);
        //FileReader(std::string file);

        // Ticks
        int getTotalTicks();
        int getGreenTicks();
        int getYellowTicks();
        int getRedTicks();

        // Direction
        double getProbRight();
        double getProbLeft();
        double getProbStraight();

        // Vehicle
        double getProbVehicle();
        double getProbCar();
        double getProbSUV();
        double getProbTruck();

    private:

        // Ticks
        int totalTicks;//100.0
        int greenTicks;//6.0
        int yellowTicks;//2.0
        int redTicks;//8.0

        // Direction: Make sure it doesn't exceed 1
        double probRight;//0.25
        double probLeft;//0.25
        double probStraight;//0.5

        // Vehicle
        double probVehicle;//0.5
        double probCar;//0.4
        double probSUV;//0.4
        double probTruck;//0.2

        // DebugMode
        bool debug;
};
#endif
