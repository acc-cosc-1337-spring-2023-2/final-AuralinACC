//die.h
#include<stdlib.h>
#include <ctime> //moved from die.cpp to allow main to use time

#ifndef DIE_H
#define DIE_H

class Die
{
public:
    void roll();
    int const rolled_value();

private:
    int roll_value;
    int sides{6};
};

#endif