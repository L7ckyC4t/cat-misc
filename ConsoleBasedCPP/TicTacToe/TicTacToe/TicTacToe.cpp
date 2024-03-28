#include <iostream>
#include "TTTController.h"
#include "TTTModel.h"
#include "TTTView.h"

using namespace std;

int main()
{
    TTTModel m;
    TTTView v = TTTView(&m);
    TTTController c = TTTController(&m, &v);

    c.startGame();
    cin.get();
    return 0;
}