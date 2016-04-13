//
// Created by NewRob on 4/11/2016.
//

#include <iostream>
#include "BunnyColony.h"


void BunnyColony::addBunny(Bunny *pBunny) {
    Node *newNode;
    newNode->b = pBunny;
    newNode->next = nullptr;

    if (bunnies == nullptr) {
        bunnies = newNode;
    } else {
        Node *temp = bunnies->next;

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
    if (bunnies == nullptr) return;


    // if first node is old, need to shift head right
    while (bunnies->b->getAge() > 9) {
        Node *tmp = bunnies;
        delete(tmp->b);
        delete (tmp);
        bunnies = bunnies->next;
    }

    if (bunnies == nullptr) return; // might be empty, now

    Node *current = bunnies;
    Node *next = bunnies->next;

    // go through the rest
    while (next != nullptr) {
        Bunny *b = next->b;
        if (b->getAge() > 9) {
            Node* tmp = next;
            delete(b);
            delete(next);

        } else {
            // age
            b->setAge(b->getAge() + 1);
        }
        current->next = next->next;

    }
}

//void BunnyColony::killOldBunnies() {
//    Node *temp = bunnies;
//    while (temp != nullptr) {
//        temp->b->setAge(temp->b->getAge() + 1);
//        temp = temp->next;
//    }
//
//    for (vector<Bunny *>::iterator itr = bunnies.begin(); itr != bunnies.end();) {
//        Bunny *b = *itr;
//        if (b->getAge() > 10) {
//            bunnies.erase(itr); // O(n) for vector
//            if (b->getSex() == Bunny::MALE) {
//                --maleCount;
//            } else {
//                --femaleCount;
//            }
//            delete (b);
//        } else {
//            ++itr;
//        }
//    }
//}

void BunnyColony::procreate() {
    // get males and females over age 2
    vector<Bunny *> adultMales;
    vector<Bunny *> adultFemales;

    for (Bunny *b : bunnies) {
        if (b->getAge() > 1) {
            if (b->getSex() == Bunny::MALE) {
                adultMales.push_back(b);
            } else {
                adultFemales.push_back(b);
            }
        }
    }

    // check at least one adult male
    if (adultMales.size() > 0) {
        for (Bunny *b : adultFemales) {
            addBunny(bunnyGenerator.makeBunnyFromParent(b));
        }
    }
}

void BunnyColony::foodShortage() {
    for (vector<Bunny *>::iterator itr = bunnies.begin(); itr != bunnies.end();) {
        if (rand() % 2) {
            Bunny *b = *itr;
            bunnies.erase(itr); // O(n) for vector
            if (b->getSex() == Bunny::MALE) {
                --maleCount;
            } else {
                --femaleCount;
            }
            delete (b);
        } else {
            ++itr;
        }
    }
}

void BunnyColony::seed() {
    // init with 5 bunnies
    for (int i = 0; i < 5; ++i) {
        Bunny *b = bunnyGenerator.makeRandomBunny();
        this->addBunny(b);
        b->printInfo();
    }
}

















