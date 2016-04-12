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
    virtual ~BunnyGenerator() { std::cout << "NameGenerator Destructor called..." << std::endl; }

    Bunny *makeRandomBunny();

    Bunny *makeBunnyFromParent(const Bunny *b);

};


#endif //BUNNY_BUNNYGENERATOR_H
