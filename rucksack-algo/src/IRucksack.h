#pragma once
/**
	Interface for each Rucksack Algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

class IRucksack{
public:
	
	virtual ~IRucksack() {}

	/**
		Initilize the Algorithm with the needed parameters
		@params	maxWeight: Total weight the Rucksack can have
				weight: Vector with all the weights of the objects that can be chosen 
				price: Corresponding to each weight there is a price at the same index
	*/
	virtual void init(vector<int> weight, vector<int> price, int maxWeight) = 0;


	// Calculate a result with the algorithm
	virtual void calculate() = 0;


	// Setter
	virtual void setSpeedUp(double speedUp) = 0;


	// Getter
	virtual int getRunTime() = 0;
	virtual int getRunSteps() = 0;
	virtual vector<int> getUsedWeights() = 0;
	virtual int getResultWeight() = 0;
	virtual int getResultPrice() = 0;
	virtual double getRelativeError() = 0;


	// Print the Result of the Algorithm to the command line
	virtual void printResult() = 0;
};