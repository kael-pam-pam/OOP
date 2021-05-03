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
	}

	SECTION("TurnOffEngine")
	{
		CCar car;
		REQUIRE(car.TurnOffEngine() == true);
		REQUIRE(car.IsTurnedOn() == false);
		car.TurnOnEngine();
		//“ест: выключение двигател€ только при нулевой скорости на нейтрали.
		//на скорости и передаче - false
		//на скорости и нейтрале - false
	}

	SECTION("SetGear")
	{

	}

	//“ест: проверка передач (только [-1..5])
	//“ест: переключение скоростей при пересечении диапазонов и одинаковом направлении движени€
	//“ест: скорость на передаче ограничена диапазоном (не больше, не меньше)
	//“ест: на нейтральной передача можно только уменьшить скорость (по модулю)
	//“ест: переключение на задний ход с первой/нейтральной и наоборот только через нулевую скорость
	
	//“ест: при выключенном двигателе переключение только возможно только на нейтраль.

}