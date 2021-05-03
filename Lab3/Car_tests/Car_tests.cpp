#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../Car/CCar.h"


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
			REQUIRE(car.SetSpeed(10));
			REQUIRE(car.GetSpeed() == 10);
			REQUIRE(car.SetSpeed(30));

			//above gear speed
			REQUIRE(car.SetSpeed(31) == false);

			//reduce speed
			REQUIRE(car.SetSpeed(5));

			//increase/reduce speed in 0 gear
			REQUIRE(car.SetGear(0));
			REQUIRE(car.SetSpeed(5) == false);
			REQUIRE(car.SetSpeed(4));

			//increase/reduce speed in -1 gear
			REQUIRE(car.SetSpeed(0));
			REQUIRE(car.SetGear(-1));
			REQUIRE(car.SetSpeed(-10));
			REQUIRE(car.SetSpeed(-20));
			REQUIRE(car.SetSpeed(-21) == false);
			REQUIRE(car.SetSpeed(-15));
			REQUIRE(car.SetSpeed(15) == false);
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
			REQUIRE(car.SetSpeed(-10));
			
			//not exists gear
			REQUIRE(car.SetGear(-2) == false);
			
			//from -1 to 1 gear
			REQUIRE(car.SetGear(1) == false);
			REQUIRE(car.SetGear(0));
			REQUIRE(car.SetGear(-1) == false);
			REQUIRE(car.SetSpeed(0) == true);
			REQUIRE(car.SetGear(1) == true);
			
			//1-5 gear
			REQUIRE(car.SetSpeed(25) == true);
			REQUIRE(car.SetGear(2) == true);
			REQUIRE(car.SetSpeed(45) == true);
			REQUIRE(car.SetGear(3) == true);
			REQUIRE(car.SetSpeed(55) == true);
			REQUIRE(car.SetGear(4) == true);
			REQUIRE(car.SetSpeed(85) == true);
			REQUIRE(car.SetGear(5) == true);
			REQUIRE(car.SetSpeed(145) == true);
			
			//not exists gear
			REQUIRE(car.SetGear(6) == false);
		}
		
	}


	//“ест: проверка передач (только [-1..5])
	//“ест: переключение скоростей при пересечении диапазонов и одинаковом направлении движени€
	//“ест: скорость на передаче ограничена диапазоном (не больше, не меньше)
	//“ест: на нейтральной передача можно только уменьшить скорость (по модулю)
	//“ест: переключение на задний ход с первой/нейтральной и наоборот только через нулевую скорость
	
	//“ест: при выключенном двигателе переключение только возможно только на нейтраль.

}