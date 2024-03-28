#include "TTTView.h"

TTTView::TTTView(TTTModel* state) : state(state)
{
}

void TTTView::displayGameStart()
{
	cout << "Welcome to a game of TicTacToe! Player " << state->getPlayer() << " starts!" << endl << endl;
}

void TTTView::displayBoard()
{
	cout << " ";
	for (int column = 0; column < 3; column++) {
		cout.width(5);
		cout << column;
	}
	cout << endl << endl;



	for (int row = 0; row < 3; row++) {
		cout << row;

		//board itself
		for (int column = 0; column < 3; column++) {
			cout.width(5);
			cout << state->getBoard(row, column);
		}

		cout << endl << endl;
	}

	cout << endl;
}

void TTTView::displayPlayer()
{
	cout << "Player " << state->getPlayer() << " to play!" << endl << endl;
}

void TTTView::displayInstructions()
{
	cout << "Please input the row and the column of your move! For example, '1 0' would be a valid move." << endl;
}

void TTTView::displayWinner()
{
	cout << "Player " << state->getPlayer() << " wins!" << endl;
}

void TTTView::displayDraw()
{
	cout << "Draw! Nobody wins!" << endl;
}
