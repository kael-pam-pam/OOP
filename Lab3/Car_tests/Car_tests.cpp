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
		car.TurnOnEngine();
		REQUIRE(car.IsTurnedOn() == true);
	}

	//����: �������� ������� (������ [-1..5])
	//����: ������������ ��������� ��� ����������� ���������� � ���������� ����������� ��������
	//����: �������� �� �������� ���������� ���������� (�� ������, �� ������)
	//����: �� ����������� �������� ����� ������ ��������� �������� (�� ������)
	//����: ������������ �� ������ ��� � ������/����������� � �������� ������ ����� ������� ��������
	//����: ���������� ��������� ������ ��� ������� �������� �� ��������.
	//����: ��� ����������� ��������� ������������ ������ �������� ������ �� ���������.

}