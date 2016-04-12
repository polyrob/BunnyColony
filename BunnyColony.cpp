//
// Created by NewRob on 4/11/2016.
//

#include <iostream>
#include "BunnyColony.h"


void BunnyColony::addBunny(Bunny *pBunny) {
    bunnies.push_back(pBunny);
    if (pBunny->getSex() == Bunny::MALE) {
        ++maleCount;
    } else {
        ++femaleCount;
    }
}

void BunnyColony::printStatus(const int &iteration) {
    std::cout << "*** ITERATION " << iteration << std::endl;
    std::cout << " Colony Size: " << bunnies.size() << ", M/F: " << maleCount << "/" << femaleCount << std::endl;

}

void BunnyColony::nextTurn() {
    ageBunnies();
    killOldBunnies();
    procreate();
    if (maleCount + femaleCount > 1000) {
        foodShortage();
    }
}

void BunnyColony::ageBunnies() {
    for (auto &value: bunnies) {
        value->setAge(value->getAge() + 1);
    }
}

void BunnyColony::killOldBunnies() {
    for (vector<Bunny *>::iterator itr = bunnies.begin(); itr != bunnies.end();) {
        Bunny *b = *itr;
        if (b->getAge() > 10) {
            bunnies.erase(itr);
            if (b->getSex() == Bunny::MALE) {
                --maleCount;
            } else {
                --femaleCount;
            }
            delete (b);
        } else {
            ++itr;
        }
    }
}

void BunnyColony::procreate() {
    // get males and females over age 2
    vector<Bunny *> adultMales;
    vector<Bunny *> adultFemales;

    for (Bunny *b : bunnies) {
        if (b->getAge() > 1) {
            if (b->getSex() == Bunny::MALE) {
                adultMales.push_back(b);
            } else {
                adultFemales.push_back(b);
            }
        }
    }

    // check at least one adult male
    if (adultMales.size() > 0) {
        for (Bunny *b : adultFemales) {
            addBunny(bunnyGenerator.makeBunnyFromParent(b));
        }
    }
}

void BunnyColony::foodShortage() {
    for (vector<Bunny *>::iterator itr = bunnies.begin(); itr != bunnies.end();) {
        if (rand() % 2) {
            Bunny *b = *itr;
            bunnies.erase(itr);
            if (b->getSex() == Bunny::MALE) {
                --maleCount;
            } else {
                --femaleCount;
            }
            delete (b);
        } else {
            ++itr;
        }
    }
}

void BunnyColony::seed() {
    // init with 5 bunnies
    for (int i = 0; i < 5; ++i) {
        Bunny* b = bunnyGenerator.makeRandomBunny();
        this->addBunny(b);
        b->printInfo();
    }
}

















