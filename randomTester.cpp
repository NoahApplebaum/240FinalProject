#include <iostream>

#include "random.h"

// let's define the static members in Random
std::mt19937 Random::rng(8675309);
std::uniform_int_distribution<int> Random::randint01(15,18);
std::uniform_real_distribution<double> Random::randdouble(0.0,1.0);


int main()
{		
	  // this will be the user input possibility			
	  double proA = 0.3;
	  double proB = 0.5;
	  double proC = 0.2;

	  // scale them because I don't know how to generate doubles
	  int intProA = (int)(proA * 100);
	  int intProB = (int)(proB * 100);
	  int intProC = (int)(proC * 100);
	  std::cout << intProA << std::endl;
	  std::cout << intProB << std::endl;
	  std::cout << intProC << std::endl;

	  // first one is the randome number from 0 to 100, the second one is what type of car to gen
	  int carRanNum;	
      int carToGen;

      for (int i = 0; i < 100; i++) {
      	
      	carRanNum = Random::randint(0,100);	
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

}