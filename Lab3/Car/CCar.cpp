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