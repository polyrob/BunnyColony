//
// Created by NewRob on 4/11/2016.
//

#include "BunnyGenerator.h"
#include <stdlib.h>

BunnyGenerator::BunnyGenerator() {
    std::cout << "BunnyGenerator Constructor called...";
    this->nameGenerator = new NameGenerator();
}

Bunny *BunnyGenerator::makeRandomBunny() {
    Bunny *b = new Bunny();
    Bunny::Sex s = Bunny::MALE;
    if (rand() % 2) {
        s = Bunny::FEMALE;
    }

    b->setSex(s);
    b->setName(nameGenerator->getRandomName(s));
    b->setAge(0);

    b->setColor(Bunny::Color(rand() % 4));

    return b;
}



Bunny *BunnyGenerator::makeBunnyFromParent(const Bunny *b) {
    Bunny *child = new Bunny();
    Bunny::Sex s = Bunny::MALE;
    if (rand() % 2) {
        s = Bunny::FEMALE;
    }

    child->setSex(s);
    child->setName(nameGenerator->getRandomName(s));
    child->setAge(0);

    child->setColor(b->getColor());

    return child;
}








