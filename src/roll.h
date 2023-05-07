//roll.h
#include "die.h"

#ifndef ROLL_H
#define ROLL_H

class Roll
{
public:
    //With initializer list, initialize die1 and die2 Roll class private variables
    Roll(Die& die1, Die& die2) : die1(die1), die2(die2) {}
    void roll_die(); 
    int roll_value() const;

private:
    Die& die1; //initialize in Roll constructor
    Die& die2; //initialize in Roll constructor
    bool rolled{false}; //intitialize to false
    int value; //set to die1 + die2 rolled values
};

#endif
