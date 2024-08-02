#include "Connect4Controller.h"

void Connect4Controller::removeWhitespace(string& input)
{
	int i = 0;
	int counter = 0;

	while (input[i++] == ' ') {
		counter++;
	}
	input.erase(0, counter);

	if (input == "") return;

	i = (int)input.length() - 1;
	counter = 0;

	while (input[i--] == ' ') {
		counter++;
	}
	input.erase(input.length() - counter, counter);
}

void Connect4Controller::getMove(string& move)
{
	cout << "> ";
	do {
		getline(cin, move);
		removeWhitespace(move);
	} while (move == "");
}

void Connect4Controller::validateMove(stringstream& moveStream, int& column)
{
	if ((moveStream >> column).fail()) throw Connect4Exception("Please input a number between 0 and 6!");
	if (moveStream.peek() != EOF) throw Connect4Exception("Please only input ONE number!");
	if (column < 0 || column > 6) throw Connect4Exception("The number must be between 0 and 6!");
}

Connect4Controller::Connect4Controller(Connect4Model* state, Connect4View* view) : state(state), view(view)
{
}

void Connect4Controller::playGame()
{
	view->displayWelcome();

	while (true) {
		string move;
		int column = 0;
		view->displayBoard();
		view->displayPlayerTurn();
		getMove(move);
		stringstream moveStream = stringstream(move);
		try {
			validateMove(moveStream, column);
			state->placePiece(column);

			if (state->checkDraw()) {
				system("cls");
				view->displayBoard();
				view->displayDraw();

				break;
			}
			else if (state->checkWin()) {
				system("cls");
				view->displayBoard();
				view->displayWin();
				break;
			}
			else {
				state->switchPlayer();
			}
		}
		catch (Connect4Exception& exc) {
			system("cls");
			cout << exc.what();
			Sleep(1000);
			system("cls");
		}

		system("cls");
	}


}
