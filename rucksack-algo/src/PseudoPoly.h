#pragma once

/**
	Calculate the rucksack problem with a PTAS Algorithm (which is pseudo polynomial, thus the name)
	For more details check out the README.md file
*/

#include "RucksackBase.h"

class PseudoPoly : public RucksackBase {
private:
	double speedUp;
	double relativeError;

	// Calculate the relative error
	void calcError();
public:
	PseudoPoly(vector<int> weight, vector<int> price, int maxWeight);
	~PseudoPoly();

	void init(vector<int> weight, vector<int> price, int maxWeight);

	void calculate();
	void printResult();

	void setSpeedUp(double speedUp);
	double getRelativeError();
};