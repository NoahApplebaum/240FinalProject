#include "FileReader.h"  // Header file

FileReader::FileReader(std::string file, bool debugMode){ // Create the fstream with the target file (No default constructor)



// VARIABLES
//=========================================================================================================//
    std::unordered_map<std::string,double> vars; // Unordered map (Hash map) of settings
    std::ifstream ifs;                           // Input filestream (for config file)
    std::string line;                            // String for holding lines
    int character;                               // Char for finding the equals character
    int index;                                   // Int for holding index being checked
    std::string key;                             // String for holding the key
    std::string value;                           // String for holding the value
    double valueDouble;                          // Double version of the value
    bool whitespaceIsPresent;                    // Boolean representing the presence of whitespace
//=========================================================================================================//

// OPEN FSTREAM
//=========================================================================================================//
    debug = debugMode;
    if(debug){std::cout << "Attempting to open file.\n";};     // Debug
    try{                                                       // Try to open stream with the file
        ifs.open(file);
    }catch(...){                                               // Catch any error...
        if(debug){std::cout << "Failed to open file.\n";};     // Debug
        throw;                                                 // Throw
    }
//=========================================================================================================//

// GET SETTING VARIABLES
//=========================================================================================================//
    while(true){                                               // Run loop until it is broken
        if(debug){std::cout << "Getting line...\n";};          // Debug
        getline(ifs, line);                                    // Get the next line and store it
        if(debug){std::cout << "Line: [" + line + "]\n";};     // Debug
        // Clean whitespace from line
        if(debug){std::cout << "Cleaning the line.\n";};       // Debug
        whitespaceIsPresent = true;                            // Reset so check will run
        while(whitespaceIsPresent){                            // While there is still whitespace
            if(!isspace(line[0]) || line[0] == '\0'){          // If the first char is not whitespace
                whitespaceIsPresent = false;                   // or is a newline end the loop
                if(debug){std::cout << "Done cleaning.\n";};   // Debug
            }else{                                             // Else...
                line.erase(0,1);                               // Erase the first char and run again
            }
        }

        if(!ifs.eof() && (line[0] == '#' || line[0] == '\0')){ // If the line is a comment or whitespace
            //do nothing (loop again)
        }else if(!ifs.eof()){                                  // If the line isn't an eof...
            index = 0;                                         // Set index back to 0
            character = 'x';                                   // Set the character back to a non '=' value
            while(character != '='){                           // While character isn't '='...
                character = line[index];                       // Get the character at index
                index++;                                       // Iterate index
            }
            key = line.substr(0,index - 1);                    // Get the key (first half) of the line
            value = line.substr(index, line.length() - index); // Get the values (second half) of the line
            if(debug){std::cout << "Key: [" + key + "]\n";};   // Debug
            if(debug){std::cout << "Value: [" + value + "]\n";};
            valueDouble = std::atof(value.c_str());            // convert string value to double value
            vars.emplace(key, valueDouble);                    // Place the key, value pair in the map


        }else if(ifs.eof() && line[0] != '\0'){
            index = 0;                                         // Set index back to 0
            character = 'x';                                   // Set the character back to a non '=' value
            while(character != '='){                           // While character isn't '='...
                character = line[index];                       // Get the character at index
                index++;                                       // Iterate index
            }
            key = line.substr(0,index - 1);                    // Get the key (first half) of the line
            value = line.substr(index, line.length() - index); // Get the values (second half) of the line
            if(debug){std::cout << "Key: [" + key + "]\n";};   // Debug
            if(debug){std::cout << "Value: [" + value + "]\n";};
            valueDouble = std::atof(value.c_str());            // convert string value to double value
            vars.emplace(key, valueDouble);                    // Place the key, value pair in the map
            break;                                             // This was the last line
        }else{                                                 // Else...
            break;                                             // Break the loop and continue setting up
        }
    }
    if(debug){std::cout << "Closing the file.\n";};            // Debug
    ifs.close();                                               // Close the fstream
//=========================================================================================================//

// SET SETTING VARIABLES
//=========================================================================================================//
    
    // Ticks
    totalTicks  = int (vars["totalTicks"]);
    greenTicks  = int (vars["greenTicks"]);
    yellowTicks = int (vars["yellowTicks"]);
    redTicks    = int (vars["redTicks"]);

    // Direction: Make sure it doesn't exceed 1
    probRight    = vars["probRight"];
    probLeft     = vars["probLeft"];
    probStraight = vars["probStraight"];

    if((probRight + probLeft + probStraight) != 1.0){
        std::cout << "\nYour direction probabilities are wonky you git.\n\n";
    }

    // Vehicle
    probVehicle = vars["probVehicle"];
    probCar = vars["probCar"];
    probSUV = vars["probSUV"];
    probTruck = vars["probTruck"];

    if((probCar + probSUV + probTruck) != 1.0){
        std::cout << "\nYour vehicle probabilities are wonky you git.\n\n";
    
    std::cout << probCar;
    std::cout << '\n';
    std::cout << probTruck;
    std::cout << '\n';
    std::cout << probSUV;
    std::cout << '\n';

    std::cout << (probCar + probSUV + probTruck);
    
    }


//=========================================================================================================//

// Debug Line

}

// GETTER METHODS
//=========================================================================================================//
int FileReader::getTotalTicks(){
    if(debug){std::cout << "getTotalTicks returns: " << totalTicks << "\n";}
    return totalTicks;
}

int FileReader::getGreenTicks(){
    if(debug){std::cout << "getGreenTicks returns: " << greenTicks << "\n";}
    return greenTicks;
}

int FileReader::getYellowTicks(){
    if(debug){std::cout << "getyellowTicks returns: " << yellowTicks << "\n";}
    return yellowTicks;
}

int FileReader::getRedTicks(){
    if(debug){std::cout << "getredlTicks returns: " << redTicks << "\n";}
    return redTicks;
}

double FileReader::getProbRight(){
    return probRight;
}

double FileReader::getProbLeft(){
    return probLeft;
}

double FileReader::getProbStraight(){
    return probStraight;
}

double FileReader::getProbVehicle(){
    return probVehicle;
}

double FileReader::getProbCar(){
    return probCar;
}

double FileReader::getProbSUV(){
    return probSUV;
}

double FileReader::getProbTruck(){
    return probTruck;
}


//=========================================================================================================//