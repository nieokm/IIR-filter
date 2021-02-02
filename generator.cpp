#include <fstream>
#include <random>
#include <iostream>
#include <cmath>

int main() {

	int type;
	std::cout << "Select the type of a signal:" << std::endl << "1. Sinosuidal" << std::endl << "2. Sum of two different sinusoidal" << std::endl << "3. White noise" << std::endl;
	std::cin >> type;
	
	std::ofstream outputFile("input.txt");
	if(type==1) {
		for(int i=0;i<1000;i++)
			outputFile<< sin(3.14159265*0.0015*i) <<"\n";
		}
	if(type==2) {
		for(int i=0;i<1000;i++)
			outputFile<< sin(3.14159265*0.0015*i) + sin(3.14159265*0.006*i) <<"\n";
		}
	if(type==3) {
		std::mt19937 generator;
		std::normal_distribution<double> normal(0.0, 2.0);
		for(int i=0;i<1000;i++)
			outputFile<<normal(generator)<<std::endl;
		}
	return 0;
}
