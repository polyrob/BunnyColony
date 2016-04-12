//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNYCOLONY_H
#define BUNNY_BUNNYCOLONY_H


#include <vector>
#include "Bunny.h"

class BunnyColony {

    vector<Bunny*> bunnies;

    int getFemaleCount();

    void foodShortage();

public:
    void nextTurn();


    void addBunny(Bunny *pBunny);

    void printStatus();
};


#endif //BUNNY_BUNNYCOLONY_H
