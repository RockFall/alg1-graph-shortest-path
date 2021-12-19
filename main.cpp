#include <iostream>
#include <iomanip>

#include "SupplyPathFinder.hpp"

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
