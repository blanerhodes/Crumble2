#include "TileMap.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Random.h"

using namespace Crumble;



void TileMap::Init()
{
	m_Checkerboard = Texture2D::Create("assets/textures/Checkerboard.png");

	m_BrickTile = Texture2D::Create("assets/textures/BrickTile.png");
	m_SandTile = Texture2D::Create("assets/textures/SandTile.png");
	m_SheepTile = Texture2D::Create("assets/textures/SheepTile.png");
	m_StoneTile = Texture2D::Create("assets/textures/StoneTile.png");
	m_WaterTile = Texture2D::Create("assets/textures/WaterTile.png");
	m_WheatTile = Texture2D::Create("assets/textures/WheatTile.png");
	m_WoodTile = Texture2D::Create("assets/textures/WoodTile.png");

	m_Token2 = Texture2D::Create("assets/textures/Token2.png");
	m_Token3 = Texture2D::Create("assets/textures/Token3.png");
	m_Token4 = Texture2D::Create("assets/textures/Token4.png");
	m_Token5 = Texture2D::Create("assets/textures/Token5.png");
	m_Token6 = Texture2D::Create("assets/textures/Token6.png");
	m_Token7 = Texture2D::Create("assets/textures/Token7.png");
	m_Token8 = Texture2D::Create("assets/textures/Token8.png");
	m_Token9 = Texture2D::Create("assets/textures/Token9.png");
	m_Token10 = Texture2D::Create("assets/textures/Token10.png");
	m_Token11 = Texture2D::Create("assets/textures/Token11.png");
	m_Token12 = Texture2D::Create("assets/textures/Token12.png");
	m_Robber = Texture2D::Create("assets/textures/robber.png");

	m_BlueCity = Texture2D::Create("assets/textures/BlueCity.png");
	//m_BlueHorizontalRoad = Texture2D::Create("assets/textures/BlueHorizontalRoad.png"); //change to vertical
	m_BlueRoadLeftUp = Texture2D::Create("assets/textures/BlueRoadLeftUp.png");
	m_BlueRoadRightUp = Texture2D::Create("assets/textures/BlueRoadRightUp.png");
	m_BlueSettlement = Texture2D::Create("assets/textures/BlueSettlement.png");
	m_BlueVerticalRoad  = Texture2D::Create("assets/textures/BlueRoadVertical.png");
	m_RedCity = Texture2D::Create("assets/textures/RedCity.png");
	//m_RedHorizontalRoad = Texture2D::Create("assets/textures/RedHorizontalRoad.png");
	m_RedRoadLeftUp = Texture2D::Create("assets/textures/RedRoadLeftUp.png");
	m_RedRoadRightUp = Texture2D::Create("assets/textures/RedRoadRightUp.png");
	m_RedSettlement = Texture2D::Create("assets/textures/RedSettlement.png");
	m_RedVerticalRoad = Texture2D::Create("assets/textures/RedRoadVertical.png");

	for (int i = 0; i < 4; i++)
	{
		HexNode wood(m_WoodTile, Resource::WOOD);
		m_Tiles.push_back(wood);
		HexNode wheat(m_WheatTile, Resource::WHEAT);
		m_Tiles.push_back(wheat);
		HexNode sheep(m_SheepTile, Resource::SHEEP);
		m_Tiles.push_back(sheep);
	}
	for (int i = 0; i < 3; i++)
	{
		HexNode brick(m_BrickTile, Resource::BRICK);
		m_Tiles.push_back(brick);
		HexNode stone(m_StoneTile, Resource::STONE);
		m_Tiles.push_back(stone);
	}

	//1: 2 12
	//2: 11 4 8 10 9 3 5 6
	DiceValueNode val2(m_Token2, 2);
	m_Tokens.push_back(val2);
	DiceValueNode val12(m_Token12, 12);
	m_Tokens.push_back(val12);
	for (int i = 0; i < 2; i++)
	{
		DiceValueNode val3(m_Token3, 3);
		m_Tokens.push_back(val3);
		DiceValueNode val4(m_Token4, 4);
		m_Tokens.push_back(val4);
		DiceValueNode val5(m_Token5, 5);
		m_Tokens.push_back(val5);
		DiceValueNode val6(m_Token6, 6);
		m_Tokens.push_back(val6);
		DiceValueNode val8(m_Token8, 8);
		m_Tokens.push_back(val8);
		DiceValueNode val9(m_Token9, 9);
		m_Tokens.push_back(val9);
		DiceValueNode val10(m_Token10, 10);
		m_Tokens.push_back(val10);
		DiceValueNode val11(m_Token11, 11);
		m_Tokens.push_back(val11);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_Tiles.begin(), m_Tiles.end(), std::default_random_engine(seed));
	shuffle(m_Tokens.begin(), m_Tokens.end(), std::default_random_engine(seed));

	int insertPoint = Random::Float() * (m_Tiles.size() - 1);
	HexNode sand(m_SandTile);
	m_Tiles.emplace(m_Tiles.begin() + insertPoint, sand);
	DiceValueNode val7(m_Robber, 7);
	m_Tokens.emplace(m_Tokens.begin() + insertPoint, val7);
}

