#pragma once
#include "TTTModel.h"

using namespace std;

class TTTView
{
private:
	TTTModel* state;

public:
	TTTView(TTTModel* state);

	void displayGameStart();
	void displayBoard();
	void displayPlayer();
	void displayInstructions();
	void displayWinner();
	void displayDraw();
};

