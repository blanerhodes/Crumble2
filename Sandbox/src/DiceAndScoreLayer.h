#pragma once

#include "Crumble.h"
#include "CrossPoint.h"
#include "Player.h"

class DiceAndScore
{
public:
	DiceAndScore() {};
	virtual ~DiceAndScore() = default;

	void Init();
	void OnRender(std::vector<Crumble::Ref<Player>>& m_Players, uint32_t& m_DiceRoll1, uint32_t& m_DiceRoll2, int m_CurrentPlayer);

private:
	Crumble::Ref<Crumble::Texture2D> m_Dice1Texture;
	Crumble::Ref<Crumble::Texture2D> m_Dice2Texture;
	Crumble::Ref<Crumble::Texture2D> m_Dice3Texture;
	Crumble::Ref<Crumble::Texture2D> m_Dice4Texture;
	Crumble::Ref<Crumble::Texture2D> m_Dice5Texture;
	Crumble::Ref<Crumble::Texture2D> m_Dice6Texture;

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

	Crumble::Ref<Crumble::Texture2D> m_EndTurnButton;

	Crumble::Ref<Crumble::Texture2D> m_ArrowPlayerIndicator;

	// texture vector storing all tokens, index matching number of token
	std::vector<Crumble::Ref<Crumble::Texture2D>> m_StoredTokens;

	// texture vector storing all dice, index + 1 = number of roll
	std::vector<Crumble::Ref<Crumble::Texture2D>> m_StoredDiceNums;
};