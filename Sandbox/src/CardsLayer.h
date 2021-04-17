#pragma once

#include "Crumble.h"
#include "CrossPoint.h"
#include "Player.h"

class CardsLayer
{
public:
	CardsLayer() {};
	virtual ~CardsLayer() = default;

	void Init();
	void OnRender(std::vector<Crumble::Ref<Player>>& m_Players);


private:
	Crumble::Ref<Crumble::Texture2D> m_BrickCard;
	Crumble::Ref<Crumble::Texture2D> m_SheepCard;
	Crumble::Ref<Crumble::Texture2D> m_StoneCard;
	Crumble::Ref<Crumble::Texture2D> m_WheatCard;
	Crumble::Ref<Crumble::Texture2D> m_WoodCard;

	Crumble::Ref<Crumble::Texture2D> m_BuildingCosts;
	Crumble::Ref<Crumble::Texture2D> m_BlackBar;

	Crumble::Ref<Crumble::Texture2D> m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_Token1;
	Crumble::Ref<Crumble::Texture2D> m_Token2;
	Crumble::Ref<Crumble::Texture2D> m_Token3;
	Crumble::Ref<Crumble::Texture2D> m_Token4;
	Crumble::Ref<Crumble::Texture2D> m_Token5;
	Crumble::Ref<Crumble::Texture2D> m_Token6;
	Crumble::Ref<Crumble::Texture2D> m_Token7;
	Crumble::Ref<Crumble::Texture2D> m_Token8;
	Crumble::Ref<Crumble::Texture2D> m_Token9;
	Crumble::Ref<Crumble::Texture2D> m_Token10;

	Crumble::Ref<Crumble::Texture2D> m_P1Settlement;
	Crumble::Ref<Crumble::Texture2D> m_P1Road;
	Crumble::Ref<Crumble::Texture2D> m_P1City;

	Crumble::Ref<Crumble::Texture2D> m_P2Settlement;
	Crumble::Ref<Crumble::Texture2D> m_P2Road;
	Crumble::Ref<Crumble::Texture2D> m_P2City;

	// Stores tokens so that index -> number texture
	std::vector<Crumble::Ref<Crumble::Texture2D>> m_StoredTokens;
};