#pragma once

#include "RucksackBase.h"

class BrutForce : public RucksackBase {
private:

public:
	BrutForce(vector<int> weight, vector<int> price, int maxWeight);
	~BrutForce();

	void calculate();
	void printResult();
};