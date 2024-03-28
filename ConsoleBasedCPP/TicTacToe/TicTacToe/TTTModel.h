#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

using namespace std;

class TTTModel
{
private:

	char board[3][3];
	char player;
	bool isGameOver;

public:
	TTTModel();

	char getBoard(int row, int column);
	void setMove(int row, int column);

	char getPlayer();
	void switchPlayers();

	bool gameWon();
	bool gameDrawn();

	bool getIsGameOver();
	void setIsGameOver(bool in_isGameOver);
};

class TTTInvalidInputException : public exception
{
public:
	TTTInvalidInputException(const char* msg) : exception(msg) {};
};
