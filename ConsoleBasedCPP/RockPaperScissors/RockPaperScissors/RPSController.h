#pragma once

#include "RPSModel.h"
#include "RPSView.h"

class RPSController
{
private:
	RPSModel* state;
	RPSView* view;

public:
	RPSController(RPSModel* state, RPSView* view);

	void startGame();

};

