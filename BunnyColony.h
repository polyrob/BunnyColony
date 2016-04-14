//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNYCOLONY_H
#define BUNNY_BUNNYCOLONY_H

#include <vector>
#include "Bunny.h"
#include "BunnyGenerator.h"

struct Node {
    Bunny *b;
    Node *next;
};

class BunnyColony {

    Node *root = nullptr;
    unsigned int maleCount = 0;
    unsigned int femaleCount = 0;
    unsigned int mutantCount = 0;

    BunnyGenerator bunnyGenerator;

    void ageBunnies();
    void foodShortage();
    void removeBunnyFromCount(Bunny *b);
    void mutateBunnies();
    std::vector<Bunny *> getNonMutantBunnies();

public:
    void nextTurn(const int &iteration);
    void addBunny(Bunny *pBunny);
    void procreate();
    void seed();

    int getMaleCount() const { return maleCount; }
    int getFemaleCount() const { return femaleCount; }
};

#endif //BUNNY_BUNNYCOLONY_H
