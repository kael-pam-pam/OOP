#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../Car/CCar.h"
#include "../Car/CDashboard.h"


TEST_CASE("Test class Ccar")
{
	CCar car;
	REQUIRE(car.IsTurnedOn() == false);
	REQUIRE(car.GetDirection() == Direction::HOLD);
	REQUIRE(car.GetSpeed() == 0);
	REQUIRE(car.GetGear() == 0);
		
	SECTION("Test fuction TurnOnEngine")
	{
		//turn on engine in start
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.IsTurnedOn());

		//turn on after turn on
		REQUIRE(car.TurnOnEngine());
	}

	SECTION("Test fuction TurnOffEngine")
	{
		SECTION("turn off in start")
		{
			REQUIRE(car.TurnOffEngine());
			REQUIRE(car.IsTurnedOn() == false);
		}

		SECTION("turn off in speed and gear")
		{
			//turn off in speed and gear
			REQUIRE(car.TurnOnEngine());
			REQUIRE(car.SetGear(1));
			REQUIRE(car.SetSpeed(10));	
			REQUIRE(car.TurnOffEngine() == false);

			//turn off in 0 gear and speed
			REQUIRE(car.SetGear(0));
			REQUIRE(car.TurnOffEngine() == false);

			//turn off in 0 gear and 0 speed
			REQUIRE(car.SetSpeed(0));
			REQUIRE(car.TurnOffEngine());
		}
	}

	SECTION("Test fuction SetSpeed")
	{
		SECTION("set speed in start")
		{
			REQUIRE(car.SetSpeed(10) == false);
			REQUIRE(car.GetSpeed() == 0);
		}
		
		SECTION("set speed without gear")
		{
			REQUIRE(car.TurnOnEngine());
			REQUIRE(car.SetSpeed(10) == false);
			REQUIRE(car.GetSpeed() == 0);
		}

		SECTION("set speed in gear")
		{
			//increase speed
			REQUIRE(car.TurnOnEngine());
			REQUIRE(car.SetGear(1));
			REQUIRE(car.GetDirection() == Direction::HOLD);
			REQUIRE(car.SetSpeed(10));
			REQUIRE(car.GetDirection() == Direction::FORWARD);
			REQUIRE(car.GetSpeed() == 10);
			REQUIRE(car.SetSpeed(30));

			//above gear speed
			REQUIRE(car.SetSpeed(31) == false);

			//reduce speed
			REQUIRE(car.SetSpeed(5));

			//increase/reduce speed in 0 gear
			REQUIRE(car.SetGear(0));
			REQUIRE(car.GetDirection() == Direction::FORWARD);
			REQUIRE(car.SetSpeed(5) == false);
			REQUIRE(car.SetSpeed(4));

			//increase/reduce speed in -1 gear
			REQUIRE(car.SetSpeed(0));
			REQUIRE(car.GetDirection() == Direction::HOLD);
			REQUIRE(car.SetGear(-1));
			REQUIRE(car.SetSpeed(10));
			REQUIRE(car.GetDirection() == Direction::BACKWARD);
			REQUIRE(car.SetSpeed(20));
			REQUIRE(car.SetSpeed(21) == false);
			REQUIRE(car.SetSpeed(15));

			//change gear between -1 and 1
			REQUIRE(car.SetGear(1) == false);
			REQUIRE(car.GetDirection() == Direction::BACKWARD);
			REQUIRE(car.SetSpeed(0));
			REQUIRE(car.SetGear(1));
			REQUIRE(car.SetSpeed(15));
		}	
	}

	SECTION("Test funtion SetGear")
	{
		SECTION("set gear in start")
		{
			REQUIRE(car.SetGear(1) == false);
			REQUIRE(car.GetGear() == 0);
			REQUIRE(car.SetGear(0));
		}

		SECTION("change gear")
		{
			//1 gear
			REQUIRE(car.TurnOnEngine());
			REQUIRE(car.SetGear(1));
			REQUIRE(car.GetGear() == 1);

			//-1 gear
			REQUIRE(car.GetSpeed() == 0);
			REQUIRE(car.SetGear(-1));
			REQUIRE(car.SetSpeed(10));
			
			//not exists gear
			REQUIRE(car.SetGear(-2) == false);
			
			//from -1 to 1 gear
			REQUIRE(car.SetGear(1) == false);
			REQUIRE(car.SetGear(0));
			REQUIRE(car.SetGear(-1) == false);
			REQUIRE(car.SetSpeed(0) == true);
			REQUIRE(car.SetGear(1));
			
			//1-5 gear
			REQUIRE(car.SetSpeed(25));
			REQUIRE(car.SetGear(2));
			REQUIRE(car.SetSpeed(45));
			REQUIRE(car.SetGear(3));
			REQUIRE(car.SetGear(4));
			REQUIRE(car.SetGear(5) == false);
			REQUIRE(car.SetSpeed(55) == true);
			REQUIRE(car.SetGear(4) == true);
			REQUIRE(car.SetSpeed(85) == true);
			REQUIRE(car.SetGear(5) == true);
			REQUIRE(car.SetSpeed(145) == true);
			
			//not exists gear
			REQUIRE(car.SetGear(6) == false);
		}
	}
}

TEST_CASE("Test class CDashboard")
{
	CCar car;
	std::istringstream input("EngineOn\nSetGear 1\nSetSpeed 30\nInfo\nSetSpeed 0\nSetGear 0\nEngineOff\n");
	std::ostringstream output;
	CDashboard dashboard(car, input, output);

	dashboard.HandleCommand();
	REQUIRE("Engine: on\n" == output.str());
	output.str("");

	dashboard.HandleCommand();
	REQUIRE("Gear 1 changed\n" == output.str());
	output.str("");

	dashboard.HandleCommand();
	REQUIRE("Speed 30 changed\n" == output.str());
	output.str("");

	dashboard.HandleCommand();
	REQUIRE("Engine: on\nSpeed: 30\nDirection: forward\nGear: 1\n" == output.str());
	output.str("");

	dashboard.HandleCommand();
	REQUIRE("Speed 0 changed\n" == output.str());
	output.str("");

	dashboard.HandleCommand();
	REQUIRE("Gear 0 changed\n" == output.str());
	output.str("");

	dashboard.HandleCommand();
	REQUIRE("Engine: off\n" == output.str());
	output.str("");
}