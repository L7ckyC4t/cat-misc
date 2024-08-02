#include "Connect4Model.h"

Connect4Model::Connect4Model()
{
	player = 'R';
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = 'e';
		}
	}
}

char Connect4Model::getBoard(int row, int column)
{
	return board[row][column];
}

char Connect4Model::getPlayer()
{
	return player;
}

void Connect4Model::placePiece(int column)
{
	if (board[0][column] != 'e') throw Connect4Exception("Column already full! Please place somewhere else!");
	for (int row = 5; row >= 0; row--) {
		if (board[row][column] == 'e') {
			board[row][column] = player;
			break;
		}
	}

}

void Connect4Model::switchPlayer()
{
	(player == 'R') ? player = 'Y' : player = 'R';
}

bool Connect4Model::checkDraw()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (board[i][j] == 'e') {
				return false;
			}
		}
	}
	return true;
}

bool Connect4Model::checkWin()
{
	for (int row = 0; row < 6; row++) {
		for (int j = 0; j < 4; j++) {
			if (board[row][j] != 'e'
				&& board[row][j] == board[row][j + 1]
				&& board[row][j + 1] == board[row][j + 2]
				&& board[row][j + 2] == board[row][j + 3]) {
				return true;
			}
		}
	}

	for (int column = 0; column < 7; column++) {
		for (int j = 0; j < 3; j++) {
			if (board[j][column] != 'e'
				&& board[j][column] == board[j + 1][column]
				&& board[j + 1][column] == board[j + 2][column]
				&& board[j + 2][column] == board[j + 3][column]) {
				return true;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 'e'
				&& board[i][j] == board[i + 1][j + 1]
				&& board[i + 1][j + 1] == board[i + 2][j + 2]
				&& board[i + 2][j + 2] == board[i + 3][j + 3]) {
				return true;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 7; j++) {
			if (board[i][j] != 'e'
				&& board[i][j] == board[i + 1][j - 1]
				&& board[i + 1][j - 1] == board[i + 2][j - 2]
				&& board[i + 2][j - 2] == board[i + 3][j - 3]) {
				return true;
			}
		}
	}

	return false;
}
