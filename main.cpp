#include <iostream>
#include <time.h>
#include "BunnyColony.h"
#include "BunnyGenerator.h"

int main() {

    srand(time(NULL));

    BunnyColony colony;
    BunnyGenerator bunnyGenerator;

    // init with 5 bunnies
    for (int i = 0; i < 5; ++i) {
        Bunny* b = bunnyGenerator.makeRandomBunny();
        colony.addBunny(b);
        b->printInfo();
    }

    colony.printStatus();


}