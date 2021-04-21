#include "DiceAndScoreLayer.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <random>

using namespace Crumble;

void DiceAndScore::Init()
{
	m_Dice1Texture = Texture2D::Create("assets/textures/dice/Roll1.png");
	m_Dice2Texture = Texture2D::Create("assets/textures/dice/Roll2.png");
	m_Dice3Texture = Texture2D::Create("assets/textures/dice/Roll3.png");
	m_Dice4Texture = Texture2D::Create("assets/textures/dice/Roll4.png");
	m_Dice5Texture = Texture2D::Create("assets/textures/dice/Roll5.png");
	m_Dice6Texture = Texture2D::Create("assets/textures/dice/Roll6.png");

	m_StoredDiceNums.push_back(m_Dice1Texture);
	m_StoredDiceNums.push_back(m_Dice2Texture);
	m_StoredDiceNums.push_back(m_Dice3Texture);
	m_StoredDiceNums.push_back(m_Dice4Texture);
	m_StoredDiceNums.push_back(m_Dice5Texture);
	m_StoredDiceNums.push_back(m_Dice6Texture);

	m_Token0 = Texture2D::Create("assets/textures/Token0.png");
	m_Token1 = Texture2D::Create("assets/textures/Token1.png");
	m_Token2 = Texture2D::Create("assets/textures/Token2.png");
	m_Token3 = Texture2D::Create("assets/textures/Token3.png");
	m_Token4 = Texture2D::Create("assets/textures/Token4.png");
	m_Token5 = Texture2D::Create("assets/textures/Token5.png");
	m_Token6 = Texture2D::Create("assets/textures/Token6.png");
	m_Token7 = Texture2D::Create("assets/textures/Token7.png");
	m_Token8 = Texture2D::Create("assets/textures/Token8.png");
	m_Token9 = Texture2D::Create("assets/textures/Token9.png");
	m_Token10 = Texture2D::Create("assets/textures/Token10.png");

	m_StoredTokens.push_back(m_Token0);
	m_StoredTokens.push_back(m_Token1);
	m_StoredTokens.push_back(m_Token2);
	m_StoredTokens.push_back(m_Token3);
	m_StoredTokens.push_back(m_Token4);
	m_StoredTokens.push_back(m_Token5);
	m_StoredTokens.push_back(m_Token6);
	m_StoredTokens.push_back(m_Token7);
	m_StoredTokens.push_back(m_Token8);
	m_StoredTokens.push_back(m_Token9);
	m_StoredTokens.push_back(m_Token10);

	m_EndTurnButton = Texture2D::Create("assets/textures/EndTurn.png");

}

void DiceAndScore::OnRender(std::vector<Crumble::Ref<Player>>& m_Players, uint32_t& m_DiceRoll1, uint32_t& m_DiceRoll2)
{

	glm::vec2 DieSize = glm::vec2(3.0f);
	glm::vec2 ScoreSize = glm::vec2(2.0f);
	glm::vec2 EndSize = glm::vec2(3.5f);

	Crumble::Ref<Crumble::Texture2D> m_p1Score = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p2Score = m_Token0;

	//cap score at 10, can't go beneath 0
	m_p1Score = m_StoredTokens.at(std::min((unsigned int)10, m_Players.at(0)->GetScore()));
	m_p2Score = m_StoredTokens.at(std::min((unsigned int)10, m_Players.at(1)->GetScore()));

	// Drawing the scores on each player's side
	Renderer2D::DrawQuad({ -8.5f, -4.5f, 0.9f }, ScoreSize, m_p1Score);
	Renderer2D::DrawQuad({ 7.8f, -4.5f, 0.9f }, ScoreSize, m_p2Score);

	Crumble::Ref<Crumble::Texture2D> m_Dice1 = m_Dice1Texture;
	Crumble::Ref<Crumble::Texture2D> m_Dice2 = m_Dice1Texture;

	m_Dice1 = m_StoredDiceNums.at(m_DiceRoll1);
	m_Dice2 = m_StoredDiceNums.at(m_DiceRoll2);

	// Drawing the dice on top right
	Renderer2D::DrawQuad({ 10.5f, 6.5f, 0.05f }, DieSize, m_Dice1);
	Renderer2D::DrawQuad({ 12.5f, 6.5f, 0.06f }, DieSize, m_Dice2);

	// Drawing the End Turn button
	Renderer2D::DrawQuad({0.0f, -7.3f, 0.9f}, EndSize, m_EndTurnButton);
}