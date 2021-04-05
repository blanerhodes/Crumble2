#include "Player.h"

Player::Player(std::string name) : m_Name(name)
{
	m_Resources.resize(5);
}

void Player::AddResource(Resource resource, uint32_t amount)
{
	m_Resources.at(static_cast<int>(resource)) += amount;
}

void Player::RemoveResource(Resource resource, uint32_t amount)
{
	if (m_Resources.at(static_cast<int>(resource)) - amount < 0)
	{
		//CR_CORE_INFO("Not enough of resource {0}", static_cast<int>(resource));
		m_Resources.at(static_cast<int>(resource)) = 0;
		return;
	}
	m_Resources.at(static_cast<int>(resource)) -= amount;
}

void Player::DecrementScore(uint32_t value)
{
	m_Score = std::max((unsigned int)0, m_Score - value);
}