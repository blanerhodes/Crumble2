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

void Player::AddStructure(Structure structure)
{
	m_Structures.push_back(structure);
}

void Player::RemoveStructure(StructureType type, glm::vec2 position)
{
	
	for (auto it = m_Structures.begin(); it != m_Structures.end(); it++)
	{
		Structure currStruct = *it;
		float xPos = currStruct.position.x;
		float yPos = currStruct.position.y;
		bool matchedX = (std::abs(xPos) - position.x < 0.0001 && std::abs(xPos) - position.x > -0.0001);
		bool matchedY = (std::abs(yPos) - position.y < 0.0001 && std::abs(yPos) - position.y > -0.0001);

		if (currStruct.buildType == type && xPos && yPos)
		{
			m_Structures.erase(it);
		}
	}
}

void Player::DecrementScore(uint32_t value)
{
	m_Score = std::max((unsigned int)0, m_Score - value);
}