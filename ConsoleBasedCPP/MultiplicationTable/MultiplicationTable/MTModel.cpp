#include "MTModel.h"

MTModel::MTModel()
{
	srand(time(NULL));
	amountOfCalc = 0;
	currentIndex = 0;
}

MTModel::~MTModel()
{
	delete[] multiplications;
}

void MTModel::setAmountOfCalc(int amount)
{
	amountOfCalc = amount;
}

int MTModel::getCurrentIndex()
{
	return currentIndex;
}

void MTModel::increaseCurrentIndex()
{
	currentIndex++;
	if (currentIndex == amountOfCalc) {
		currentIndex = 0;
		system("cls");
	}
}

int MTModel::getErrorCount()
{
	return errorCount;
}

int MTModel::getAmountOfCalc()
{
	return amountOfCalc;
}

Multiplication MTModel::getCurrentMultiplication()
{
	return multiplications[currentIndex];
}

void MTModel::handleInput(int calc)
{
	if (multiplications[currentIndex].factor1 * multiplications[currentIndex].factor2 == calc) {
		multiplications[currentIndex].guessedCorrectly = true;
		cout << "Correct! :D" << endl << endl;
	}
	else {
		errorCount++;
		cout << "Incorrect! :(" << endl << endl;
	}
}

void MTModel::startCountingTime()
{
	startTime = chrono::system_clock::now();
}

chrono::system_clock::time_point MTModel::getStartTime()
{
	return startTime;
}

void MTModel::initializeMultiplications()
{
	multiplications = new Multiplication[amountOfCalc]();
}

bool MTModel::checkIfAllCalcAreCorrect()
{
	for (int i = 0; i < amountOfCalc; i++) {
		if (!multiplications[i].guessedCorrectly) {
			return false;
		}
	}
	return true;
}

bool MTModel::checkIfCurrentGuessedCorrectly()
{
	return multiplications[currentIndex].guessedCorrectly;
}

void MTModel::resetValues()
{
	delete[] multiplications;
	currentIndex = 0;
	amountOfCalc = 0;
	errorCount = 0;
}
