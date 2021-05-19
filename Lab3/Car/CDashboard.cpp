#include "CDashboard.h"
#include <sstream>

std::string DirectionString(Direction dr)
{
	switch (dr)
	{
	case Direction::BACKWARD: 
		return "backward";
	case Direction::FORWARD:
		return "forward";
	case Direction::HOLD:
		return "hold";
	default:
		return "";
	}
}

bool GetNumberFromStr(std::string inputStr, int& outputNum)
{
	try
	{
		outputNum = stoi(inputStr);
	}
	catch (std::exception&)
	{
		return false;
	}

	return true;
}

CDashboard::CDashboard(CCar& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "Info", [this](std::istream& args) {
			   return Info();
		   } },
		  { "EngineOn", [this](std::istream& args) {
			   return EngineOn();
		   } },
		  { "EngineOff", [this](std::istream& args) {
			   return EngineOff();
		   } },
		  { "SetGear", [this](std::istream& args) {
			   return SetGear(args);
		   } },
		  { "SetSpeed", [this](std::istream& args) {
			   return SetSpeed(args);
		   } },
		})
{
}

bool CDashboard::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CDashboard::Info()
{
	if (m_car.IsTurnedOn())
	{
		m_output << "Engine: on\n";
	}
	else
	{
		m_output << "Engine: off\n";
	}

	m_output << "Speed: " << m_car.GetSpeed() << "\n";
	m_output << "Direction: " << DirectionString(m_car.GetDirection()) << "\n";
	m_output << "Gear: " << m_car.GetGear() << "\n";
	return true;
}

bool CDashboard::EngineOn()
{
	m_car.TurnOnEngine();
	m_output << "Engine: on\n";
	return true;
}

bool CDashboard::EngineOff()
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine: off\n";
	}
	else
	{
		m_output << "Engine don't stopped\n";
	}

	return true;
}

bool CDashboard::SetGear(std::istream& args)
{
	std::string inputStr;
	args >> inputStr;
	int gear;

	if (GetNumberFromStr(inputStr, gear))
	{
		if (m_car.SetGear(gear))
		{
			m_output << "Gear " << gear << " changed\n";
		}
		else
		{
			m_output << "Gear don`t changed\n";
		}
	}

	return true;
}

bool CDashboard::SetSpeed(std::istream& args)
{
	std::string inputStr;
	args >> inputStr;
	int speed;
	
	if (GetNumberFromStr(inputStr, speed))
	{
		if (m_car.SetSpeed(speed))
		{
			m_output << "Speed " << speed <<" changed\n";
		}
		else
		{
			m_output << "Speed don`t changed\n";
		}
	}

	return true;
}