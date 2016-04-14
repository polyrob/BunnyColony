#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BunnyColony.h"
#include "Bunny.h"

int main() {
    srand(time(NULL));        // init new random seed

    BunnyColony colony;
    colony.seed();            // add first 5 random bunnies

    int turn = 0;

    while (colony.getMaleCount() > 0 && colony.getFemaleCount() > 0) {
        colony.nextTurn(++turn);
        if (turn >= 100)
            break;
    }

    std::cout << "\nEnd.\n";
    return 0;
}
