#pragma once

#include "Crumble.h"
#include "CrossPoint.h"
#include "Player.h"

struct HexNode
{
	Crumble::Ref<Crumble::Texture2D> texture;
	Resource type;
	glm::vec2 position;
	uint8_t diceValue;

	HexNode(Crumble::Ref<Crumble::Texture2D> tex, Resource rec = Resource::NONE, glm::vec2 pos = glm::vec2(1.0f),  uint8_t value = 0) : texture(tex), type(rec), position(pos), diceValue(value) {}
};

struct DiceValueNode
{
	Crumble::Ref<Crumble::Texture2D> texture;
	uint8_t diceValue = 0;
	DiceValueNode(Crumble::Ref<Crumble::Texture2D> tex, uint8_t val) : texture(tex), diceValue(val){}
};


class TileMap
{
public:
	TileMap() {};
	virtual ~TileMap() = default;

	void Init();
	void OnRender(std::vector<CrossPoint>& nodeMap);
	void RenderStructures(std::vector<CrossPoint>& nodeMap, std::vector<Crumble::Ref<Player>>& players);
	
	void OnUpdate(Crumble::Timestep ts);
	void OnImGuiRender();
	void OnEvent(Crumble::Event& event);
	void GatherResources(std::vector<Crumble::Ref<Player>> players, uint32_t diceRoll);

private:
	Crumble::Ref<Crumble::VertexArray> m_SquareVA;
	Crumble::Ref<Crumble::Texture2D> m_BrickTile;
	Crumble::Ref<Crumble::Texture2D> m_SandTile;
	Crumble::Ref<Crumble::Texture2D> m_SheepTile;
	Crumble::Ref<Crumble::Texture2D> m_StoneTile;
	Crumble::Ref<Crumble::Texture2D> m_WaterTile;
	Crumble::Ref<Crumble::Texture2D> m_WheatTile;
	Crumble::Ref<Crumble::Texture2D> m_WoodTile;

	Crumble::Ref<Crumble::Texture2D> m_Token2;
	Crumble::Ref<Crumble::Texture2D> m_Token3;
	Crumble::Ref<Crumble::Texture2D> m_Token4;
	Crumble::Ref<Crumble::Texture2D> m_Token5;
	Crumble::Ref<Crumble::Texture2D> m_Token6;
	Crumble::Ref<Crumble::Texture2D> m_Token7;
	Crumble::Ref<Crumble::Texture2D> m_Token8;
	Crumble::Ref<Crumble::Texture2D> m_Token9;
	Crumble::Ref<Crumble::Texture2D> m_Token10;
	Crumble::Ref<Crumble::Texture2D> m_Token11;
	Crumble::Ref<Crumble::Texture2D> m_Token12;
	Crumble::Ref<Crumble::Texture2D> m_Robber;

	Crumble::Ref<Crumble::Texture2D> m_BlueCity;
	Crumble::Ref<Crumble::Texture2D> m_BlueHorizontalRoad;
	Crumble::Ref<Crumble::Texture2D> m_BlueRoadLeftUp;
	Crumble::Ref<Crumble::Texture2D> m_BlueRoadRightUp;
	Crumble::Ref<Crumble::Texture2D> m_BlueSettlement;
	Crumble::Ref<Crumble::Texture2D> m_BlueVerticalRoad;
	Crumble::Ref<Crumble::Texture2D> m_RedCity;
	Crumble::Ref<Crumble::Texture2D> m_RedHorizontalRoad;
	Crumble::Ref<Crumble::Texture2D> m_RedRoadLeftUp;
	Crumble::Ref<Crumble::Texture2D> m_RedRoadRightUp;
	Crumble::Ref<Crumble::Texture2D> m_RedSettlement;
	Crumble::Ref<Crumble::Texture2D> m_RedVerticalRoad;

	

	Crumble::Ref<Crumble::Shader> m_FlatColorShader;

	Crumble::Ref<Crumble::Texture2D> m_Checkerboard;
	std::vector<HexNode> m_Tiles;
	std::vector<DiceValueNode> m_Tokens;

};

