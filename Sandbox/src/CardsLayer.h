#pragma once

#include "Crumble.h"
#include "CrossPoint.h"

class CardsLayer
{
public:
	CardsLayer() {};
	virtual ~CardsLayer() = default;

	void Init();
	void OnRender(std::vector<int>& player1, std::vector<int>& player2);


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

	std::vector<Crumble::Ref<Crumble::Texture2D>> p1_Cards;
	std::vector<Crumble::Ref<Crumble::Texture2D>> p1_CardAmount;
	std::vector<Crumble::Ref<Crumble::Texture2D>> p1_CardAmountInt;
	std::vector<Crumble::Ref<Crumble::Texture2D>> p2_Cards;
	std::vector<Crumble::Ref<Crumble::Texture2D>> p2_CardAmount;
	std::vector<Crumble::Ref<Crumble::Texture2D>> p2_CardAmountInt;
};