#include "PseudoPoly.h"


PseudoPoly::PseudoPoly(vector<int> weight, vector<int> price, int maxWeight){
	this->speedUp = 1;	// No speed up
	this->relativeError = 0; // No error => result is exact

	init(weight, price, maxWeight);
}

PseudoPoly::~PseudoPoly(){
}

void PseudoPoly::calcError(){
	int max = INT_MIN;
	for (auto val : price) {
		if (max < val) max = val;
	}
	// The formular for the relative error is not 100% exact, it is an appraisal
	// Thus if speedUp is 1 the formular does not output a relative error of 0
	// That is why it must be set to 0 programmatically in that case
	if (speedUp > 1)
		relativeError = ((double)price.size() / (double)max) * speedUp;
	else
		relativeError = 0;
}

void PseudoPoly::init(vector<int> weight, vector<int> price, int maxWeight){
	// Depending on speed up, size and max{price}, calculate relativeError
	calcError();

	RucksackBase::init(weight, price, maxWeight);
}

void PseudoPoly::setSpeedUp(double speedUp){
	this->speedUp = speedUp;
	// When speedup changes, the relative error must be calculated again
	calcError();
}

double PseudoPoly::getRelativeError(){
	if (speedUp <= 1)
		return 0;
	return relativeError;
}

void PseudoPoly::printResult(){
	cout << "============================================================" << endl;
	cout << "Pseud Polynomyl Algorithm:" << endl;
	cout << "Complexity: O(n^2 * max{price})" << endl << endl;
	if(speedUp > 1){
		cout << "Speed Up: " << speedUp << "x" << endl;
		cout << "Relativ Error: " << relativeError << endl;
	}
	RucksackBase::printResult();
}

void PseudoPoly::calculate() {
	// Start Timer
	long int start = GetTickCount();

	// Variables 
	int alpha = 0;
	size_t n = weight.size();
	int maxPriceSum = 0;
	int alphaMax = 0;
	int steps = 0;
	vector<int> orgPrices = price;

	// Calc Max Posible price
	for (int i = 0; i < n; i++) {
		price.at(i) = price.at(i) / speedUp;
		maxPriceSum += price.at(i);
	}

	map<int, vector<pair<int, int>>> table;

	// p.first => the weight at that position in the table
	// p.second => the previous position in the table (to make it easy to find out the the used weights)
	pair<int, int> p;

	// To make more sense off these algorithm also look into the README.md file
	while (alpha <= maxPriceSum) {
		int fi = 0;
		for (int i = 0; i < n; i++) {
			steps++;

			// For price = 0, no object is in the rucksack
			if (alpha == 0) {
				table[0].push_back(pair<int,int>(0, 0));
			}
			else {
				if (i == 0) {
					// There is no previous entry in the table that could be used
					if (alpha == price.at(0)) {
						table[alpha].push_back(pair<int,int>(weight.at(0),0));
					}
					else {
						// NOTE: using -1 as a placeholder for infinity might have not been the smartest move... 
						// have to make some if condition statments later on that I think could be avoided otherwise
						table[alpha].push_back(pair<int,int>(-1,0));
					}
				}
				else {
					// fi_last is the table entry at F(alpha) at i - 1
					// fi_new is the table entry at [ F(alpha - price(i)) at i - 1 ] + weight(i)
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

					// Test if fi_last or fi_new is smaller and take the smallest
					int prev = 0;
					if (fi_last == -1 || (fi_new < fi_last && fi_new != -1)) {
						fi = fi_new;
						prev = testIndex;
					}
					else {
						fi = fi_last;
						prev = alpha;
					}

					// Saving the previous alpha makes it much easier to retrive 
					// exactly which items where used for the final result
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
			cout << alpha << " |";
			for (int index = 0; index < table[alpha].size(); index++)
				cout << "\t" << table[alpha][index].first;
			cout << endl;
		}

		alpha++;
	}
	long int end = GetTickCount();

	 
	// Get result values
	int currentLine = alphaMax;
	resultPriceTotal = 0;
	// 
	for(int i = (table[alphaMax].size()-1); i >= 0; --i){
		// table[currentLine][i].second == previous alpha
		// Each time the previous line is not the current line, 
		// indicates that a weight has been added there
		// in the README.md file at the table image: 
		// for each read arrow darwn in to the image
		if(table[currentLine][i].second != currentLine){
			currentLine = table[currentLine][i].second;
			resultWeights.push_back(weight.at(i));
			resultPriceTotal += orgPrices.at(i);
		}
	}
	reverse(resultWeights.begin(), resultWeights.end());

	runSteps = steps;
	runTime = end - start;
	resultWeightTotal = table[alphaMax][table[alphaMax].size()-1].first;

}

