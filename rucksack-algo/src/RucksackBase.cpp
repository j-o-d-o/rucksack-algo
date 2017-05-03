#include "RucksackBase.h"

RucksackBase::RucksackBase(vector<int> weight, vector<int> price, int maxWeight) {
	init(weight, price, maxWeight);
}

RucksackBase::~RucksackBase(){
}

void RucksackBase::init(vector<int> weight, vector<int> price, int maxWeight){
	assert(weight.size() == price.size());

	this->weight = weight;
	this->price = price;
	this->maxWeight = maxWeight;

	this->runTime = NULL;
	this->runSteps = NULL;
	resultWeights.clear();
	resultPriceTotal = NULL;
	resultWeightTotal = NULL;
}

pair<int, int> RucksackBase::getRunTime(){
	pair<int, int> returnValue(runTime, runSteps);
	return returnValue;
}

void RucksackBase::printResult(){
	// Usualy some specific stuff for the algorithm used is printed first
	// ...
	// Then the generic stuff here:
	cout << "Weight Result:\t" << resultWeightTotal << endl;
	cout << "Price Result:\t" << resultPriceTotal << endl;
	cout << "Run Time (ms):\t" << runTime << endl;
	cout << "Run Steps:\t" << runSteps << endl;
	cout << "Used Weights:\t";
	for(int i=0; i < resultWeights.size(); ++i)
		std::cout << resultWeights[i] << ' ';
	cout << endl;
	cout << "============================================================" << endl << endl;
}