#pragma once

#include "Crumble.h"

struct Neighbor
{
	bool roaded = false;
	glm::vec3 position;
};

struct CrossPoint
{
	Neighbor leftNeighbor;
	Neighbor rightNeighbor;
	Neighbor vertNeighbor;
	glm::vec3 position;
};

enum class StructureType
{
	NONE = -1, ROAD = 0, SETTLEMENT = 1, CITY = 2, ROAD_LEFT_UP = 3, ROAD_RIGHT_UP = 4, ROAD_VERTICAL = 5
};

struct Structure
{
	glm::vec3 position;
	glm::vec3 nearestCrossPoint;
	StructureType buildType = StructureType::NONE;
};

enum class Resource
{
	NONE = -1,
	BRICK = 0,
	SHEEP = 1,
	STONE = 2,
	WHEAT = 3,
	WOOD = 4
};


