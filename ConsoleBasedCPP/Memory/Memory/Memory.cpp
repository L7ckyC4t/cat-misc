#include "MemoryModel.h"
#include "MemoryController.h"
#include "MemoryView.h"
using namespace std;

int main()
{
	MemoryModel m = MemoryModel();
	MemoryView v = MemoryView(&m);
	MemoryController c = MemoryController(&m, &v);

	c.startGame();

	return 0;
}
