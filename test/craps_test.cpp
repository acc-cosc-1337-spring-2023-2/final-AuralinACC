//craps_test.cpp
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify each roll returns a value from 1 to 6.")
{
	Die test;

	for(int i = 1;  i <= 10; i++)
	{
		test.roll();
		REQUIRE(test.rolled_value() >= 1);
		REQUIRE(test.rolled_value() <= 6);
	}
}

TEST_CASE("Verify rolls return a value from 2 to 12.")
{
	Die die1;
	Die die2;
	Roll test(die1, die2);

	for(int i = 1; i <= 10; i++)
	{
		test.roll_die();
		REQUIRE(test.roll_value() >= 2);
		REQUIRE(test.roll_value() <= 12);
	}
}

TEST_CASE("Test return and verify that the roll result has value from 2 to 12")
{
	Die die1;
	Die die2;
	Shooter test_shoot;

	//Test that shooter reutrns a Roll
	for(int i = 0; i < 10; i++)
	{
		//create instance of Roll pointer from instance of Shooter
		Roll* roll_instance = test_shoot.throw_die(die1, die2); 

		//create temp variable to hold roll value by pointing to Roll instance
		int roll_value = roll_instance->roll_value();

		//verify that the roll result has one of the following values: 2-12
		//(loop 10 times and create and assert in the loop)
		REQUIRE(roll_value >= 2);
		REQUIRE(roll_value <= 12);
	}
}

TEST_CASE("Test ComeOutPhase get_outcomes returns values natural, craps, and point")
{
	Die die1;
	Die die2;
	Roll roll(die1, die2);
	ComeOutPhase test;

	//instructions didn't say how many times to test
	//I didn't feel 10 was enough given the complexity
	//for me the test ran fine with 1000 assertions
	for(int i = 0; i < 1000; i++) 
	{
		roll.roll_die();
		int roll_value = roll.roll_value();
		RollOutcome outcome = test.get_outcome(&roll);

		if(roll_value == 7 || roll_value == 11)
		{
			REQUIRE(outcome == RollOutcome::natural);
		}
		else if(roll_value == 2 || roll_value == 3 || roll_value == 12)
		{
			REQUIRE(outcome == RollOutcome::craps);
		}
		else
		{
			REQUIRE(outcome == RollOutcome::point);
		}
	}
}

TEST_CASE("Test PointPhase get_coutcomes returns values point, seven_out, and nopoint")
{
	Die die1;
	Die die2;
	Roll roll(die1, die2);
	int point = 4;
	PointPhase test(point);
	
	for(int i = 0; i < 1000; i++)
	{
		roll.roll_die();
		int roll_value = roll.roll_value();
		RollOutcome outcome = test.get_outcome(&roll);

		if(roll_value == point)
		{
			REQUIRE(outcome == RollOutcome::point);
		}
		else if(roll_value == 7)
		{
			REQUIRE(outcome == RollOutcome::seven_out);
		}
		else
		{
			REQUIRE(outcome == RollOutcome::nopoint);
		}
	}
}