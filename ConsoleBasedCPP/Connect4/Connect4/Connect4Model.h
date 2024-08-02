#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Connect4Exception.h"
#include <stdlib.h> 

using namespace std;
class Connect4Model
{
private:
	char board[6][7];
	char player;

public:
	Connect4Model();

	char getBoard(int row, int column);
	char getPlayer();

	void placePiece(int column);
	void switchPlayer();
	bool checkDraw();
	bool checkWin();
};