void TileMap::OnUpdate(Timestep ts)
{
	

}

void TileMap::OnRender(std::vector<CrossPoint>& nodeMap)
{
	glm::vec2 standardTileSize = glm::vec2(3.0f);
	glm::vec2 standardTokenSize = glm::vec2(1.0f);
	glm::vec2 testTokenSize = glm::vec2(0.25f);
	float tileOffsetX = 2.1f;
	float tileOffsetY = 1.8f;
	float tileYMidpoint = tileOffsetY * 0.66f;
	float tokenYMidpoint = tileYMidpoint + 0.5f;
	float xStart = -6.0f;
	float yStart = 6.5f;
	float currX;
	float currY = yStart;
	float currZ = 0;
	unsigned int row = 1;


	//for (auto& node : nodeMap)
	//{
	//	//if (std::abs(node.position.x) - 17.0f < 0.0001 && std::abs(node.position.x) - 17.0f > -0.0001)
	//		Renderer2D::DrawQuad(node.position, testTokenSize, m_Token2);
	//}

	//top water row
	currX = xStart + tileOffsetX / 2;
	for (int k = 0; k < 4; k++)
	{
		currZ += 0.01;
		currX += tileOffsetX;
		Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	}

	//2nd row
	int i = 0;
	int vertIter = 0;
	currX = xStart + tileOffsetX;
	currY = yStart - tileOffsetY * row++;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	for (; i < 3; i++, vertIter++)
	{
		currZ += 0.01;
		currX += tileOffsetX;
		glm::vec3 currPos = nodeMap.at(vertIter).position;
		m_Tiles.at(i).position = { currPos.x, currPos.y - tileYMidpoint };
		m_Tiles.at(i).diceValue = m_Tokens.at(i).diceValue;
		Renderer2D::DrawQuad({ m_Tiles.at(i).position.x, m_Tiles.at(i).position.y, currZ }, standardTileSize, m_Tiles.at(i).texture);
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i).texture);
	}
	currX += tileOffsetX;
	currZ += 0.01;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;

	//3rd row
	currX = xStart + tileOffsetX / 2;
	currY = yStart - tileOffsetY * row++;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	for (; i < 7; i++, vertIter++)
	{
		currZ += 0.01;
		currX += tileOffsetX;
		glm::vec3 currPos = nodeMap.at(vertIter).position;
		m_Tiles.at(i).position = { currPos.x, currPos.y - tileYMidpoint};
		m_Tiles.at(i).diceValue = m_Tokens.at(i).diceValue;
		Renderer2D::DrawQuad({ m_Tiles.at(i).position.x, m_Tiles.at(i).position.y, currZ }, standardTileSize, m_Tiles.at(i).texture);
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i).texture);
	}
	currX += tileOffsetX;
	currZ += 0.01;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;

	//4th row (central row)
	currX = xStart;
	currY = yStart - tileOffsetY * row++;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	for (; i < 12; i++, vertIter++)
	{
		currZ += 0.01;
		currX += tileOffsetX;
		glm::vec3 currPos = nodeMap.at(vertIter).position;
		m_Tiles.at(i).position = { currPos.x, currPos.y - tileYMidpoint };
		m_Tiles.at(i).diceValue = m_Tokens.at(i).diceValue;
		Renderer2D::DrawQuad({ m_Tiles.at(i).position.x, m_Tiles.at(i).position.y, currZ }, standardTileSize, m_Tiles.at(i).texture);
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i).texture);
		
	}
	currX += tileOffsetX;
	currZ += 0.01;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;

	//5th row
	currX = xStart + tileOffsetX / 2;
	currY = yStart - tileOffsetY * row++;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;
	for (; i < 16; i++, vertIter++)
	{
		CrossPoint currNode = nodeMap.at(vertIter);
		bool badLeft = (std::abs(currNode.leftNeighbor.position.x) - 17.0f < 0.0001 && std::abs(currNode.leftNeighbor.position.x) - 17.0f > -0.0001);
		bool badRight = (std::abs(currNode.rightNeighbor.position.x) - 17.0f < 0.0001 && std::abs(currNode.rightNeighbor.position.x) - 17.0f > -0.0001);
		if (!badLeft && !badRight)
		{
			currZ += 0.01;
			currX += tileOffsetX;
			glm::vec3 currPos = currNode.position;
			m_Tiles.at(i).position = { currPos.x, currPos.y - tileYMidpoint };
			m_Tiles.at(i).diceValue = m_Tokens.at(i).diceValue;
			Renderer2D::DrawQuad({ m_Tiles.at(i).position.x, m_Tiles.at(i).position.y, currZ }, standardTileSize, m_Tiles.at(i).texture);
			currZ += 0.01;
			Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i).texture);
		}
		else
			i--;
	}
	currX += tileOffsetX;
	currZ += 0.01;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;

	//6th row
	currX = xStart + tileOffsetX;
	currY = yStart - tileOffsetY * row++;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;
	for (; i < m_Tiles.size(); i++, vertIter++)
	{
		CrossPoint currNode = nodeMap.at(vertIter);
		bool badLeft = (std::abs(currNode.leftNeighbor.position.x) - 17.0f < 0.0001 && std::abs(currNode.leftNeighbor.position.x) - 17.0f > -0.0001);
		bool badRight = (std::abs(currNode.rightNeighbor.position.x) - 17.0f < 0.0001 && std::abs(currNode.rightNeighbor.position.x) - 17.0f > -0.0001);

		if (!badLeft && !badRight)
		{
			currZ += 0.01;
			currX += tileOffsetX;
			glm::vec3 currPos = currNode.position;
			m_Tiles.at(i).position = { currPos.x, currPos.y - tileYMidpoint };
			m_Tiles.at(i).diceValue = m_Tokens.at(i).diceValue;
			Renderer2D::DrawQuad({ m_Tiles.at(i).position.x, m_Tiles.at(i).position.y, currZ }, standardTileSize, m_Tiles.at(i).texture);
			currZ += 0.01;
			Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i).texture);
		}
		else
			i--;
	}
	currX += tileOffsetX;
	currZ += 0.01;
	Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	currZ += 0.01;

	//bottom water row
	currX = xStart + tileOffsetX / 2;
	currY = yStart - tileOffsetY * row++;
	for (int k = 0; k < 4; k++)
	{
		currZ += 0.01;
		currX += tileOffsetX;
		Renderer2D::DrawQuad({ currX, currY, currZ }, standardTileSize, m_WaterTile);
	}

	Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, glm::vec2(20.0f), m_Checkerboard, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));

}


