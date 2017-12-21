Simulator: Simulator.o FileReader.o Light.o Vehicle.o Intersection.o random.o
	g++ -Wall -Wno-deprecated -std=c++11 Simulator.cpp -o Simulator

Simulator.o: Simulator.cpp
	g++ -Wall -Wno-deprecated -std=c++11 Simulator.cpp

FileReader.o: FileReader.cpp FileReader.h
	g++ -Wall -Wno-deprecated -std=c++11 FileReader.cpp

Light.o: Light.cpp Light.h
	g++ -Wall -Wno-deprecated -std=c++11 Light.cpp 

Vehicle.o: Vehicle.cpp Vehicle.h
	g++ -Wall -Wno-deprecated -std=c++11 Vehicle.cpp

random.o: random.h
	g++ -Wall -Wno-deprecated -std=c++11 random.h

Intersection.o: Intersection.cpp Intersection.h
	g++ -Wall -Wno-deprecated -std=c++11 Intersection.cpp

clean:
	/bin/rm -f *.o Simulator