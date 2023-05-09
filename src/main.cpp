//main.cpp
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include<iostream>
#include "point_phase.h"

using std::cout;

int main() 
{
	//die.cpp already seeded the roll. Die::roll() edited so that srand can be in main. 
	//make srand(time(0)) the first statement-this allows the rand function output true random numbers
	srand(time(0));

	//Create two instances of Die die1 and die 2
	Die die1;
	Die die2;
	//Create a Shooter instance shooter.
	Shooter shooter;
	//Create a pointer to Roll, name it roll.
	Roll* roll;
	//Set roll equal to the return value of the shooter throw_die function.
	roll = shooter.throw_die(die1, die2);

	//Create  ComeOutPhase instance come_out_phase.
	ComeOutPhase come_out_phase;

	/*Create a loop that continues while come_out_phase get_outcome is RollOutcome::natural or
		RollOutcome::craps.*/
	while(come_out_phase.get_outcome(roll) == RollOutcome::natural)
    {
    	//display the value of the rolled value and the text roll again
		cout<<"You rolled: "<<roll->roll_value()<<", roll again\n";
    	//Set roll equal to the return value of the shooter throw_die function.
		roll = shooter.throw_die(die1, die2);
	}

	//Display rolled value with the text start of point phase
	cout<<"Rolled "<<roll->roll_value()<<" start of point phase\n";
	//Display the text Roll until rolled value or 7 is rolled.
	cout<<"Roll until a "<<roll->roll_value()<<" or a 7 is rolled\n";

	//Create an int point variable set to roll rolled_value
	int point = roll->roll_value();
	//Set roll equal to the return value of the shooter throw_die function.
	roll = shooter.throw_die(die1, die2);

	//Create an instance of PointPhase point_phase.
	PointPhase point_phase(point);

	//Create a loop that continues while point_phase get_outcome is not RollOutcome::point 
	//or RollOutcome::seven_out
	while(point_phase.get_outcome(roll) != RollOutcome::point 
	&& point_phase.get_outcome(roll) != RollOutcome::seven_out)
	{
		//Display the rolled value and the text roll again
		cout<<"Rolled "<<roll->roll_value()<<" roll again\n";
		//Set roll equal to the return value of the shooter throw_die function.
		roll = shooter.throw_die(die1, die2);
	}

	//Display rolled value and the text end of point phase
	cout<<"Rolled: "<<roll->roll_value()<<" end of point phase\n";
	
	//Use cout to display the shooter variable(ostream has been overloaded for it)
	//edited shooter.cpp to match Example output
	cout<<shooter<<"\n";

	return 0;
}