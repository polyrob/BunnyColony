//
// Created by NewRob on 4/11/2016.
//

#include <iostream>
#include "BunnyColony.h"
#include <stdlib.h>


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

    if (pBunny->getSex() == Bunny::MALE) {
        ++maleCount;
    } else {
        ++femaleCount;
    }
}

void BunnyColony::printStatus(const int &iteration) {
    std::cout << "*** ITERATION " << iteration << std::endl;
    std::cout << " Colony Size: " << maleCount + femaleCount << ", M/F: " << maleCount << "/" << femaleCount <<
    std::endl;

}

void BunnyColony::nextTurn() {
    ageBunnies();  // increment age and kill if old
    procreate();
    if (maleCount + femaleCount > 1000) {
        foodShortage();
    }
}


void BunnyColony::ageBunnies() {
    if (root == nullptr) return;

    // if first node is old, need to shift head right
    while (root->b->getAge() > 9) {
    	removeBunnyFromCount(root->b);
        Node *tmp = root;
        root = root->next;
        delete (tmp->b);
        delete (tmp);
    }

    if (root == nullptr) return; // might be empty, now
    root->b->setAge(root->b->getAge() + 1); //age the first bunny


    Node *current = root;
    Node *nextNode = root->next;

    // go through the rest
    while (nextNode != nullptr) {
        Bunny *b = nextNode->b;
        if (b->getAge() > 9) {
        	removeBunnyFromCount(b);
            current->next = nextNode->next;
            delete (nextNode->b);
            delete (nextNode);

        } else {
            // age
            b->setAge(b->getAge() + 1);
        }
        current = current->next;
        if (current == nullptr) break;
        nextNode = current->next;

    }
}


void BunnyColony::procreate() {
    if (root == nullptr) return;

    // get males and females over age 2
    vector<Bunny *> adultMales;
    vector<Bunny *> adultFemales;

    Node *temp = root;
    while (temp != nullptr) {
        Bunny *b = temp->b;
        if (b->getAge() > 1) {
            if (b->getSex() == Bunny::MALE) {
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
            addBunny(bunnyGenerator.makeBunnyFromParent(b));
        }
    }
}

void BunnyColony::foodShortage() {
    std::cout << "! Food shortage." << std::endl;
    if (root == nullptr) return;

    // if first node is old, need to shift head right
    if (rand() % 2) {
    	removeBunnyFromCount(root->b);
        Node *tmp = root;
        root = root->next;
        delete (tmp->b);
        delete (tmp);
    }

    if (root == nullptr) return; // might be empty, now

    Node *current = root;
    Node *nextNode = root->next;

    // go through the rest
    while (nextNode != nullptr) {
        if (rand() % 2) {
        	removeBunnyFromCount(nextNode->b);
            current->next = nextNode->next;
            delete (nextNode->b);
            delete (nextNode);

        }
        current = current->next;
        if (current== nullptr) break;
        nextNode = current->next;

    }

}

void BunnyColony::removeBunnyFromCount(Bunny* b) {
	if (b->getSex() == Bunny::MALE) {
	        --maleCount;
	    } else {
	        --femaleCount;
	    }
}

void BunnyColony::seed() {
    // init with 5 root
    for (int i = 0; i < 5; ++i) {
        Bunny *b = bunnyGenerator.makeRandomBunny();
        this->addBunny(b);
        b->printInfo();
    }
}

















