#pragma once

#include "Crumble.h"
#include "TileMap.h"
#include "Player.h"
#include "CrossPoint.h"

enum class ActiveFrame
{
	NONE = -1, MAP = 0, PLAYER1_CARDS = 1, PLAYER2_CARDS = 2
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
private:
	Crumble::Scope<Crumble::OrthographicCamera> m_Camera;
	TileMap m_TileMap;
	std::vector<CrossPoint> m_NodeMap;
	std::vector<Crumble::Ref<Player>> m_Players;
	int m_CurrentPlayer = 0;
	uint32_t m_CurrentDiceRoll = 8;
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
	glm::vec4 m_Player1CardsFrame = glm::vec4({ -14.0f, -5.5f, -7.9f, -6.4f });
	glm::vec4 m_Player2CardsFrame = glm::vec4({ 5.5f, 14.0f, -7.9f, -6.4f });
	
};