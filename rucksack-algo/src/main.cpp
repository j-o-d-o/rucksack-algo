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
		cout << "Chose a File (e.g. test.txt):" << endl;
		getline(cin, fileName);
		cout << "Chose the speed up for ptas Algorithm (e.g. 10):" << endl;
		cin >> speedUp;
		cin.ignore(1, '\n');
		cout << endl;

		vector<int> weight;
		vector<int> price;
		int maxWeight;

		readFile(&weight, &price, &maxWeight, fileName);
		assert(weight.size() == price.size());

		IRucksack* ppAlgo = new PseudoPoly(weight, price, maxWeight);
		IRucksack* bfAlgo = new BrutForce(weight, price, maxWeight);
		IRucksack* geAlgo = new Greedy(weight, price, maxWeight);

		// Speed Up
		ppAlgo->setSpeedUp(speedUp);

		// Start Algorithms
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