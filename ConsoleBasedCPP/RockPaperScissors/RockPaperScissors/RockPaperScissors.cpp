#include <iostream>
#include "RPSModel.h"
#include "RPSController.h"
#include "RPSView.h"

using namespace std;

int main()
{
    RPSModel m = RPSModel();
    RPSView v = RPSView(&m);
    RPSController c = RPSController(&m, &v);

    c.startGame();

    return 0;
}
