//die.cpp
#include "die.h"
//#include <ctime> //moved to die.h to give access to time in main

void Die::roll()//Randomly assigns a value to roll_value in the range of 1 to 6
{
    //removed seed and now seeding in main
    /*static bool seeded = false;
    if (!seeded)
    {  
        srand(time(NULL));
        seeded = true;
    }*/
    roll_value = rand() % sides + 1; //value between 1 and 6
}
int const Die::rolled_value() //Returns roll_value
{
    return roll_value;
}