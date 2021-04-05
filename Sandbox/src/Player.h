#pragma once

#include "Crumble.h"

enum class Resource
{
	BRICK, SHEEP, STONE, WHEAT, WOOD
};

class Player
{
public:
	Player(std::string name = "Default");
	~Player() {}
	void SetName(std::string name) { m_Name = name; }
	std::string GetName() { return m_Name; }
	uint32_t GetCities() { return m_Cities; }
	uint32_t GetSettlements() { return m_Settlements; }
	uint32_t GetRoads() { return m_Roads; }
	uint32_t GetScore() { return m_Score; }
	std::vector<int> GetResources() { return m_Resources; }
	void AddResource(Resource resource, uint32_t amount);
	void RemoveResource(Resource resource, uint32_t amount);
	void IncrementScore(uint32_t value) { m_Score += value; }
	void DecrementScore(uint32_t value);

private:
	uint32_t m_Cities = 0;
	uint32_t m_Settlements = 0;
	uint32_t m_Roads = 0;
	uint32_t m_Score = 0;
	std::string m_Name;

	std::vector<int> m_Resources;
};