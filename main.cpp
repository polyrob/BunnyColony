#include <iostream>
#include <time.h>
#include "BunnyColony.h"
#include "BunnyGenerator.h"

int main() {

    srand(time(NULL));

    BunnyColony colony;
    colony.seed();


    int itr = 0;
    colony.printStatus(itr);

    while (true)
    {
        colony.nextTurn();
        ++itr;
        colony.printStatus(itr);
        if (itr > 100) break;
    }

    std::cout<< "End...";
}