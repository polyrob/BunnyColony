//
// Created by NewRob on 4/11/2016.
//

#include <iostream>
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
            current->next = nextNode->next;
            delete (nextNode);

        } else {
            // age
            b->setAge(b->getAge() + 1);
        }
        current = current->next;
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
    Node *temp = root;
    while (temp != nullptr) {
        if (rand() % 2) {
            // kill it
            Bunny *b = temp->b;

            if (b->getAge() > 1) {
                if (b->getSex() == Bunny::MALE) {
                    --maleCount;
                } else {
                    --femaleCount;
                }
            }

        }
        temp = temp->next;
    }


    Node *current = root;
    Node *nextNode = root->next;

    // go through the rest
    while (nextNode != nullptr) {
        Bunny *b = nextNode->b;
        if (rand() % 2) {

            if (b->getSex() == Bunny::MALE) {
                --maleCount;
            } else {
                --femaleCount;
            }

            current->next = nextNode->next;
            delete (nextNode);

        }
        current = current->next;
        nextNode = current->next;

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

















