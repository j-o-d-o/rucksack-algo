#include <iostream>
#include <vector>
#include <map>
#include <assert.h>

#include "PseudoPoly.h"

using namespace std;

// Parameters
int maxWeight = 645;		// maximum weight that can be inside the bag
//vector<int> weight{ 153,  54, 191,  66, 239, 137, 148, 249 };
//vector<int>  price{ 232,  73, 201,  50, 141,  79,  48,  38 };
vector<int> weight{ 183, 354, 291, 166, 279, 237, 108,  49, 50, 400, 10 };
vector<int>  price{ 212, 173, 201,  80, 211, 179,  48,  38, 30, 401, 23 };

int main() {
	assert(weight.size() == price.size());

	IRucksack* ppAlgo = new PseudoPoly(weight, price, maxWeight);

	// Start Algorithms
	ppAlgo->calculate();


	// Print Input
	cout << "Print Results" << endl;
	cout << "INPUT: " << endl;
	cout << "Weights: ";
	for(int i=0; i < weight.size(); ++i)
		std::cout << weight[i] << ' ';
	cout << endl;
	cout << "Prices: ";
	for(int i=0; i < price.size(); ++i)
		std::cout << price[i] << ' ';
	cout << endl;
	cout << "Maximum Weight: " << maxWeight << endl << endl;
	cout << "RESULTS:" << endl;
	
	// Print Results
	ppAlgo->printResult();


	system("pause");
	return 0;
} 