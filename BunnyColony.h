//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNYCOLONY_H
#define BUNNY_BUNNYCOLONY_H

#include <vector>
#include "Bunny.h"
#include "BunnyGenerator.h"

struct Node {
    Bunny* b;
    Node* next;
};

class BunnyColony {

//    vector<Bunny *> root;
    Node*root = nullptr;

    BunnyGenerator bunnyGenerator;

    void ageBunnies();

    // although calling size on a vector is O(1), we still need to know the mix
    int maleCount = 0;
    int femaleCount = 0;

    void foodShortage();
    void removeBunnyFromCount(Bunny* b);

public:
    void nextTurn(const int &iteration);

    void addBunny(Bunny *pBunny);

    void procreate();

    void seed();


    int getMaleCount() const {
        return maleCount;
    }

    int getFemaleCount() const {
        return femaleCount;
    }
};


#endif //BUNNY_BUNNYCOLONY_H
