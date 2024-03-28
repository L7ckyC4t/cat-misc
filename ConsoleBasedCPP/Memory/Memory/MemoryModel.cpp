#include "MemoryModel.h"

void MemoryModel::initializeAllPairs()
{
	pairs = new int[numberOfElements];
	guessPairs = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i += 2) {
		pairs[i] = i / 2 + 1;
		pairs[i + 1] = i / 2 + 1;
	}

	for (int i = 0; i < numberOfElements; i++) {
		guessPairs[i] = -1;
	}
}

void MemoryModel::shufflePairs()
{
	int randomNumber;
	for (int i = 0; i < numberOfElements; i++) {
		for (int j = numberOfElements - 1; j >= 0; j--) {
			randomNumber = rand() % (numberOfElements / 2) + 1;
			if (pairs[j] == randomNumber) {
				pairs[j] = pairs[numberOfElements - 1];
				pairs[numberOfElements - 1] = randomNumber;
			}
		}
	}
}

MemoryModel::MemoryModel()
{
	srand(time(NULL));
	allGuessed = false;
	numberOfElements = 6;
	errorCount = 0;

	initializeAllPairs();
	shufflePairs();
}

MemoryModel::~MemoryModel()
{
	delete[] pairs;
	delete[] guessPairs;
}

int MemoryModel::getNumberOfElements()
{
	return numberOfElements;
}

int MemoryModel::getPairsElement(int index)
{
	return pairs[index];
}

int MemoryModel::getGuessPairsElement(int index)
{
	return guessPairs[index];
}

int MemoryModel::getErrorCount()
{
	return errorCount;
}

bool MemoryModel::getAllGuessed()
{
	return allGuessed;
}

bool MemoryModel::checkIfAllGuessed()
{
	for (int i = 0; i < numberOfElements; i++) {
		if (guessPairs[i] == -1) {
			return false;
		}
	}

	return true;
}

void MemoryModel::resetValuesAndReinitializeAllPairs()
{
	delete[] pairs;
	delete[] guessPairs;

	numberOfElements += 2;

	initializeAllPairs();
	shufflePairs();

	allGuessed = false;
	errorCount = 0;
}

void MemoryModel::handleInput(int index1, int index2)
{
	if (pairs[index1] == pairs[index2]) {
		cout << "Correct guess :D" << endl << endl;
		revealGuess(index1, index2);
		allGuessed = checkIfAllGuessed();
	}
	else {
		cout << "Incorrect guess :(" << endl << endl;
		errorCount++;
	}
}

void MemoryModel::revealGuess(int index1, int index2)
{
	guessPairs[index1] = pairs[index1];
	guessPairs[index2] = pairs[index2];
}
