//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNYCOLONY_H
#define BUNNY_BUNNYCOLONY_H


#include <vector>
#include "Bunny.h"
#include "BunnyGenerator.h"

class BunnyColony {

    vector<Bunny*> bunnies;

    BunnyGenerator bunnyGenerator;

    void ageBunnies();
//    int getFemaleCount();

    int maleCount = 0;
    int femaleCount = 0;

    void foodShortage();

public:
    void nextTurn();


    void addBunny(Bunny *pBunny);

    void printStatus(const int& iteration);

    void killOldBunnies();

    void procreate();

    void seed();
};


#endif //BUNNY_BUNNYCOLONY_H
