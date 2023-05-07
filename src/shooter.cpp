//shooter.cpp
#include "shooter.h"

Roll* Shooter::throw_die(Die& die1, Die& die2)
{
    //Create a dynamic instance(heap) of Roll
    Roll* roll_instance = new Roll(die1, die2);
    //call Roll roll_die function
    roll_instance->roll_die();
    // add roll to vector
    rolls.push_back(roll_instance);
    //return roll instance
    return roll_instance;
}
std::ostream& operator<<(std::ostream& out, const Shooter& shooter)
{
    //output vector of Roll*
    for (int i = 0; i < shooter.rolls.size(); i++) //standard for loop
    {
        out << "Roll " << (i + 1) << ": " << shooter.rolls[i]->roll_value() << "\n";
    }
    return out; // allows for chained output 
}
Shooter::~Shooter()
{
    //Iterate through the rolls vector
    for(Roll* roll : rolls) //range based for loop
    {
        //call delete on each roll(clear memory)
        delete roll;
    }
    //optional, but good practice clears the rolls vector
    //should be done automatically when Shooter clears from stack without this line
    rolls.clear();
}