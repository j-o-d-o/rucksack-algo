#include "Greedy.h"

Greedy::Greedy(vector<int> weight, vector<int> price, int maxWeight) : RucksackBase(weight, price, maxWeight) {
}

Greedy::~Greedy(){
}


void Greedy::printResult(){
	cout << "============================================================" << endl;
	cout << "Greedy Algorithm:" << endl;
	cout << "Complexity: O(log(n)*n)" << endl << endl;
	RucksackBase::printResult();
}

void Greedy::calculate() {
	// Start Timer
	long int start = GetTickCount();
	int steps = 0;

	int size = weight.size();
	// int => saves the index to the original input, double => saves the actual ratio
	vector<pair<int, double>> ratios;

	// Calc price to weight ratio, high number = good, low number = bad
	for(int i = 0; i < size; i++){
		steps++;
		double ratio = (double)price.at(i) / (double)weight.at(i);
		ratios.push_back(pair<int, double>(i, ratio));
	}

	// Sort the vector
	// http://www.cplusplus.com/reference/algorithm/sort/ states that std::sort is, on avarage, n*log(n)
	// From what I have found online, std::sort using IntroSort (a variation of Quicksort) and if a "bad case"
	// for IntroSort is detected it switches to HeapSort 
	sort(ratios.begin(), ratios.end(), [&] (const pair<int, double>& val1, const pair<int, double>& val2){
		steps++;
		return (val1.second > val2.second);
	});

	resultPriceTotal = 0;
	resultWeightTotal = 0;
	resultWeights.clear();
	int weightLeft = maxWeight;
	for(int i = 0; i < size; i++){
		steps++;
		int testWeight = weight.at(ratios[i].first);
		if(weightLeft >= testWeight){
			weightLeft -= testWeight;
			resultPriceTotal += price.at(ratios[i].first);
			resultWeightTotal += testWeight;
			resultWeights.push_back(testWeight);
		}
	}

	long int end = GetTickCount();

	runSteps = steps;
	runTime = end - start;
}

