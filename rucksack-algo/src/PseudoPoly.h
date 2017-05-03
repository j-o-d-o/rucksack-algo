#pragma once

#include "RucksackBase.h"

class PseudoPoly : public RucksackBase {
private:

public:
	PseudoPoly(vector<int> weight, vector<int> price, int maxWeight);
	~PseudoPoly();

	pair<int, vector<int>> calculate();
	void printResult();
};