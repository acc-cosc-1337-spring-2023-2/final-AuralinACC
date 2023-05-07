//shooter.h
#include "die.h"
#include "roll.h"
#include<vector>
#include<iostream>

using std::ostream; using std::vector;

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
public:
Roll* throw_die(Die& die1, Die& die2);
friend std::ostream& operator<<(std::ostream& out, const Shooter& shooter);
~Shooter();
private:
vector<Roll*> rolls;
};

#endif