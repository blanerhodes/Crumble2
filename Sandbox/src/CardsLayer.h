#pragma once

#include "Crumble.h"
#include "GameLayer.h"

using namespace Crumble;

class CardsLayer : public Crumble::Layer 
{
public:
	CardsLayer();
	virtual ~CardsLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(Crumble::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Crumble::Event & event) override;

	bool OnMouseButtonPressed(Crumble::MouseButtonPressedEvent & e);
	Ref<Player> GetPlayer(std::string name);
private:
	Crumble::Ref<Crumble::Texture2D> m_BrickCard;
	Crumble::Ref<Crumble::Texture2D> m_SandCard;
	Crumble::Ref<Crumble::Texture2D> m_SheepCard;
	Crumble::Ref<Crumble::Texture2D> m_StoneCard;
	Crumble::Ref<Crumble::Texture2D> m_WaterCard;
	Crumble::Ref<Crumble::Texture2D> m_WheatCard;
	Crumble::Ref<Crumble::Texture2D> m_WoodCard;

	std::vector<Player> m_Players;
};