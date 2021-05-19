#pragma once
#include "Ccar.h"
#include <iostream>
#include <string>
#include <map>
#include <functional>

class CDashboard
{
public:
	CDashboard(CCar& car, std::istream& input, std::ostream& output);
	bool HandleCommand();		
private:
	bool Info();				
	bool EngineOn();			
	bool EngineOff();			
	bool SetGear(std::istream& args);
	bool SetSpeed(std::istream& args);

	CCar& m_car;
	std::istream& m_input;
	std::ostream& m_output;

	const std::map<std::string, std::function<bool(std::istream& args)>> m_actionMap;
};