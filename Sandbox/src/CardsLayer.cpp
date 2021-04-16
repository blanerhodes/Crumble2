#include "CardsLayer.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <random>

using namespace Crumble;


void CardsLayer::Init()
{
	
	//Resource cards
	m_BrickCard = Texture2D::Create("assets/textures/BrickCard.png");
	m_SheepCard = Texture2D::Create("assets/textures/SheepCard.png");
	m_StoneCard = Texture2D::Create("assets/textures/StoneCard.png");
	m_WheatCard = Texture2D::Create("assets/textures/WheatCard.png");
	m_WoodCard  = Texture2D::Create("assets/textures/WoodCard.png");

	//standalone card -> for reference
	m_BuildingCosts = Texture2D::Create("assets/textures/BuildingCostsCard.png");
	m_BlackBar = Texture2D::Create("assets/textures/BlackBar.png");

	//Tokens for rendering the amount of cards player has
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

	p1_Cards.push_back(m_BrickCard);
	p1_Cards.push_back(m_WoodCard);
	p1_Cards.push_back(m_StoneCard);
	p1_Cards.push_back(m_SheepCard);
	p1_Cards.push_back(m_WheatCard);
	for (int i = 0; i < 5; i++) p1_CardAmount.push_back(m_Token0);
	for (int i = 0; i < 5; i++) p1_CardAmountInt.push_back(0);

	p2_Cards.push_back(m_BrickCard);
	p2_Cards.push_back(m_WoodCard);
	p2_Cards.push_back(m_StoneCard);
	p2_Cards.push_back(m_SheepCard);
	p2_Cards.push_back(m_WheatCard);
	for (int i = 0; i < 5; i++) p2_CardAmount.push_back(m_Token0);
	for (int i = 0; i < 5; i++) p2_CardAmountInt.push_back(0);
}

void CardsLayer::OnRender(std::vector<int>& player1, std::vector<int>& player2)
{
	glm::vec2 CardSize = glm::vec2(3.0f);
	glm::vec2 BuildGuideSize = glm::vec2(8.0f);
	glm::vec2 TokenSize = glm::vec2(1.0f);
	glm::vec2 BarSize = glm::vec2(4.0f);

	float xStart = -12.0f;
	float yStart = -6.0f;

	float currX = -13.0f;
	float currZ = 0.01;

	// Render the Building Costs
	auto& window = Application::Get().GetWindow();
	float windowWidth = window.GetWidth();
	float windowHeight = window.GetHeight();


	Crumble::Ref<Crumble::Texture2D> m_p1_BrickAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p1_StoneAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p1_WoodAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p1_SheepAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p1_WheatAmount = m_Token0;

	Crumble::Ref<Crumble::Texture2D> m_p2_BrickAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p2_StoneAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p2_WoodAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p2_SheepAmount = m_Token0;
	Crumble::Ref<Crumble::Texture2D> m_p2_WheatAmount = m_Token0;

	Renderer2D::DrawQuad({xStart, 5.0f, 1}, BuildGuideSize, m_BuildingCosts);

	//PLAYER 1

	// order -> BRICK = 0, SHEEP = 1, STONE = 2, WHEAT = 3,	WOOD = 4
	for (int& resource : player1)
	{
		// BRICK
		if (resource == 0)
		{

		}
	}

	Renderer2D::DrawQuad({ currX + 2, yStart + 4, currZ}, BarSize, m_BlackBar);

	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_BrickCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p1_BrickAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_StoneCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p1_StoneAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_WheatCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p1_WheatAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_SheepCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p1_SheepAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_WoodCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p1_WoodAmount);

	// PLAYER 2
	currX = 7.2f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_BrickCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p2_BrickAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_StoneCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p2_StoneAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_WheatCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p2_WheatAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_SheepCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p2_SheepAmount);
	currZ += 0.01;
	currX += 1.3f;
	Renderer2D::DrawQuad({ currX, yStart, currZ }, CardSize, m_WoodCard);
	Renderer2D::DrawQuad({ currX, yStart - 0.5f, currZ + 0.01 }, TokenSize, m_p2_WoodAmount);
}

