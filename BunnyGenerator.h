//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNYGENERATOR_H
#define BUNNY_BUNNYGENERATOR_H

#include <random>
#include "Bunny.h"
#include "NameGenerator.h"

class BunnyGenerator {

    NameGenerator *nameGenerator;

    std::default_random_engine generator;
    std::normal_distribution<double> distribution;


public:

    BunnyGenerator();
    virtual ~BunnyGenerator();

    Bunny *makeBunny(const Bunny *b);
    Bunny *makeBunny();

//    Bunny *makeBunnyFromParent(const Bunny *b);

};


#endif //BUNNY_BUNNYGENERATOR_H
