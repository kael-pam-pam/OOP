#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../Car/CCar.h"

TEST_CASE("Test class Ccar")
{
	SECTION("Default values")
	{
		CCar car;
		REQUIRE(car.IsTurnedOn() == false);
		REQUIRE(car.GetDirection() == Direction::HOLD);
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetGear() == 0);
	}
	
	SECTION("TurnOnEngine")
	{
		CCar car;
		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.IsTurnedOn() == true);

		REQUIRE(car.TurnOnEngine() == true);
	}

	SECTION("TurnOffEngine")
	{
		CCar car;
		REQUIRE(car.TurnOffEngine() == true);
		REQUIRE(car.IsTurnedOn() == false);

		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.SetGear(1) == true);
		REQUIRE(car.SetSpeed(10) == true);	
		REQUIRE(car.TurnOffEngine() == false);

		REQUIRE(car.SetGear(0) == true);
		REQUIRE(car.TurnOffEngine() == false);

		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.TurnOffEngine() == true);
	}

	SECTION("SetSpeed")
	{
		CCar car;
		REQUIRE(car.SetSpeed(10) == false);
		REQUIRE(car.GetSpeed() == 0);

		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.SetSpeed(10) == false);
		REQUIRE(car.GetSpeed() == 0);

		REQUIRE(car.SetGear(1) == true);
		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.GetSpeed() == 10);

		REQUIRE(car.SetSpeed(30) == true);
		REQUIRE(car.SetSpeed(31) == false);

		REQUIRE(car.SetSpeed(5) == true);

		REQUIRE(car.SetGear(0) == true);
		REQUIRE(car.SetSpeed(5) == false);	
		REQUIRE(car.SetSpeed(4) == true);
		
		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.SetGear(-1) == true);
		REQUIRE(car.SetSpeed(-10) == true);
		REQUIRE(car.SetSpeed(-20) == true);
		REQUIRE(car.SetSpeed(-21) == false);
		REQUIRE(car.SetSpeed(-15) == true);
		REQUIRE(car.SetSpeed(15) == false);
	}

	SECTION("SetGear")
	{
		CCar car;
		REQUIRE(car.SetGear(1) == false);
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.SetGear(0) == true);
		REQUIRE(car.TurnOnEngine() == true);
		REQUIRE(car.SetGear(1) == true);
		REQUIRE(car.GetGear() == 1);

		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.SetGear(-1) == true);
		REQUIRE(car.SetSpeed(-10) == true);
		REQUIRE(car.SetGear(-2) == false);
		REQUIRE(car.SetGear(1) == false);
		REQUIRE(car.SetGear(0) == true);
		REQUIRE(car.SetGear(-1) == false);

		REQUIRE(car.SetSpeed(0) == true);
		REQUIRE(car.SetGear(1) == true);
		REQUIRE(car.SetSpeed(25) == true);
		REQUIRE(car.SetGear(2) == true);
		REQUIRE(car.SetSpeed(45) == true);
		REQUIRE(car.SetGear(3) == true);
		REQUIRE(car.SetSpeed(55) == true);
		REQUIRE(car.SetGear(4) == true);
		REQUIRE(car.SetSpeed(85) == true);
		REQUIRE(car.SetGear(5) == true);
		REQUIRE(car.SetSpeed(145) == true);
		REQUIRE(car.SetGear(6) == false);
	}


	//“ест: проверка передач (только [-1..5])
	//“ест: переключение скоростей при пересечении диапазонов и одинаковом направлении движени€
	//“ест: скорость на передаче ограничена диапазоном (не больше, не меньше)
	//“ест: на нейтральной передача можно только уменьшить скорость (по модулю)
	//“ест: переключение на задний ход с первой/нейтральной и наоборот только через нулевую скорость
	
	//“ест: при выключенном двигателе переключение только возможно только на нейтраль.

}