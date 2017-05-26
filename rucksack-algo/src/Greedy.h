#pragma once

/**
	Calculate the rucksack problem with a greedy method
	For more details check out the README.md file
*/

#include "RucksackBase.h"

class Greedy : public RucksackBase {
private:

public:
	Greedy(vector<int> weight, vector<int> price, int maxWeight);
	~Greedy();

	void calculate();
	void printResult();
};
