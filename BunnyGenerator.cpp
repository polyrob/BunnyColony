//
// Created by NewRob on 4/11/2016.
//

#include "BunnyGenerator.h"
#include <stdlib.h>
#include "Enum.h"

BunnyGenerator::BunnyGenerator() {
    std::cout << "BunnyGenerator Constructor called...\n";
    this->nameGenerator = new NameGenerator();
}

Bunny *BunnyGenerator::makeRandomBunny() {
    Bunny *b = new Bunny();
    Sex s = MALE;
    if (rand() % 2) {
        s = FEMALE;
    }

    b->setSex(s);
    b->setName(nameGenerator->getRandomName(s));
    b->setAge(0);

    b->setColor(Color(rand() % 4));
    std::cout << b->getName() << " has been born!\n";
    return b;
}



Bunny *BunnyGenerator::makeBunnyFromParent(const Bunny *b) {
    Bunny *child = new Bunny();
    Sex s = MALE;
    if (rand() % 2) {
        s = FEMALE;
    }

    child->setSex(s);
    child->setName(nameGenerator->getRandomName(s));
    child->setAge(0);

    child->setColor(b->getColor());
    std::cout << child->getName() << " has been born!\n";
    return child;
}








