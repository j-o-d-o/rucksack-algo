#include "RucksackBase.h"

RucksackBase::RucksackBase(){
}

RucksackBase::RucksackBase(vector<int> weight, vector<int> price, int maxWeight) {
	init(weight, price, maxWeight);
}

RucksackBase::~RucksackBase(){
}

void RucksackBase::init(vector<int> weight, vector<int> price, int maxWeight){
	// Each item must have a price and a weight
	assert(weight.size() == price.size());

	this->weight = weight;
	this->price = price;
	this->maxWeight = maxWeight;

	// Init / reset values
	this->runTime = NULL;
	this->runSteps = NULL;
	resultWeights.clear();
	resultPriceTotal = NULL;
	resultWeightTotal = NULL;
}

int RucksackBase::getRunTime(){
	return runTime;
}
int RucksackBase::getRunSteps(){
	return runSteps;
}
vector<int> RucksackBase::getUsedWeights(){
	return resultWeights;
}
int RucksackBase::getResultWeight(){
	return resultWeightTotal;
}
int RucksackBase::getResultPrice(){
	return resultPriceTotal;
}
double RucksackBase::getRelativeError(){
	// If the child class does not override this method, the algorithm does not have an realtiv error
	cout << "Warning: This is either an exect Algorithm or the Error can be infinitely bad" << endl;
	return -1;
}
void RucksackBase::setSpeedUp(double speedUp){
	// If the child class does not override this method, the algorithm does not have a speed up variable
	cout << "Warning: This algorithm has not speed up parameter!" << endl;
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