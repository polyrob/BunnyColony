//
// Created by NewRob on 4/11/2016.
//

#ifndef BUNNY_BUNNY_H
#define BUNNY_BUNNY_H

#include <string>
#include <iostream>

using namespace std;

class Bunny {


public:
    enum Sex {
        MALE, FEMALE
    };
    enum Color {
        WHITE, BROWN, BLACK, SPOTTED
    };


    Bunny() { }

    virtual ~Bunny() { }


    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Bunny::age = age;
    }

    Color getColor() const {
        return color;
    }

    void setColor(Color color) {
        Bunny::color = color;
    }

    Sex getSex() const {
        return sex;
    }

    void setSex(Sex sex) {
        Bunny::sex = sex;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Bunny::name = name;
    }

    void printInfo() const;




private:
    string name;
    Sex sex;
    Color color;
    int age;
};


#endif //BUNNY_BUNNY_H
