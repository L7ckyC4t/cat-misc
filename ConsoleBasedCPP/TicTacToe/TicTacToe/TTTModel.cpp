#include "TTTModel.h"

TTTModel::TTTModel()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 'e';
		}
	}
	isGameOver = false;

	player = 'x';
}

char TTTModel::getBoard(int row, int column)
{
	return board[row][column];
}

void TTTModel::setMove(int row, int column)
{
	board[row][column] = player;
}

char TTTModel::getPlayer()
{
	return player;
}

void TTTModel::switchPlayers()
{
	player = ((player == 'x') ? 'o' : 'x');
}

bool TTTModel::gameWon()
{
	for (int row = 0; row < 3; row++) {
		if (board[row][0] != 'e'
			&& board[row][0] == board[row][1]
			&& board[row][1] == board[row][2]) {
			return true;
		}
	}

	for (int column = 0; column < 3; column++) {
		if (board[0][column] != 'e'
			&& board[0][column] == board[1][column]
			&& board[1][column] == board[2][column]) {
			return true;
		}
	}

	if (board[0][0] != 'e'
		&& board[0][0] == board[1][1]
		&& board[1][1] == board[2][2]) {
		return true;
	}
	if (board[0][2] != 'e'
		&& board[0][2] == board[1][1]
		&& board[1][1] == board[2][0]) {
		return true;
	}

	return false;
}

bool TTTModel::gameDrawn()
{
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == 'e') {
				return false;
			}
		}
	}
	return true;
}

bool TTTModel::getIsGameOver()
{
	return isGameOver;
}

void TTTModel::setIsGameOver(bool in_isGameOver)
{
	isGameOver = in_isGameOver;
}
