#include "CCar.h"

const std::pair<int, int> ReverseSpeedRange = { -20, 0 };
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

	switch(gear)
	{
	case 0:
		m_gear = gear;
		return true;
	case 1:
		if ((m_direction == Direction::FORWARD || m_direction == Direction::HOLD) && InRange(m_speed, FirstSpeedRange))
		{
			m_gear = gear;
			return true;
		}
		return false;
	case 2:
	case 3:
	case 4:
	case 5:
		if (m_direction == Direction::FORWARD && (InRange(m_speed, FirstSpeedRange)
			|| InRange(m_speed, SecondSpeedRange)
			|| InRange(m_speed, ThirdSpeedRange)
			|| InRange(m_speed, FourthSpeedRange)
			|| InRange(m_speed, FifthSpeedRange)))
		{
			m_gear = gear;
			return true;
		}
		return false;
	default: 
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

	switch (m_gear)
	{
	case -1:
		if (InRange(speed, ReverseSpeedRange))
		{
			m_direction = Direction::BACKWARD;
			m_speed = speed;
			return true;
		}
		return false;
	case 0:
		if (abs(speed) < abs(m_speed))
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 1:
		if (InRange(speed, FirstSpeedRange))
		{
			m_direction = Direction::FORWARD;
			m_speed = speed;
			return true;
		}
		return false;
	case 2:
		if (InRange(speed, SecondSpeedRange))
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 3:
		if (InRange(speed, ThirdSpeedRange))
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 4:
		if (InRange(speed, FourthSpeedRange))
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 5:
		if (InRange(speed, FifthSpeedRange))
		{
			m_speed = speed;
			return true;
		}
		return false;
	default:
		return false;
	}
}