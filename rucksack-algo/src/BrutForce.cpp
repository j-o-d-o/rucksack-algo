#include "BrutForce.h"

#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))

BrutForce::BrutForce(vector<int> weight, vector<int> price, int maxWeight) : RucksackBase(weight, price, maxWeight) {
}

BrutForce::~BrutForce(){
}


void BrutForce::printResult(){
	cout << "============================================================" << endl;
	cout << "Brut Force Algorithm:" << endl;
	cout << "Complexity: O(2^n)" << endl << endl;
	RucksackBase::printResult();
}

void BrutForce::calculate() {
	// Start Timer
	long int start = GetTickCount();
	int steps = 0;

	int size = weight.size();
	if(size > 31){
		throw std::invalid_argument("The Size of the Input is too large for a brut force approach");
	}

	// Just try out every posible combination
	// It is basicly counting values up to 2^n and each bit is a "object"
	unsigned int maxTry = pow(2, size);
	int priceTmp = 0;
	int weightTmp = 0;
	vector<int> weightsTmp;
	resultPriceTotal = 0;
	for(unsigned int i = 0; i < maxTry; i++){
		weightTmp = 0;
		weightsTmp.clear();
		priceTmp = 0;
		for(int pos = 0; pos < size; pos++){
			steps++;
			if(CHECK_BIT(i, pos)){
				weightsTmp.push_back(weight.at(pos));
				weightTmp += weight.at(pos);
				priceTmp += price.at(pos);
			}
		}
		if(weightTmp <= maxWeight && priceTmp > resultPriceTotal){
			resultWeightTotal = weightTmp;
			resultPriceTotal = priceTmp;
			resultWeights = weightsTmp;
		}
	}
	long int end = GetTickCount();

	runSteps = steps;
	runTime = end - start;
}

