//
// Created by NewRob on 4/11/2016.
//

#include "Bunny.h"
#include <iostream>

using namespace std;

bool Bunny::isTimeForBunnyHeaven() {
    if (!mutant && age >= longevity)
        return true;
    else if (age >= longevity * 2)
        return true;
    return false;
}

void Bunny::printInfo() const {
    cout << "*** Bunny Info ***" << endl;
    cout << "  Name:    " << name << endl;
    cout << "  Sex:     " << sex << endl;
    cout << "  Age:     " << age << endl;
    cout << "  Color:   " << color << endl;
    cout << " *" << endl;

}

