#include <iostream>
#include <time.h>
#include "BunnyColony.h"

int main() {

    srand(time(NULL));

    BunnyColony colony;
    colony.seed();


    int itr = 0;
    colony.printStatus(itr);

    while (colony.getMaleCount() > 0 && colony.getFemaleCount() > 0) {
        colony.nextTurn();
        ++itr;
        colony.printStatus(itr);
        if (itr % 10 == 0) system("pause"); // stop every 10 turns
    }

    std::cout << "End...";
}