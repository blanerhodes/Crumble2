#pragma once

#include "Crumble.h"
#include "TileMap.h"
#include "CardsLayer.h"
#include "Player.h"
#include "CrossPoint.h"
#include "DiceAndScoreLayer.h"

enum class ActiveFrame
{
	NONE = -1, MAP = 0, PLAYER1_CARDS = 1, PLAYER2_CARDS = 2, P1_ROAD = 3, P1_CITY = 4, P1_SETTLEMENT = 5, DICE_ROLL = 6,
		P2_ROAD = 7, P2_SETTLEMENT = 8, P2_CITY = 9, END_TURN = 10
};

class GameLayer : public Crumble::Layer 
{
public:
	GameLayer();
	virtual ~GameLayer() = default;
	void InitNodeMap(float xAnchor, float yAnchor);
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Crumble::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Crumble::Event& e) override;
	bool OnMouseButtonPressed(Crumble::MouseButtonPressedEvent& e);
	bool OnWindowResize(Crumble::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
	ActiveFrame GetActiveFrame(float x, float y);
	void HandleMapEvents(float normX, float normY);
	void HandleP1PlacementEvents(float normX, float normY, StructureType structure);

	void RollDiceEvent();
private:
	Crumble::Scope<Crumble::OrthographicCamera> m_Camera;
	TileMap m_TileMap;
	CardsLayer m_CardsLayer;
	DiceAndScore m_DiceAndScore;

	std::vector<CrossPoint> m_NodeMap;
	std::vector<Crumble::Ref<Player>> m_Players;
	int m_CurrentPlayer = 1;
	uint32_t m_DiceRoll1 = 0;
	uint32_t m_DiceRoll2 = 0;
	uint32_t m_CurrentDiceRoll = m_DiceRoll1 + m_DiceRoll2 + 2;
	bool m_RollState = false;
	StructureType m_Selection = StructureType::SETTLEMENT;
	bool m_MouseState = true;

	float m_AspectRatio;
	float m_CamWidth = 8.0f;
	float m_Bottom = -m_CamWidth;
	float m_Top = m_CamWidth;
	float m_Left;
	float m_Right;

	glm::vec4 m_MapFrame = glm::vec4({-6.0f, 6.0f, -6.5f, 6.5f});
	glm::vec4 m_Player1CardsFrame = glm::vec4({ -14.0f, -10.5f, -5.0f, -4.0f });
	glm::vec4 m_Player1Road = glm::vec4({ -13.8f, -12.6f, -5.0f, -4.0f });
	glm::vec4 m_Player1Settlement = glm::vec4({ -12.6f, -12.0f, -5.0f, -4.0f });
	glm::vec4 m_Player1City = glm::vec4({ -11.6f, -10.5f, -5.0f, -4.0f });

	glm::vec4 m_Player2CardsFrame = glm::vec4({ 10.0f, 13.2f, -5.0f, -4.0f });
	glm::vec4 m_Player2Road = glm::vec4({ 10.0f, 10.9f, -5.0f, -4.0f });
	glm::vec4 m_Player2Settlement = glm::vec4({ 11.0f, 11.9f, -5.0f, -4.0f });
	glm::vec4 m_Player2City = glm::vec4({ 12.0f, 13.0f, -5.0f, -4.0f });

	glm::vec4 m_DiceRollFrame = glm::vec4({ 9.4f, 13.8f, 5.5f, 7.8f });

	glm::vec4 m_EndTurnFrame = glm::vec4({ -1.5f, 1.5f, -7.9f, -6.0f });

	// TESTING PURPOSES
	//Crumble::Ref<Crumble::Texture2D> m_Token2;
	
};