#pragma once

#include "Crumble.h"
#include "CrossPoint.h"

class TileMap
{
public:
	TileMap() {};
	virtual ~TileMap() = default;

	void Init();
	void OnRender(std::vector<std::vector<CrossPoint>>& nodeMap);
	
	void OnUpdate(Crumble::Timestep ts);
	void OnImGuiRender();
	void OnEvent(Crumble::Event& event);

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

	Crumble::Ref<Crumble::Shader> m_FlatColorShader;

	Crumble::Ref<Crumble::Texture2D> m_Checkerboard;
	std::vector<Crumble::Ref<Crumble::Texture2D>> m_Tiles;
	std::vector<Crumble::Ref<Crumble::Texture2D>> m_Tokens;

};

