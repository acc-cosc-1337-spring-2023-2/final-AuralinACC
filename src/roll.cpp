//roll.cpp
#include "roll.h"

void Roll::roll_die()
{
    //Rolls die1 and die2, saves rolled values to value(private), and sets rolled to true.
    die1.roll();
    die2.roll();
    value = die1.rolled_value() + die2.rolled_value();
    rolled = true;
}
int const Roll::roll_value()
{
    //return value
    return value;
}