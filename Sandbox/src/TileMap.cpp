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

	for (int i = 0; i < 4; i++)
	{
		m_Tiles.push_back(m_WoodTile);
		m_Tiles.push_back(m_WheatTile);
		m_Tiles.push_back(m_SheepTile);
	}
	for (int i = 0; i < 3; i++)
	{
		m_Tiles.push_back(m_BrickTile);
		m_Tiles.push_back(m_StoneTile);
	}

	//1: 2 12
	//2: 11 4 8 10 9 3 5 6
	m_Tokens.push_back(m_Token2);
	m_Tokens.push_back(m_Token12);
	for (int i = 0; i < 2; i++)
	{
		m_Tokens.push_back(m_Token3);
		m_Tokens.push_back(m_Token4);
		m_Tokens.push_back(m_Token5);
		m_Tokens.push_back(m_Token6);
		m_Tokens.push_back(m_Token8);
		m_Tokens.push_back(m_Token9);
		m_Tokens.push_back(m_Token10);
		m_Tokens.push_back(m_Token11);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_Tiles.begin(), m_Tiles.end(), std::default_random_engine(seed));
	shuffle(m_Tokens.begin(), m_Tokens.end(), std::default_random_engine(seed));

	int insertPoint = Random::Float() * (m_Tiles.size() - 1);
	m_Tiles.emplace(m_Tiles.begin() + insertPoint, m_SandTile);
	m_Tokens.emplace(m_Tokens.begin() + insertPoint, m_Robber);
}

void TileMap::OnUpdate(Timestep ts)
{
	

}

void TileMap::OnRender(std::vector<std::vector<CrossPoint>>& nodeMap)
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

	//top water row
	for (auto& vec: nodeMap)
	{
		for(auto& node: vec)
		{ 
			if(node.position.x != -17.0f)
				Renderer2D::DrawQuad(node.position, testTokenSize, m_Token2);
		}

	}

	currX = xStart + tileOffsetX / 2;
	/*Renderer2D::DrawQuad({ currX + tileOffsetX, currY + tileOffsetY * 0.66f, currZ+1 }, testTokenSize, m_Token9);
	Renderer2D::DrawQuad({ currX + tileOffsetX / 2, currY + tileOffsetY / 3, currZ + 1 }, testTokenSize, m_Token8);
	Renderer2D::DrawQuad({ currX + tileOffsetX * 1.5f, currY - tileOffsetY / 3, currZ + 1 }, testTokenSize, m_Token8);*/

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
		glm::vec3 currPos = nodeMap.at(vertIter).at(0).position;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tileYMidpoint, currZ }, standardTileSize, m_Tiles.at(i));
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i));
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
		glm::vec3 currPos = nodeMap.at(vertIter).at(0).position;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tileYMidpoint, currZ }, standardTileSize, m_Tiles.at(i));
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i));
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
		glm::vec3 currPos = nodeMap.at(vertIter).at(0).position;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tileYMidpoint, currZ }, standardTileSize, m_Tiles.at(i));
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i));
		
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
	for (; i < 16; i++)
	{
		if (nodeMap.at(vertIter).at(1).position.x != -17.0f || nodeMap.at(vertIter).at(3).position.x != -17.0f)
		{
			currZ += 0.01;
			currX += tileOffsetX;
			glm::vec3 currPos = nodeMap.at(vertIter).at(0).position;
			Renderer2D::DrawQuad({ currPos.x, currPos.y - tileYMidpoint, currZ }, standardTileSize, m_Tiles.at(i));
			currZ += 0.01;
			Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i));
			vertIter++;
		}
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
		currZ += 0.01;
		currX += tileOffsetX;
		glm::vec3 currPos = nodeMap.at(vertIter).at(0).position;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tileYMidpoint, currZ }, standardTileSize, m_Tiles.at(i));
		currZ += 0.01;
		Renderer2D::DrawQuad({ currPos.x, currPos.y - tokenYMidpoint, currZ }, standardTokenSize, m_Tokens.at(i));
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


void TileMap::OnImGuiRender()
{
	
}

void TileMap::OnEvent(Event& e)
{
	
}