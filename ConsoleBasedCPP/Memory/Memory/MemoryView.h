#pragma once
#include "MemoryModel.h"

class MemoryView
{
private:
	MemoryModel* state;

public:
	MemoryView(MemoryModel* state);

	void displayBegin();
	void displayPairs();
	void displayGuessPairs();

	void displayCongrats();
	void displayErrorCount();
};

