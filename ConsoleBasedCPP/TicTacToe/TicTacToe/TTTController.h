#pragma once
#include "TTTModel.h"
#include "TTTView.h"

using namespace std;

class TTTController
{

private:
	TTTModel* state;
	TTTView* view;

	void removeWhitespace(string& string);
	void askInput(string& move);

public:
	TTTController(TTTModel* state, TTTView* view);

	void startGame();



};

