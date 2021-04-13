#pragma once

#include "Crumble.h"
#include "TileMap.h"
#include "Player.h"
#include "CrossPoint.h"


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
private:
	Crumble::Scope<Crumble::OrthographicCamera> m_Camera;
	TileMap m_TileMap;
	std::vector<std::vector<CrossPoint>> m_NodeMap;
	Crumble::Ref<Player> m_Player1;
	Crumble::Ref<Player> m_Player2;
	//ImFont* m_Font;
};