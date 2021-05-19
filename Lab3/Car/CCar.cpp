#include "CCar.h"

const std::pair<int, int> ReverseSpeedRange = { 0, 20 };
const std::pair<int, int> FirstSpeedRange = { 0, 30 };
const std::pair<int, int> SecondSpeedRange = { 20, 50 };
const std::pair<int, int> ThirdSpeedRange = { 30,60 };
const std::pair<int, int> FourthSpeedRange = { 40, 90 };
const std::pair<int, int> FifthSpeedRange = { 50, 150 };

bool InRange(int num, const std::pair<int, int>& range)
{
	return num >= range.first && num <= range.second;
}

bool CCar::IsTurnedOn() const
{
	return m_isOnEngine;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetGear() const
{
	return m_gear;
}

bool CCar::TurnOnEngine()
{
	m_isOnEngine = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (!m_isOnEngine)
	{
		return true;
	}
	
	if (m_speed == 0 && m_gear == 0)
	{
		m_isOnEngine = false;
		return true;
	}
	
	return false;
}

bool CCar::SetGear(int gear)
{
	if (!m_isOnEngine)
	{
		if (gear == 0)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}

	if (gear == -1)
	{
		if (m_direction == Direction::HOLD)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}

	if (m_gear == gear)
	{
		return true;
	}

	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}
	else if ((gear == 1 && (m_direction == Direction::FORWARD || m_direction == Direction::HOLD) && InRange(m_speed, FirstSpeedRange)) 
		|| (gear == 2 && m_direction == Direction::FORWARD && InRange(m_speed, SecondSpeedRange)) 
		|| (gear == 3 && m_direction == Direction::FORWARD && InRange(m_speed, ThirdSpeedRange)) 
		|| (gear == 4 && m_direction == Direction::FORWARD && InRange(m_speed, FourthSpeedRange)) 
		|| (gear == 5 && m_direction == Direction::FORWARD && InRange(m_speed, FifthSpeedRange)))
	{
		m_gear = gear;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::SetSpeed(int speed)
{
	if ((m_gear == -1 || m_gear == 0 || m_gear == 1) && (speed == 0))
	{
		m_direction = Direction::HOLD;
		m_speed = speed;
		return true;
	}

	if (m_gear == -1 && InRange(speed, ReverseSpeedRange))
	{
		m_direction = Direction::BACKWARD;
		m_speed = speed;
		return true;
	}
	else if (m_gear == 1 && InRange(speed, FirstSpeedRange))
	{
		m_direction = Direction::FORWARD;
		m_speed = speed;
		return true;
	}
	else if ((m_gear == 0 && speed < m_speed)
		|| (m_gear == 2 && InRange(speed, SecondSpeedRange))
		|| (m_gear == 3 && InRange(speed, ThirdSpeedRange))
		|| (m_gear == 4 && InRange(speed, FourthSpeedRange))
		|| (m_gear == 5 && InRange(speed, FifthSpeedRange)))
	{
		m_speed = speed;
		return true;
	}
	else
	{
		return false;
	}
}