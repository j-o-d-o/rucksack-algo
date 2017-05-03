#pragma once

#include "RucksackBase.h"

class Greedy : public RucksackBase {
private:

public:
	Greedy(vector<int> weight, vector<int> price, int maxWeight);
	~Greedy();

	void calculate();
	void printResult();
};
