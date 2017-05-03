#pragma once

#include <iostream>
#include <vector>

using namespace std;

class IRucksack{
public:
	
	virtual ~IRucksack() {}

	// Initilize the Algorithm with the needed info
	// maxWeight => Total weight the Rucksack can have
	// weight => Vector with all the weights of the objects that can be chosen 
	// price => Corresponding to each weight there is a price at the same index
	virtual void init(vector<int> weight, vector<int> price, int maxWeight) = 0;


	// Calculate using a specified Algorithm, first int is the resulting weight, second one are the indicies of the used weights
	virtual pair<int, vector<int>> calculate() = 0;


	// First int is RunTime in ms, Second int is RunTime Steps
	virtual pair<int, int> getRunTime() = 0;


	// Print the Result of the Algorithm to the Command Box
	virtual void printResult() = 0;
};