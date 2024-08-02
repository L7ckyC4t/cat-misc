#include <iostream>
#include "Connect4Model.h"
#include "Connect4View.h"
#include "Connect4Controller.h"

int main()
{
    Connect4Model m = Connect4Model();
    Connect4View v = Connect4View(&m);
    Connect4Controller c = Connect4Controller(&m, &v);

    c.playGame();
    return 0;
}

