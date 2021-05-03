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
		//����: ���������� ��������� ������ ��� ������� �������� �� ��������.
		//�� �������� � �������� - false
		//�� �������� � �������� - false
	}

	SECTION("SetGear")
	{

	}

	//����: �������� ������� (������ [-1..5])
	//����: ������������ ��������� ��� ����������� ���������� � ���������� ����������� ��������
	//����: �������� �� �������� ���������� ���������� (�� ������, �� ������)
	//����: �� ����������� �������� ����� ������ ��������� �������� (�� ������)
	//����: ������������ �� ������ ��� � ������/����������� � �������� ������ ����� ������� ��������
	
	//����: ��� ����������� ��������� ������������ ������ �������� ������ �� ��������.

}