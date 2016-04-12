//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNYGENERATOR_H
#define BUNNY_BUNNYGENERATOR_H

#include "Bunny.h"
#include "NameGenerator.h"

class BunnyGenerator {

    NameGenerator *nameGenerator;

public:

    BunnyGenerator();
    virtual ~BunnyGenerator() { std::cout << "NameGenerator Destructor called..."; }

    Bunny *makeRandomBunny();

    Bunny *makeBunnyFromParents(const Bunny &b1, const Bunny &b2);

};


#endif //BUNNY_BUNNYGENERATOR_H
