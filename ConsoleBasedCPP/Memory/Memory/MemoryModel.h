#pragma once
#include "InvalidInputException.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class MemoryModel
{
private:
	int* pairs;
	int* guessPairs;

	int numberOfElements;

	bool allGuessed;

	int errorCount;

	void initializeAllPairs();
	void shufflePairs();

public:
	MemoryModel();
	~MemoryModel();


	int getNumberOfElements();

	int getPairsElement(int index);
	int getGuessPairsElement(int index);

	int getErrorCount();

	bool getAllGuessed();
	bool checkIfAllGuessed();

	void resetValuesAndReinitializeAllPairs();

	void handleInput(int index1, int index2);
	void revealGuess(int index1, int index2);
};