void TileMap::RenderStructures(std::vector<CrossPoint>& nodeMap, std::vector<Ref<Player>>& players)
{
	glm::vec2 standardTokenSize = glm::vec2(1.0f);
	for (Structure& structure : players.at(0)->GetStructures())
	{
		switch (structure.buildType)
		{
		case StructureType::SETTLEMENT:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_RedSettlement);
			break;
		case StructureType::CITY:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_RedCity);
			break;
		case StructureType::ROAD_LEFT_UP:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_RedRoadLeftUp);
			break;
		case StructureType::ROAD_RIGHT_UP:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_RedRoadRightUp);
			break;
		case StructureType::ROAD_VERTICAL:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_RedVerticalRoad); //needs to be vertical road when we get it
			break;
		default:
			CR_ASSERT(false, "Bad Structure Value on TileMap render");
		}
	}

	for (Structure& structure : players.at(1)->GetStructures())
	{
		switch (structure.buildType)
		{
		case StructureType::SETTLEMENT:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_BlueSettlement);
			break;
		case StructureType::CITY:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_BlueCity);
			break;
		case StructureType::ROAD_LEFT_UP:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_BlueRoadLeftUp);
			break;
		case StructureType::ROAD_RIGHT_UP:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_BlueRoadRightUp);
			break;
		case StructureType::ROAD_VERTICAL:
			Renderer2D::DrawQuad(structure.position, standardTokenSize, m_BlueVerticalRoad); //needs to be vertical road when we get it
		default:
			CR_ASSERT(false, "Bad Structure Value on TileMap render");
		}
	}
}

void TileMap::GatherResources(std::vector<Crumble::Ref<Player>> players, uint32_t diceRoll)
{
	float tileOffsetX = 2.2f; //these are widened by 0.1
	float tileOffsetY = 1.9f;
	for (auto& player : players)
	{
		for (auto& building : player->GetStructures())
		{
			if (building.buildType == StructureType::SETTLEMENT || building.buildType == StructureType::CITY)
			{
				if(building.buildType == StructureType::CITY)
					CR_TRACE("BUILDING TYPE CITY");
				float negX = building.position.x - tileOffsetX;
				float posX = building.position.x + tileOffsetX;
				float negY = building.position.y - tileOffsetY;
				float posY = building.position.y + tileOffsetY;
				for (auto& resource : m_Tiles)
				{
					if(resource.position.x > negX && resource.position.x < posX && resource.position.y > negY && resource.position.y < posY && resource.diceValue == diceRoll && diceRoll != 7)
					{
						uint32_t resourceCount = (building.buildType == StructureType::CITY) ? 2 : 1;
						CR_TRACE("BEFORE ADDING RESOURCE");
						player->AddResource(resource.type, resourceCount);
						CR_TRACE("AFTER ADDING RESOURCE");
					}
				}
			}
		}
	}
}

void TileMap::OnEvent(Event& e)
{
	
}