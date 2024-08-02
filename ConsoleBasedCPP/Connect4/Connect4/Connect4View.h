#pragma once
#include "Connect4Model.h"

enum ConsoleColour {
    BLACK = 0,
    DARK_BLUE = 1,
    DARK_GREEN = 2,
    DARK_CYAN = 3,
    DARK_RED = 4,
    DARK_MAGENTA = 5,
    DARK_YELLOW = 6,
    LIGHT_GRAY = 7,
    DARK_GRAY = 8,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

class Connect4View
{
private:
	Connect4Model* state;

    void setColour(ConsoleColour colour);

public:
	Connect4View(Connect4Model* state);

	void displayWelcome();
	void displayBoard();
    void displayPlayerTurn();
    void displayDraw();
    void displayWin();
};

