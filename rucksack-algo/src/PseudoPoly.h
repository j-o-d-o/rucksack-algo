#pragma once

#include "RucksackBase.h"

class PseudoPoly : public RucksackBase {
private:
	double speedUp;
	double relativeError;

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