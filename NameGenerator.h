//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_NAMEGENERATOR_H
#define BUNNY_NAMEGENERATOR_H


#include <iostream>
#include <vector>
#include "Bunny.h"

class NameGenerator {

    const char *NAMES_FIRST_MALE = "names_first_m.txt";
    const char *NAMES_FIRST_FEMALE = "names_first_f.txt";
    const char *NAMES_LAST = "names_last.txt";

    std::vector<string> vFirstNamesMale;
    std::vector<string> vFirstNamesFemale;
    std::vector<string> vLastNames;

    void loadFromFile(const char *filename, vector<string> &v);

public:
    NameGenerator();

    virtual ~NameGenerator() { std::cout << "NameGenerator Destructor called..."; }

    std::string getRandomName(const Bunny::Sex sex);
};


#endif //BUNNY_NAMEGENERATOR_H

