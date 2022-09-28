#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test function get_factorial")
{
    REQUIRE(get_factorial(3) == 6);
    REQUIRE(get_factorial(5) == 120);
    REQUIRE(get_factorial(6) == 720);
}

TEST_CASE("Test function get_greatest_common_divisor")
{
    REQUIRE(get_greatest_common_divisor(5, 15) == 5);
    REQUIRE(get_greatest_common_divisor(21, 28) == 7);
    REQUIRE(get_greatest_common_divisor(25, 100) == 25);
}
