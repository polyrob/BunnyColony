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

Bunny *BunnyGenerator::makeBunny() {
	Bunny *b = new Bunny();
	Sex s = MALE;
	if (rand() % 2) {
		s = FEMALE;
	}

	b->setSex(s);
	b->setName(nameGenerator->getRandomName(s));
	b->setAge(0);
	b->setColor(Color(rand() % 4));

	// Determine if will be a mutant, 2%
	if (rand() % 50 == 1) {
		b->setMutant(true);
		std::cout << "Mutant "; // prefix born announcement
	} else {
		b->setMutant(false);
	}

	std::cout << b->getName() << " has been born!\n";
	return b;
}

Bunny *BunnyGenerator::makeBunny(const Bunny *b) {
	Bunny* child = makeBunny();
	child->setColor(b->getColor());		// set color to that of parent

	return child;
}

