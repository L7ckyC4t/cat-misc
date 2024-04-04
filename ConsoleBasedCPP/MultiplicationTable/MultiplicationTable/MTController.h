#pragma once
#include "MTModel.h"
#include "MTView.h"


class MTController
{
private:

	MTModel* state;
	MTView* view;

	void askForAmount();
	void askForCalculation();

	void removeWhitespace(string& string);

public:
	MTController(MTModel* state, MTView* view);

	void startGame();

};

