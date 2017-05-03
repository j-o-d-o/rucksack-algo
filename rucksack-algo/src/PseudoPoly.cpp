#include "PseudoPoly.h"


PseudoPoly::PseudoPoly(vector<int> weight, vector<int> price, int maxWeight) : RucksackBase(weight, price, maxWeight) {
}

PseudoPoly::~PseudoPoly(){
}

void PseudoPoly::printResult(){
	cout << "============================================================" << endl;
	cout << "Pseud Polynomyl Algorithm:" << endl;
	cout << "Complexity: O(n^2 * max{price})" << endl << endl;
	RucksackBase::printResult();
}

pair<int, vector<int>> PseudoPoly::calculate() {
	// Start Timer
	long int start = GetTickCount();


	// Variables 
	int alpha = 0;
	size_t n = weight.size();
	int maxPriceSum = 0;
	int alphaMax = 0;
	int steps = 0;

	// Calc Max Posible price
	for (int i = 0; i < n; i++) {
		maxPriceSum += price.at(i);
	}

	map<int, vector<pair<int, int>>> table;
	pair<int, int> p;
	while (alpha < maxPriceSum) {
		int fi = 0;
		for (int i = 0; i < n; i++) {
			steps++;

			// For price = 0, no object is in the rucksack
			if (alpha == 0) {
				table[0].push_back(pair<int,int>(0, 0));
			}
			else {
				if (i == 0) {
					if (alpha == price.at(0)) {
						table[alpha].push_back(pair<int,int>(weight.at(0),0));
					}
					else {
						table[alpha].push_back(pair<int,int>(-1,0));
					}
				}
				else {
					int fi_last = table.at(alpha).at(i - 1).first;
					int fi_new = -1;
					int testIndex = 0;

					if (alpha - price.at(i) >= 0) {
						int w = weight.at(i);
						testIndex = alpha - price.at(i);
						int val = table.at(testIndex).at(i - 1).first;
						if (val != -1) {
							fi_new = val + w;
						}
					}

					int prev = 0;
					if (fi_last == -1 || (fi_new < fi_last && fi_new != -1)) {
						fi = fi_new;
						prev = testIndex;
					}
					else {
						fi = fi_last;
						prev = alpha;
					}

					table[alpha].push_back(pair<int, int>(fi, prev));
				}
			}
		}

		if (fi <= maxWeight && fi > 0) {
			alphaMax = alpha;
		}

		// Debug output of table, if fi == -1, price was not posible to reach with the given weights
		bool showTable = false;
		if (fi != -1 && showTable){
			cout << alpha;
			for (int index = 0; index < table[alpha].size(); index++)
				cout << "\t" << table[alpha][index].first << ", " << table[alpha][index].second;
			cout << endl;
		}

		alpha++;
	}
	long int end = GetTickCount();

	 
	// Save results
	int currentLine = alphaMax;
	int prevWeight = table[alphaMax][table[alphaMax].size()-1].first;
	for(int i = (table[alphaMax].size()-2); i >= 0; --i){
		if(table[currentLine][i].first > prevWeight || (prevWeight != -1 && table[currentLine][i].first == -1)){
			resultWeights.push_back(weight.at(i+1));
			prevWeight -= weight.at(i + 1);
			currentLine = table[currentLine][i + 1].second;
			if(i == 0 && table[currentLine][i].first != -1){
				resultWeights.push_back(weight.at(0));
			}
		}
	}
	

	runSteps = steps;
	runTime = end - start;
	resultPriceTotal = alphaMax;
	resultWeightTotal = table[alphaMax][table[alphaMax].size()-1].first;

	// Return Values
	pair<int, vector<int>> returnVal(alphaMax, weight);
	return returnVal;
}

