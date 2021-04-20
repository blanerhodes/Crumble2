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

	m_P1Settlement = Texture2D::Create("assets/textures/RedSettlement.png");
	m_P1City = Texture2D::Create("assets/textures/RedCity.png");
	m_P1Road = Texture2D::Create("assets/textures/RedHorizontalRoad.png");

	m_P2Settlement = Texture2D::Create("assets/textures/BlueSettlement.png");
	m_P2City = Texture2D::Create("assets/textures/BlueCity.png");
	m_P2Road = Texture2D::Create("assets/textures/BlueHorizontalRoad.png");

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
}

void CardsLayer::OnRender(std::vector<Crumble::Ref<Player>>& m_Players)
{
	glm::vec2 CardSize = glm::vec2(3.0f);
	glm::vec2 BuildGuideSize = glm::vec2(8.0f);
	glm::vec2 TokenSize = glm::vec2(1.0f);
	glm::vec2 BarSize = glm::vec2(4.0f);
	glm::vec2 SelectionSize = glm::vec2(1.0);

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

	for (int i = 0; i < 5; i++) 
	{
		int rec_amount = m_Players.at(0)->GetResources().at(i);
		if (rec_amount > 10) rec_amount = 10;
		if (rec_amount < 0) rec_amount = 0;

		if (i == 0) m_p1_BrickAmount = m_StoredTokens.at(rec_amount);
		if (i == 2) m_p1_StoneAmount = m_StoredTokens.at(rec_amount);
		if (i == 4) m_p1_WoodAmount = m_StoredTokens.at(rec_amount);
		if (i == 3) m_p1_WheatAmount = m_StoredTokens.at(rec_amount);
		if (i == 1) m_p1_SheepAmount = m_StoredTokens.at(rec_amount);
		
		int rec_amount_p2 = m_Players.at(1)->GetResources().at(i);
		if (rec_amount_p2 > 10) rec_amount = 10;
		if (rec_amount_p2 < 0) rec_amount = 0;

		if (i == 0) m_p2_BrickAmount = m_StoredTokens.at(rec_amount_p2);
		if (i == 0) m_p2_StoneAmount = m_StoredTokens.at(rec_amount_p2);
		if (i == 0) m_p2_WoodAmount = m_StoredTokens.at(rec_amount_p2);
		if (i == 0) m_p2_WheatAmount = m_StoredTokens.at(rec_amount_p2);
		if (i == 0) m_p2_SheepAmount = m_StoredTokens.at(rec_amount_p2);
	}
	

	Renderer2D::DrawQuad({ currX + 0.80, yStart + 1.5, currZ }, BarSize, m_BlackBar);
	Renderer2D::DrawQuad({ 11.5, yStart + 1.5, currZ}, BarSize, m_BlackBar);

	currZ += 0.01;
	Renderer2D::DrawQuad({ currX, yStart, currZ}, CardSize, m_BrickCard);
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

	
	// Clickable - city, road, settlement, for each player.
	//PLAYER ONE
	currZ += 0.01;
	Renderer2D::DrawQuad({ -13.2, yStart + 1.5, currZ }, SelectionSize, m_P1Road);
	currZ += 0.01;
	Renderer2D::DrawQuad({ -12.2, yStart + 1.5, currZ }, SelectionSize, m_P1Settlement);
	currZ += 0.01;
	Renderer2D::DrawQuad({ -11.2, yStart + 1.5, currZ }, SelectionSize, m_P1City);

	//PLAYER TWO
	currZ += 0.01;
	Renderer2D::DrawQuad({ 10.5, yStart + 1.5, currZ }, SelectionSize, m_P2Road);
	currZ += 0.01;
	Renderer2D::DrawQuad({ 11.5, yStart + 1.5, currZ }, SelectionSize, m_P2Settlement);
	currZ += 0.01;
	Renderer2D::DrawQuad({ 12.5, yStart + 1.5, currZ }, SelectionSize, m_P2City);

	//currZ += 0.01;
	//Renderer2D::DrawQuad({ 0.0f, 0.0f, 10 }, glm::vec2(10.0f), m_BlackBar, 10.0f, glm::vec4(-14.0f, -0.5f, -7.9f, -6.4f));
}

