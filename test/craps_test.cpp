#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

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