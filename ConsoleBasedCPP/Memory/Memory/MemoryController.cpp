#include "MemoryController.h"

void MemoryController::removeWhitespace(string& string)
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

void MemoryController::askInput()
{
	string move;
	cout << "Your guess" << endl;
	cout << "> ";
	do {
		getline(cin, move);
		removeWhitespace(move);
	} while (move == "");
	cout << endl;

	stringstream moveStream = stringstream(move);

	int index1, index2;
	if ((moveStream >> index1).fail()) throw InvalidInputException("Invalid first index!");
	if ((moveStream >> index2).fail()) throw InvalidInputException("Invalid second index!");
	if (moveStream.peek() != EOF) throw InvalidInputException("Only 2 arguments allowed!");

	if (index1 < 0 || index1 >= state->getNumberOfElements() || index2 < 0 || index2 >= state->getNumberOfElements())
		throw InvalidInputException("Please put in a number between 0 and the maximum!");

	if (state->getGuessPairsElement(index1) != -1 || state->getGuessPairsElement(index2) != -1)
		throw InvalidInputException("You already guesse at least one element!");

	state->handleInput(index1, index2);
}

MemoryController::MemoryController(MemoryModel* state, MemoryView* view) : state(state), view(view)
{
}

void MemoryController::startGame()
{

	view->displayBegin();
	Sleep(5000);
	system("cls");


	while (true) {
		view->displayPairs();
		Sleep(10000);
		system("cls");

		while (!state->getAllGuessed()) {
			view->displayGuessPairs();

			try {
				askInput();
			}
			catch (InvalidInputException& exc) {
				cout << exc.what() << endl << endl;
			}
		}
		
		view->displayCongrats();
		view->displayErrorCount();
		Sleep(5000);
		system("cls");
		state->resetValuesAndReinitializeAllPairs();
	}
}
