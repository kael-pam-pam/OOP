#include "CCar.h"

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
		m_isOnEngine == false;
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

	if (m_gear == gear)
	{
		return true;
	}

	switch(gear)
	{
	case -1:
		if (m_direction == Direction::HOLD)
		{
			m_gear = gear;
			return true;
		}
		return false;
	case 0:
		m_gear = gear;
		return true;
	case 1:
		if (m_direction == Direction::FORWARD && m_speed >= 0 && m_speed <= 30)
		{
			m_gear = gear;
			return true;
		}
		return false;
	case 2:
		if (m_direction == Direction::FORWARD && m_speed >= 20 && m_speed <= 50)
		{
			m_gear = gear;
			return true;
		}
		return false;
	case 3:
		if (m_direction == Direction::FORWARD && m_speed >= 30 && m_speed <= 60)
		{
			m_gear = gear;
			return true;
		}
		return false;
	case 4:
		if (m_direction == Direction::FORWARD && m_speed >= 40 && m_speed <= 90)
		{
			m_gear = gear;
			return true;
		}
		return false;
	case 5:
		if (m_direction == Direction::FORWARD && m_speed >= 50 && m_speed <= 150)
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
	switch (m_gear)
	{
	case -1:
		if (speed >= 0 && speed <= 20)
		{
			m_direction = Direction::BACKWARD;
			if (speed == 0)
			{
				m_direction = Direction::HOLD;
			}
			m_speed = speed;
			return true;
		}
		return false;
	case 0:
		if (speed <= m_speed)
		{
			if (speed == 0)
			{
				m_direction = Direction::HOLD;
			}
			m_speed = speed;
			return true;
		}
		return false;
	case 1:
		if (speed >= 0 && speed <= 30)
		{
			m_direction = Direction::FORWARD;
			if (speed == 0)
			{
				m_direction = Direction::HOLD;
			}
			m_speed = speed;
			return true;
		}
		return false;
	case 2:
		if (speed >= 20 && speed <= 50)
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 3:
		if (speed >= 30 && speed <= 60)
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 4:
		if (speed >= 40 && speed <= 90)
		{
			m_speed = speed;
			return true;
		}
		return false;
	case 5:
		if (speed >= 50 && speed <= 150)
		{
			m_speed = speed;
			return true;
		}
		return false;
	default:
		return false;
	}
}