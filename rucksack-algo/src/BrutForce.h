#pragma once

/**
	Calculate the rucksack problem with a brute force method
	For more details check out the README.md file
*/

#include "RucksackBase.h"

class BrutForce : public RucksackBase {
private:

public:
	BrutForce(vector<int> weight, vector<int> price, int maxWeight);
	~BrutForce();

	void calculate();
	void printResult();
};