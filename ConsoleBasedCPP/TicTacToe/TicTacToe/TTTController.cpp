#include "TTTController.h"

void TTTController::removeWhitespace(string& string)
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

void TTTController::askInput(string& move)
{
	cout << "> ";
	do {
		getline(cin, move);
		removeWhitespace(move);
	} while (move == "");
	cout << endl;


	stringstream moveStream = stringstream(move);

	int row, column;
	if ((moveStream >> row).fail()) throw TTTInvalidInputException("Invalid row!");
	if ((moveStream >> column).fail()) throw TTTInvalidInputException("Invalid column!");
	if (moveStream.peek() != EOF) throw TTTInvalidInputException("Only 2 arguments allowed!");

	if (row < 0 || row > 2 || column < 0 || column > 2) throw TTTInvalidInputException("Input a number between 0 and 2!");
	if (state->getBoard(row, column) != 'e') throw TTTInvalidInputException("Make a move on an empty place!");

	state->setMove(row, column);
}

TTTController::TTTController(TTTModel* state, TTTView* view) : state(state), view(view)
{
}

void TTTController::startGame()
{
	view->displayGameStart();


	while (!state->getIsGameOver()) {
		view->displayBoard();
		view->displayPlayer();
		view->displayInstructions();

		string move;
		do {
			try {
				askInput(move);
			}
			catch (TTTInvalidInputException& exc) {
				move = "";
				cout << exc.what() << endl << endl;
			}
		} while (move == "");

		
		if (state->gameWon()) {
			view->displayBoard();
			view->displayWinner();
			state->setIsGameOver(true);
		}
		else if (state->gameDrawn()) {
			view->displayBoard();
			view->displayDraw();
			state->setIsGameOver(true);

		}
		else {
			state->switchPlayers();
		}
	}
}