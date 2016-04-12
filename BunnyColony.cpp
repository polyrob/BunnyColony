//
// Created by NewRob on 4/11/2016.
//

#include <iostream>
#include "BunnyColony.h"

void addBunny(Bunny *pBunny) {

}


void BunnyColony::addBunny(Bunny *pBunny) {
    bunnies.push_back(pBunny);
}

void BunnyColony::printStatus() {
    std::cout << " Colony Size: " << bunnies.size() << std::endl;
    int femaleCount = getFemaleCount();
    std::cout << " Males:   " << bunnies.size()-femaleCount << std::endl;
    std::cout << " Females: " << femaleCount << std::endl;

}

int BunnyColony::getFemaleCount() {
    int count = 0;
    for(auto const& value: bunnies) {
        if (value->getSex() == Bunny::FEMALE)
            count++;
    }
    return count;
}





