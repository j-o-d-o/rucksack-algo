/** 
	Main entry point of the programm
	1.) Gets user input
	2.) Read file from user input
	3.) Use algorithms to calculate results
	4.) Output results
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <assert.h>

#include "PseudoPoly.h"
#include "BrutForce.h"
#include "Greedy.h"


using namespace std;

/**
	Gets each token from a line with a space delimiter
	@params str: the line as a string
	@return the numbers as a vector of integers
*/
vector<int> get_tokens(string str) {
	vector<int> dt;
	stringstream ss;
	string tmp; 
	ss << str;
	for (size_t i = 0; !ss.eof(); i++) {
		ss >> tmp;
		int tmpVal = stoi(tmp.c_str());
		dt.push_back(tmpVal);
	}
	return dt;
}


/** 
	Read values from a .txt file
	@params	weight: vector of integers for the weights of each item
			price: vector of integers for the prices of each item
			maxWeight: integer for the maximum weight of the rucksack
			fileName: string for the file name that should be used to get these values
	@return void (values are writen via parameter input (weight, price, maxWeight))
*/
void readFile(vector<int>* weight, vector<int>* price, int* maxWeight, string fileName){

	ifstream infile("assets/" + fileName);
	string line;
	std::getline(infile, line);
	int weightTmp = stoi(line.c_str());
	*maxWeight = weightTmp;
	std::getline(infile, line);
	*weight = get_tokens(line);
	std::getline(infile, line);
	*price = get_tokens(line);
}

int main() {
	string fileName;
	int speedUp;

	cout << "Rucksack - Algorithms" << endl;
	cout << "========================================" << endl << endl;

	while(true){
		// Get user input for filename and speedUp
		cout << "Chose a File (e.g. test.txt):" << endl;
		getline(cin, fileName);
		cout << "Chose the speed up for ptas Algorithm (e.g. 10):" << endl;
		cin >> speedUp;
		cin.ignore(1, '\n');
		cout << endl;

		// Init the parameters for the rucksack problem
		vector<int> weight;
		vector<int> price;
		int maxWeight;

		readFile(&weight, &price, &maxWeight, fileName);

		// Each item must have a price and a weight, thus weight and price size must be equal
		assert(weight.size() == price.size());

		// Create object for each algorithm type and pass the parameters
		IRucksack* ppAlgo = new PseudoPoly(weight, price, maxWeight);
		IRucksack* bfAlgo = new BrutForce(weight, price, maxWeight);
		IRucksack* geAlgo = new Greedy(weight, price, maxWeight);

		// Set Speed Up for the PTAS algorithm
		ppAlgo->setSpeedUp(speedUp);

		// Calculate result with each algorithm (depending on the input size, this might take a while)
		ppAlgo->calculate();
		bfAlgo->calculate();
		geAlgo->calculate();

		// Print Input
		cout << "INPUT: " << endl;
		cout << "Weights: ";
		for(int i=0; i < weight.size(); ++i)
			std::cout << weight[i] << '\t';
		cout << endl;
		cout << "Prices: " << " ";
		for(int i=0; i < price.size(); ++i)
			std::cout << price[i] << "\t";
		cout << endl;
		cout << "Max Weight: " << maxWeight << endl << endl;

		// Print Results
		ppAlgo->printResult();
		bfAlgo->printResult();
		geAlgo->printResult();

		cout << endl << endl;
	}
	return 0;
} 