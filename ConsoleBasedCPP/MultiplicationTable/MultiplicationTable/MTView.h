#pragma once
#include "MTModel.h"


class MTView
{
private:

	MTModel* state;

public:

	MTView(MTModel* state);

	void displayWelcome();
	void displayCurrentMultiplication();
	void displayRoundFinished();
};

