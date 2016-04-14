//
// Created by NewRob on 4/11/2016.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "BunnyColony.h"


void BunnyColony::addBunny(Bunny *pBunny) {
	Node *newNode = new Node();
	newNode->b = pBunny;
	newNode->next = nullptr;

	if (root == nullptr) {
		root = newNode;
	} else {
		Node *temp = root;

		while (temp->next != nullptr) {
			temp = temp->next;
		}
		// when finally at the end
		temp->next = newNode;
	}

	if (pBunny->getSex() == MALE) {
		++maleCount;
	} else {
		++femaleCount;
	}
}

void BunnyColony::nextTurn(const int &iteration) {
	std::cout << "\n*** ITERATION " << iteration << std::endl;
	ageBunnies();
	procreate();
	mutateBunnies();
	if (maleCount + femaleCount > 1000) {
		foodShortage();
	}

	std::cout << " Colony Size: " << maleCount + femaleCount;
	std::cout << ", M/F: " << maleCount << "/" << femaleCount;
	std::cout << ", Mutants: " << mutantCount << std::endl;
}

void BunnyColony::ageBunnies() {
	// if first node is old, need to shift head right
	while (root != nullptr && root->b->isTimeForBunnyHeaven()) {
		removeBunnyFromCount(root->b);			// it's just the bunny's time :(
		std::cout << root->b->getName() << " has died from old age.\n";
		Node *tmp = root;
		root = root->next;
		delete (tmp->b);
		delete (tmp);
	}

	if (root == nullptr)
		return; 								// might be empty now after processing
	root->b->setAge(root->b->getAge() + 1); 	//age the first bunny

	Node *current = root;
	Node *nextNode = root->next;

	// go through the rest
	while (nextNode != nullptr) {
		Bunny *b = nextNode->b;
		if (b->isTimeForBunnyHeaven()) {
			removeBunnyFromCount(b);
			std::cout << b->getName() << " has died from old age.\n";
			current->next = nextNode->next;
			delete (nextNode->b);
			delete (nextNode);

		} else {
			b->setAge(b->getAge() + 1);		// if it's surviving, age it 1
		}
		current = current->next;
		if (current == nullptr)
			break;							// if it's the last one, break out of the loop
		nextNode = current->next;
	}
}

void BunnyColony::procreate() {
	if (root == nullptr)
		return;

	// get males and females over age 2
	vector<Bunny *> adultMales;
	vector<Bunny *> adultFemales;

	Node *temp = root;
	while (temp != nullptr) {
		Bunny *b = temp->b;
		if (b->getAge() > 1 && !b->isMutant()) {
			if (b->getSex() == MALE) {
				adultMales.push_back(b);
			} else {
				adultFemales.push_back(b);
			}
		}
		temp = temp->next;
	}
	// done going through

	// check at least one adult male
	if (adultMales.size() > 0) {
		for (Bunny *b : adultFemales) {
			addBunny(bunnyGenerator.makeBunny(b));
		}
	}
}

void BunnyColony::foodShortage() {
	//TODO: this isn't - per spec - killing 'exactly half' of the bunnies. It's more of a coin flip
	if (root == nullptr)
		return;

	// if first node is old, need to shift head right
	if (rand() % 2) {
		removeBunnyFromCount(root->b);
		std::cout << root->b->getName() << " has died from lack of food.\n";
		Node *tmp = root;
		root = root->next;
		delete (tmp->b);
		delete (tmp);
	}

	if (root == nullptr)
		return; // might be empty, now

	Node *current = root;
	Node *nextNode = root->next;

	// go through the rest
	while (nextNode != nullptr) {
		if (rand() % 2) {
			removeBunnyFromCount(nextNode->b);
			std::cout << nextNode->b->getName()
					<< " has died from lack of food.\n";
			current->next = nextNode->next;
			delete (nextNode->b);
			delete (nextNode);

		}
		current = current->next;
		if (current == nullptr)
			break;
		nextNode = current->next;

	}

}

void BunnyColony::removeBunnyFromCount(Bunny* b) {
	if (b->getSex() == MALE) {
		--maleCount;
	} else {
		--femaleCount;
	}
}

void BunnyColony::mutateBunnies() {
	std::vector<Bunny*> nonMutants = getNonMutantBunnies();
	mutantCount = (maleCount + femaleCount) - nonMutants.size();

	// shuffle so we can use the first n Bunny* from our list
	std::random_shuffle ( nonMutants.begin(), nonMutants.end() );

	// for every mutant, mutate a regular bunny
	unsigned int newMutants = 0;
	for (unsigned int i = 0; i < mutantCount && i < nonMutants.size(); i++) {
		Bunny* b = nonMutants[i];
		std::cout << b->getName() << " has become a Mutant!\n";
		b->setMutant(true);
		++newMutants;
		b->setName(std::string("Mutant ").append(b->getName()));
	}
	mutantCount += newMutants;
}

std::vector<Bunny*> BunnyColony::getNonMutantBunnies() {
	std::vector<Bunny*> v;

	if (root == nullptr)
		return v;

	Node *temp = root;
	while (temp != nullptr) {
		Bunny* b = temp->b;
		if (!b->isMutant()) {
			v.push_back(b);
		}
		temp = temp->next;
	}
	return v;
}

void BunnyColony::seed() {
	// init with 5 root
	for (int i = 0; i < 5; ++i) {
		Bunny *b = bunnyGenerator.makeBunny();
		this->addBunny(b);
		b->printInfo();
	}
}

