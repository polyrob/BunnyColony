#include <iostream>
#include <time.h>
#include "BunnyColony.h"

int main() {
    srand(time(NULL));          // init new random seed

    BunnyColony colony;         // create our colony
    colony.seed();              // add first 5 random bunnies

    int turn = 0;

    while (colony.getMaleCount() > 0 && colony.getFemaleCount() > 0) {
        colony.nextTurn(++turn);
    }

    std::cout << "\n # Completed in " << turn << " turns.\n";
    return 0;
}
