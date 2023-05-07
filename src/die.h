//die.h
#include<stdlib.h>

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