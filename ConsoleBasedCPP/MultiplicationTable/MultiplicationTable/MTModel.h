#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <chrono>

using namespace std;

class InvalidInputException : public exception {
public:
	InvalidInputException(const char* msg) : exception(msg) {};
};


struct Multiplication {
	int factor1, factor2;
	bool guessedCorrectly;

	Multiplication() {
		factor1 = rand() % 10;
		factor2 = rand() % 10;
		guessedCorrectly = false;
	}
};

class MTModel
{
private:
	Multiplication* multiplications;

	int amountOfCalc, currentIndex;
	int errorCount;
	chrono::system_clock::time_point startTime;

public:
	MTModel();
	~MTModel();

	void setAmountOfCalc(int amount);

	int getCurrentIndex();
	void increaseCurrentIndex();

	int getErrorCount();
	int getAmountOfCalc();

	Multiplication getCurrentMultiplication();

	void handleInput(int calc);

	void startCountingTime();
	chrono::system_clock::time_point getStartTime();

	void initializeMultiplications();

	bool checkIfAllCalcAreCorrect();

	bool checkIfCurrentGuessedCorrectly();

	void resetValues();
};

