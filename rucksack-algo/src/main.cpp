#include <iostream>
#include <vector>
#include <map>
#include <assert.h>

#include "PseudoPoly.h"
#include "BrutForce.h"
#include "Greedy.h"

using namespace std;

// Parameters
int maxWeight = 645;		// maximum weight that can be inside the bag
vector<int> weight{ 153,  54, 191,  66, 239, 137, 148, 249 };
vector<int> price{  232,  73, 201,  50, 141,  79,  48,  38 };
//vector<int> weight{ 183, 354, 291, 166, 279, 237, 108,  49, 50, 120, 111,  30, 194, 182, 148, 193, 105 };
//vector<int>  price{ 122, 173, 201,  80, 211, 179,  48,  38, 30, 111,  23,  49, 139,  98, 199, 189, 174 };

int main() {
	assert(weight.size() == price.size());

	IRucksack* ppAlgo = new PseudoPoly(weight, price, maxWeight);
	IRucksack* bfAlgo = new BrutForce(weight, price, maxWeight);
	IRucksack* geAlgo = new Greedy(weight, price, maxWeight);

	// Speed Up
	ppAlgo->setSpeedUp(17);

	// Start Algorithms
	ppAlgo->calculate();
	bfAlgo->calculate();
	geAlgo->calculate();
	
	// Print Input
	cout << "INPUT: " << endl;
	cout << "Weights: ";
	for(int i=0; i < weight.size(); ++i)
		std::cout << weight[i] << '\t';
	cout << endl;
	cout << "Prices: " << " ";
	for(int i=0; i < price.size(); ++i)
		std::cout << price[i] << "\t";
	cout << endl;
	cout << "Max Weight: " << maxWeight << endl << endl;

	// Print Results
	ppAlgo->printResult();
	bfAlgo->printResult();
	geAlgo->printResult();

	system("pause");
	return 0;
} 