#include <iostream>
#include <time.h>
#include "BunnyColony.h"

int main() {
    srand(time(NULL));          // init new random seed

    BunnyColony colony;         // create our colony
    colony.seed();              // add first 5 random bunnies

    int turn = 0;

    while (colony.getMaleCount()+colony.getFemaleCount() > 0) {
        colony.nextTurn(++turn);

        if (turn >= 500) break; // tmp safety just in case we don't break loop
    }

    std::cout << "\n # Completed in " << turn << " turns.\n";
    return 0;
}
