#include "MTController.h"

void MTController::askForAmount()
{
	cout << "Please enter the number of calculations you want to do." << endl
		<< "> ";
	
	string input;
	do {
		getline(cin, input);
		removeWhitespace(input);
	} while (input == "");
	cout << endl;

	stringstream inputStream = stringstream(input);
	int amount;

	if ((inputStream >> amount).fail()) throw InvalidInputException("Please input a number!");

	state->setAmountOfCalc(amount);
}

void MTController::askForCalculation()
{
	string input;
	do {
		getline(cin, input);
		removeWhitespace(input);
	} while (input == "");

	stringstream inputStream = stringstream(input);

	int calculation;

	if ((inputStream >> calculation).fail()) throw InvalidInputException("Please input a (valid) number!");

	state->handleInput(calculation);
}

void MTController::removeWhitespace(string& string)
{
	int i = 0;
	int counter = 0;

	while (string[i++] == ' ') {
		counter++;
	}
	string.erase(0, counter);

	if (string == "") {
		return;
	}

	i = (int)string.length() - 1;
	counter = 0;

	while (string[i--] == ' ') {
		counter++;
	}
	string.erase(string.length() - counter, counter);
}

MTController::MTController(MTModel* state, MTView* view) : state(state), view(view)
{

}

void MTController::startGame()
{
	view->displayWelcome();

	while (true) {
		try {
			askForAmount();

			state->startCountingTime();
			state->initializeMultiplications();

			system("cls");

			while (!state->checkIfAllCalcAreCorrect()) {

				try {
					if (!state->checkIfCurrentGuessedCorrectly()) {

						view->displayCurrentMultiplication();
						askForCalculation();

					}
					state->increaseCurrentIndex();

				}
				catch (InvalidInputException& exc) {
					cout << exc.what() << endl << endl;
				}

			}

			view->displayRoundFinished();

			Sleep(7000);
			system("cls");
			state->resetValues();
		}
		catch (InvalidInputException& exc) {
			cout << exc.what() << endl << endl;
		}
	}
	/*
		//welcome, tutorial

		//loop
		//ask user for the amount of calculation they want to do
			// validate the input
			// with input, create the necessary amount of calculations

		//loop if all calculations were done correctly
			//loop going through the calculations
				//check if current calculation was not correctly calculated
					//yes, ask calcuation
						//ask for input
							// validate the input
							// process the input
							// wrong or correct
					//no, do nothing
				//increase counter
			//when all calculations are done, give some stats (error count, percentage, etc.)
	*/

}
