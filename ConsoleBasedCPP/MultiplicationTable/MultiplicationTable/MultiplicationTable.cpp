#include <iostream>
#include "MTModel.h";
#include "MTController.h"
#include "MTView.h"

using namespace std;

int main()
{
    MTModel m = MTModel();
    MTView v = MTView(&m);
    MTController c = MTController(&m, &v);

    c.startGame();

    cin.get();
}
