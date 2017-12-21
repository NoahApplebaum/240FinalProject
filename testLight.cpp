#include <iostream>
#include "Light.cpp"

using namespace std;

int main() {
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "Testing default light constructor:" << endl;

	Light light1("light1");
	cout << "Green ticks: " << light1.getGreenTicks() << ", Yellow ticks: " << light1.getYellowTicks() << ", Red ticks: " << light1.getRedTicks() << ", Light color: " << light1.getLightColor() << ", Ticks left: " << light1.getTicksLeft() << endl << endl;

	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "Testing useful light constructor:" << endl;
	cout << "Light light2(20,15,0)" << endl;
	Light light2("light2",20,15,0);
	cout << "Green ticks: " << light2.getGreenTicks() << ", Yellow ticks: " << light2.getYellowTicks() << ", Red ticks: " << light2.getRedTicks() << ", Light color: " << light2.getLightColor() << ", Ticks left: " << light2.getTicksLeft() << endl << endl;


	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "Testing the light function in a simulator: " << endl;
	cout << "Run 50 seconds on light2, which has 20 seconds for greenTicks, 15 seconds for redTicks, and starting with a red light. What is the light state after 50 seconds?" << endl;
	for (int i = 0; i < 50; i++) {
		light2.updateTicksLeft();
		light2.updateLightColor();
		cout << "after " << i+1 << " seconds, light color: " << light2.getLightColor() << ", ticks left: " << light2.getTicksLeft() << endl << endl;
	}


}