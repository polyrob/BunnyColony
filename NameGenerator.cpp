//
// Created by NewRob on 4/11/2016.
//

#include <fstream>
#include "NameGenerator.h"

NameGenerator::NameGenerator() {
    std::cout << "NameGenerator Constructor called..." << std::endl;

    try {
        loadFromFile(NAMES_FIRST_MALE, vFirstNamesMale);
        loadFromFile(NAMES_FIRST_FEMALE, vFirstNamesFemale);
        loadFromFile(NAMES_LAST, vLastNames);
    } catch (std::exception &e) {
        std::cout << "ERROR! " << e.what();
    }
}

void NameGenerator::loadFromFile(const char *filename, vector<string> &v) {
    string line;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            v.push_back(line);
        }
        myfile.close();
    }
}

std::string NameGenerator::getRandomName(const Bunny::Sex sex) {
    std::string fullName;
    if (sex == Bunny::Sex::MALE) {
        int index = rand() % vFirstNamesMale.size();
        fullName.append(vFirstNamesMale[index]);
    } else {
        int index = rand() % vFirstNamesFemale.size();
        fullName.append(vFirstNamesFemale[index]);
    }

    fullName.append(" ");
    fullName.append(vLastNames[rand() % vLastNames.size()]);
    return fullName;
}





