#include "CardsLayer.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <random>

using namespace Crumble;

CardsLayer::CardsLayer() : Layer("CardsLayer")
{
	m_Players.emplace_back("Player1");
	m_Players.emplace_back("Player2");
}

void CardsLayer::OnAttach()
{
	m_BrickCard = Texture2D::Create("assets/textures/BrickTile.png");
	m_SandCard  = Texture2D::Create("assets/textures/SandTile.png");
	m_SheepCard = Texture2D::Create("assets/textures/SheepTile.png");
	m_StoneCard = Texture2D::Create("assets/textures/StoneTile.png");
	m_WaterCard = Texture2D::Create("assets/textures/WaterTile.png");
	m_WheatCard = Texture2D::Create("assets/textures/WheatTile.png");
	m_WoodCard  = Texture2D::Create("assets/textures/WoodTile.png");

}

void CardsLayer::OnDetach()
{
}

void CardsLayer::OnUpdate(Timestep ts)
{
	

}

void CardsLayer::OnImGuiRender()
{
	
}

void CardsLayer::OnEvent(Event& e)
{
	/*EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(CR_BIND_EVENT_FN(GameLayer::OnWindowResize));*/

}

bool CardsLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
{
	
	return false;
}

Ref<Player> CardsLayer::GetPlayer(std::string name)
{
	for (auto& player : m_Players)
	{
		if (player.GetName() == name)
		{
			return CreateRef<Player>(player);
		}
	}
}