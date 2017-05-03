#pragma once

#include "IRucksack.h"

#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <windows.h>
#include <fstream>

class RucksackBase : public IRucksack{

protected:
	// Input Values
	vector<int> weight;
	vector<int> price;
	int maxWeight;

	// Result Values
	long int runTime;
	int runSteps;
	vector<int> resultWeights;
	int resultPriceTotal;
	int resultWeightTotal;

public:
	RucksackBase(vector<int> weight, vector<int> price, int maxWeight);
	~RucksackBase();

	void init(vector<int> weight, vector<int> price, int maxWeight);
	pair<int, int> getRunTime();
	void printResult();

	// Pass calculate through to the child classes
	virtual pair<int, vector<int>> calculate() = 0;
};