#include <iostream>
#include <iomanip>

#include "SupplyPathFinder.hpp"

void TEST(int expected, int actual, std::string testName){
	if (expected == actual) {
		std::cout << testName << "\t\t\tPASSED!" << std::endl;
	} else {
		std::cout << testName << "\t\tFAILED!!!" << std::endl;
		std::cout << "Expected " << expected << " but was " << actual << std::endl;
	}
}

void TestStore(){

}

void TestPathFind(){
	SupplyPathFinder finder(6, 1, 3, 2 ,3);

}

int main() {

	SupplyPathFinder finder = SupplyPathFinder();
	finder.Populate();

	// Find the resulting KMs foro bikes and trucks
	std::pair<double, double> kms = finder.Find();
	// Printing with precision of 3
	std::cout << std::fixed;
	std::cout << std::setprecision(3);
	std::cout << kms.first << " " << kms.second << std::endl;

	return 0;
}
