#include "Connect4View.h"

void Connect4View::setColour(ConsoleColour colour)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

Connect4View::Connect4View(Connect4Model* state) : state(state)
{
}

void Connect4View::displayWelcome()
{
	cout << "Welcome to Connect 4!" << endl;
	cout << "The player 'Red' starts. Their piece is displayed with an 'R'." << endl;
	cout << "The pieces of the player 'Yellow' is displayed with an 'Y'." << endl;
}

void Connect4View::displayBoard()
{

	char piece = ' ';
	for (int i = 0; i < 6; i++) {
		cout << endl << endl;
		for (int j = 0; j < 7; j++) {
			piece = state->getBoard(i, j);
			if (piece == 'R') {
				setColour(RED);
			}
			else if (piece == 'Y') {
				setColour(YELLOW);
			}
			else {
				setColour(WHITE);
			}
			cout << piece << "   ";
		}
	}

	setColour(WHITE);
	cout << endl << endl;
	for (int i = 0; i < 7; i++) {
		cout << i << "   ";
	}
	
	cout << endl << endl;
}

void Connect4View::displayPlayerTurn()
{
	char player = state->getPlayer();
	cout << "Player ";
	if (player == 'R') {
		setColour(RED);
	}
	else if (player == 'Y') {
		setColour(YELLOW);
	}
	else {
		setColour(WHITE);
	}
	cout << player;
	setColour(WHITE);
	cout << "'s turn." << endl;
	cout << "To make a move, please input the row as a number between 0 and 6.";
	cout << endl;
}

void Connect4View::displayDraw()
{
	cout << "Draw! Nobody wins!" << endl;
}

void Connect4View::displayWin()
{
	char player = state->getPlayer();
	cout << "Player ";
	if (player == 'R') {
		setColour(RED);
	}
	else if (player == 'Y') {
		setColour(YELLOW);
	}
	else {
		setColour(WHITE);
	}
	cout << player;
	setColour(WHITE);
	cout << " wins!" << endl;
}
