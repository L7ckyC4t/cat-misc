#pragma once
#include "Connect4Model.h"
#include "Connect4View.h"


class Connect4Controller
{
private:
	Connect4Model* state;
	Connect4View* view;

	void removeWhitespace(string& input);
	void getMove(string& move);
	void validateMove(stringstream& moveStream, int& column);

public:
	Connect4Controller(Connect4Model* state, Connect4View* view);

	void playGame();
};

