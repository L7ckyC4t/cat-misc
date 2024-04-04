#include "MTView.h"

MTView::MTView(MTModel* state) : state(state)
{
}

void MTView::displayWelcome()
{
	cout << "Welcome to Multiplication Table Calculation!" << endl
		<< "In this program, you need to calculate a set amount of multiplications from (0 x 0) to (9 x 9)." << endl
		<< "The amount is set by you." << endl << endl;
}

void MTView::displayCurrentMultiplication()
{
	cout << state->getCurrentIndex() + 1 << ". " 
		<< state->getCurrentMultiplication().factor1 << " * " << state->getCurrentMultiplication().factor2 << " = ";
}

void MTView::displayRoundFinished()
{
	float correctNumber = (float)state->getAmountOfCalc() - state->getErrorCount();
	float percentage = (correctNumber / state->getAmountOfCalc()) * 100;
	float formattedPercentage = (int)(percentage * 100) / 100.f;

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - state->getStartTime();

	cout << "Congratulations! You finished a round. Here are some stats: " << endl
		<< "Number of errors: " << state->getErrorCount() << "/" << state->getAmountOfCalc() << endl
		<< "Success rate: " << formattedPercentage << "%" << endl
		<< "It took you around " << elapsed_seconds.count() << "s to do all calculations." << endl;
}
