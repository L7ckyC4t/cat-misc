#pragma once
#include "MemoryModel.h"
#include "MemoryView.h"

class MemoryController
{
private:
	MemoryModel* state;
	MemoryView* view;

	void removeWhitespace(string& string);
	void askInput();

public:
	MemoryController(MemoryModel* state, MemoryView* view);

	void startGame();
};

