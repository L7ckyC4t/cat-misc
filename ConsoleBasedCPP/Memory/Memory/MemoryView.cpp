#include "MemoryView.h"

MemoryView::MemoryView(MemoryModel* state): state(state)
{
}

void MemoryView::displayBegin()
{
	cout << "Welcome to Memory!" << endl
		<< "How this game works: You will see a sequence of pair numbers that you need to remember." << endl
		<< "This sequence is shown for 10 seconds, then it disappears." << endl
		<< "Then you will need to input the places where you think a pair is (starting from 0)" << endl
		<< "An example for your input would be: '0 2'" << endl
		<< "Good luck!";
}

void MemoryView::displayPairs()
{
	for (int i = 0; i < state->getNumberOfElements(); i++) {
		cout << i << ": " << state->getPairsElement(i) 
			<< "    ";
	}
}

void MemoryView::displayGuessPairs()
{
	for (int i = 0; i < state->getNumberOfElements(); i++) {
		cout << i << ": " << ((state->getGuessPairsElement(i) == -1) ? "?" : to_string(state->getGuessPairsElement(i))) 
			<< "    ";
	}
	
	cout << endl << endl;
}

void MemoryView::displayCongrats()
{
	cout << "Congrats! You guessed all pairs! If you want to stop the game press Ctrl + C." << endl
		<< "Else a new round start with a new pair." << endl;
}

void MemoryView::displayErrorCount()
{
	cout << "You have guessed " << state->getErrorCount() << " times wrong." << endl;
}
