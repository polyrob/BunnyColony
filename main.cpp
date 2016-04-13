#include <iostream>
#include <time.h>
#include "BunnyColony.h"

int main() {

    srand(time(NULL));

    BunnyColony colony;
    colony.seed();


    int turn = 0;
    colony.printStatus(turn);

    while (colony.getMaleCount() > 0 && colony.getFemaleCount() > 0) {
        colony.nextTurn();
        ++turn;
        colony.printStatus(turn);

        if (turn > 1000) break;
    }

    std::cout << "End..." << std::endl;
}