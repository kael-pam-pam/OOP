#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../FindMaxEx/FindMaxEx.h"
#include "../FindMaxEx/lib.h"


TEST_CASE("Test function FindMaxEx")
{
	Athlete ath;
	SECTION("empty vector")
	{
		std::vector<Athlete> emptyV;
		REQUIRE_FALSE(FindMaxEx(emptyV, ath, LessHeight));
	}
	SECTION("one element in vector")
	{
		std::vector<Athlete> oneElemV = {
			{"Carter", 180.5, 80.0}
		};

		REQUIRE(FindMaxEx(oneElemV, ath, LessWeight));
		REQUIRE(ath.name == "Carter");
		REQUIRE(ath.height == 180.5);
		REQUIRE(ath.weight == 80.0);		

		ath = { "", 0, 0 };
		REQUIRE(FindMaxEx(oneElemV, ath, LessHeight));
		REQUIRE(ath.name == "Carter");
		REQUIRE(ath.height == 180.5);
		REQUIRE(ath.weight == 80.0);
	}
	SECTION("more then one element in vector")
	{
		std::vector<Athlete> arrAthlete = {
			{"Carter", 180.5, 80.0},
			{"Allen", 167.3, 75},
			{"Dorsey", 183, 74.9},
			{"Bates", 177.6, 83.5},
			{"York", 190.0, 81.3}
		};

		REQUIRE(FindMaxEx(arrAthlete, ath, LessWeight));
		REQUIRE(ath.name == "Bates");
		REQUIRE(ath.height == 177.6);
		REQUIRE(ath.weight == 83.5);

		REQUIRE(FindMaxEx(arrAthlete, ath, LessHeight));
		REQUIRE(ath.name == "York");
		REQUIRE(ath.height == 190.0);
		REQUIRE(ath.weight == 81.3);
	}
}

