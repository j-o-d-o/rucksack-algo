#pragma once

#include "IRucksack.h"

#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <windows.h>
#include <fstream>
#include <algorithm>

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
	RucksackBase();
	RucksackBase(vector<int> weight, vector<int> price, int maxWeight);
	~RucksackBase();

	void init(vector<int> weight, vector<int> price, int maxWeight);

	// Getter Functions for the Results
	int getRunTime();
	int getRunSteps();
	vector<int> getUsedWeights();
	int getResultWeight();
	int getResultPrice();
	void printResult();
	double getRelativeError();
	void setSpeedUp(double speedUp);

	// Pass calculate through to the child classes
	void calculate() = 0;
};