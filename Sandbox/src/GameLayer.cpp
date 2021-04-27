#include "GameLayer.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Random.h"

using namespace Crumble;

GameLayer::GameLayer() : Layer("GameLayer")
{
	auto& window = Application::Get().GetWindow();
	CreateCamera(window.GetWidth(), window.GetHeight());
	m_Players.emplace_back(CreateRef<Player>("Player1"));
	m_Players.emplace_back(CreateRef<Player>("Player2"));

	Random::Init();
	InitNodeMap(-6.0f, 6.5f);
	CR_TRACE("NodeMap size: {0}", m_NodeMap.size());

	for (auto& player: m_Players) {
		player->AddResource(Resource::WOOD, 4);
		player->AddResource(Resource::SHEEP, 2);
		player->AddResource(Resource::WHEAT, 2);
		player->AddResource(Resource::BRICK, 4);
	}
	// TESTING PURPOSES
	//m_Token2 = Texture2D::Create("assets/textures/Token2.png");
}

void GameLayer::OnAttach()
{
	m_TileMap.Init();
	// cards layer
	m_CardsLayer.Init();
	// dice and score layer
	m_DiceAndScore.Init();

}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(Timestep ts)
{
	if (Input::IsMouseButtonPressed(CR_MOUSE_BUTTON_1) && m_MouseState)
	{
		auto& window = Application::Get().GetWindow();
		std::pair<float, float> position = Input::GetMousePosition();
		float scaleX = window.GetWidth() / (2 * m_Right);
		float normX = position.first / scaleX - m_Right;
		float scaleY = window.GetHeight() / (2 * m_Top);
		float normY = -(position.second / scaleY - m_Top);
		switch (GetActiveFrame(normX, normY))
		{
		case ActiveFrame::MAP:
			HandleMapEvents(normX, normY);
			break;
		case ActiveFrame::P1_ROAD:
			CR_TRACE("CLICKED IN P1_ROAD");
			HandleP1PlacementEvents(normX, normY, StructureType::ROAD);
			break;
		case ActiveFrame::P1_CITY:
			CR_TRACE("CLICKED IN P1_CITY");
			HandleP1PlacementEvents(normX, normY, StructureType::CITY);
			break;
		case ActiveFrame::P1_SETTLEMENT:
			CR_TRACE("CLICKED IN P1_SETTLEMENT");
			HandleP1PlacementEvents(normX, normY, StructureType::SETTLEMENT);
			break;
		case ActiveFrame::P2_ROAD:
			CR_TRACE("CLICKED IN P2_ROAD");
			HandleP1PlacementEvents(normX, normY, StructureType::ROAD);
			break;
		case ActiveFrame::P2_CITY:
			CR_TRACE("CLICKED IN P2_CITY");
			HandleP1PlacementEvents(normX, normY, StructureType::CITY);
			break;
		case ActiveFrame::P2_SETTLEMENT:
			CR_TRACE("CLICKED IN P2_SETTLEMENT");
			HandleP1PlacementEvents(normX, normY, StructureType::SETTLEMENT);
			break;
		case ActiveFrame::DICE_ROLL:
			CR_TRACE("CLICKED IN DICE_ROLL");
			RollDiceEvent();
			m_TileMap.GatherResources(m_Players, m_CurrentDiceRoll);
			
			for (auto& resource : m_Players.at(0)->GetResources())
			{
				CR_TRACE("Resource Count: {0}", resource);
			}
			break;
		case ActiveFrame::END_TURN:
			// change players
			if (m_CurrentPlayer == 0)
				m_CurrentPlayer = 1;
			else
				m_CurrentPlayer = 0;
			CR_TRACE("CLICKED END TURN");
			break;
		default:
			CR_TRACE("CLICKED OUTSIDE OF MAP WINDOW");
		}
		
		
	}
	m_MouseState = Input::IsMouseButtonReleased(CR_MOUSE_BUTTON_1);

	m_TileMap.OnUpdate(ts);
	//card
	//m_CardsLayer.OnUpdate(ts);

	RenderCommand::SetClearColor({ 0.0f, 0.0f, 0.0f, 1 });
	RenderCommand::Clear();
	Renderer2D::BeginScene(*m_Camera);
	m_TileMap.OnRender(m_NodeMap);
	//card
	m_CardsLayer.OnRender(m_Players);
	m_DiceAndScore.OnRender(m_Players, m_DiceRoll1, m_DiceRoll2, m_CurrentPlayer);

	//card
	m_TileMap.RenderStructures(m_NodeMap, m_Players);
	Renderer2D::EndScene();

	/*for (auto& node : m_NodeMap)
	{
		Renderer2D::DrawQuad(node.position, glm::vec3(0.5), m_Token2);
	}*/
	
	/*
	TO SEE THE BOX AROUND A SETTLEMENT/BUILDING

	float tileOffsetX = 2.0f / 1.6f; //these are widened by 0.1
	float tileOffsetY = 1.7f / 1.3f;
	for (auto& player : m_Players)
	{
		for (auto& building : player->GetStructures())
		{
			if (building.buildType == StructureType::SETTLEMENT || building.buildType == StructureType::CITY)
			{
				if (building.buildType == StructureType::CITY)
					CR_TRACE("BUILDING TYPE CITY");
				float negX = building.position.x - tileOffsetX;
				float posX = building.position.x + tileOffsetX;
				float negY = building.position.y - tileOffsetY;
				float posY = building.position.y + tileOffsetY;

				Renderer2D::DrawQuad({ negX, negY, 1 }, glm::vec3(0.5), m_Token2);
				Renderer2D::DrawQuad({ negX, posY, 1 }, glm::vec3(0.5), m_Token2);
				Renderer2D::DrawQuad({ posX, negY, 1 }, glm::vec3(0.5), m_Token2);
				Renderer2D::DrawQuad({ posX, posY, 1 }, glm::vec3(0.5), m_Token2);
			}
		}
	}*/
}


void GameLayer::OnImGuiRender()
{

}

void GameLayer::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(CR_BIND_EVENT_FN(GameLayer::OnWindowResize));
	dispatcher.Dispatch<MouseButtonPressedEvent>(CR_BIND_EVENT_FN(GameLayer::OnMouseButtonPressed));
}

bool GameLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
{
	return false;
}

bool GameLayer::OnWindowResize(WindowResizeEvent& e)
{
	CreateCamera(e.GetWidth(), e.GetHeight());
	return false;
}

void GameLayer::CreateCamera(uint32_t width, uint32_t height)
{
	m_AspectRatio = (float)width / (float)height;
	m_Left = m_Bottom * m_AspectRatio;
	m_Right = m_Top * m_AspectRatio;
	m_Camera = CreateScope<OrthographicCamera>(m_Left, m_Right, m_Bottom, m_Top);
}

ActiveFrame GameLayer::GetActiveFrame(float x, float y)
{
	if (x > m_MapFrame.r && x < m_MapFrame.g && y > m_MapFrame.b && y < m_MapFrame.a)
		return ActiveFrame::MAP;
	if (x > m_Player1Road.r && x < m_Player1Road.g && y > m_Player1Road.b && y < m_Player1Road.a)
		return ActiveFrame::P1_ROAD;
	if (x > m_Player1City.r && x < m_Player1City.g && y > m_Player1City.b && y < m_Player1City.a)
		return ActiveFrame::P1_CITY;
	if (x > m_Player1Settlement.r && x < m_Player1Settlement.g && y > m_Player1Settlement.b && y < m_Player1Settlement.a)
		return ActiveFrame::P1_SETTLEMENT;	
	//if (x > m_Player1CardsFrame.r && x < m_Player1CardsFrame.g && y > m_Player1CardsFrame.b && y < m_Player1CardsFrame.a)
		//return ActiveFrame::PLAYER1_CARDS;
	//if (x > m_Player2CardsFrame.r && x < m_Player2CardsFrame.g && y > m_Player2CardsFrame.b && y < m_Player2CardsFrame.a)
		//return ActiveFrame::PLAYER2_CARDS;
	if (x > m_Player2Road.r && x < m_Player2Road.g && y > m_Player2Road.b && y < m_Player2Road.a)
		return ActiveFrame::P2_ROAD;
	if (x > m_Player2City.r && x < m_Player2City.g && y > m_Player2City.b && y < m_Player2City.a)
		return ActiveFrame::P2_CITY;
	if (x > m_Player2Settlement.r && x < m_Player2Settlement.g && y > m_Player2Settlement.b && y < m_Player2Settlement.a)
		return ActiveFrame::P2_SETTLEMENT;
	if (x > m_DiceRollFrame.r && x < m_DiceRollFrame.g && y > m_DiceRollFrame.b && y < m_DiceRollFrame.a)
		return ActiveFrame::DICE_ROLL;
	if (x > m_EndTurnFrame.r && x < m_EndTurnFrame.g && y > m_EndTurnFrame.b && y < m_EndTurnFrame.a)
		return ActiveFrame::END_TURN;

	
}

void GameLayer::HandleMapEvents(float normX, float normY) 
{
	//CR_TRACE("Left: {0}, Right: {1}, Top: {2}, Bottom: {3}", m_Left, m_Right, m_Top, m_Bottom);
	
	//CR_TRACE("NormX: {0}, NormY: {1}", normX, normY);
	//CR_TRACE("m_Selection: {0}", (int)m_Selection);

	float sum = INT_MAX;
	CrossPoint closest = m_NodeMap.at(0);
	//CR_TRACE("Mouse x: {0}, Mouse y: {1}", position.first, position.second);
	for (auto& node : m_NodeMap)
	{
		float x = std::abs(normX - node.position.x);
		float y = std::abs(normY - node.position.y);
		if (x + y < sum)
		{
			sum = x + y;
			closest = node;
			//CR_TRACE("Closest x {0}, closest y {1}, Sum: {2}", closest.position.x, closest.position.y, sum);
		}
	}


	Structure structure;
	float vertNeighborMidpoint = closest.position.y + (closest.vertNeighbor.position.y - closest.position.y) / 2;
	float rightNeighborXMidpoint = closest.position.x + (closest.rightNeighbor.position.x - closest.position.x) / 2;
	float rightNeighborYMidpoint = closest.position.y - (closest.position.y - closest.rightNeighbor.position.y) / 2;
	float leftNeighborXMidpoint = closest.position.x - (closest.position.x - closest.leftNeighbor.position.x) / 2;
	float leftNeighborYMidpoint = closest.position.y - (closest.position.y - closest.leftNeighbor.position.y) / 2;
	if (m_Selection == StructureType::SETTLEMENT || m_Selection == StructureType::CITY)
	{
		if (normY > vertNeighborMidpoint && vertNeighborMidpoint > closest.position.y)
			structure.position = closest.vertNeighbor.position;
		else if (normX > rightNeighborXMidpoint && rightNeighborXMidpoint > closest.position.x)
			structure.position = closest.rightNeighbor.position;
		else if (normX < leftNeighborXMidpoint)
			structure.position = closest.leftNeighbor.position;
		else
			structure.position = closest.position;

		structure.buildType = m_Selection;
		structure.nearestCrossPoint = closest.position;
		/*if(m_Selection == StructureType::SETTLEMENT)
			m_Players.at(m_CurrentPlayer)->*/
		m_Players.at(m_CurrentPlayer)->AddStructure(structure);
	}
	else if (m_Selection == StructureType::ROAD)
	{
		//CR_TRACE("ITS A ROAD");
		if (normY > closest.position.y)
		{
			structure.position.x = closest.position.x;
			structure.position.y = vertNeighborMidpoint;
			structure.position.z = closest.position.z;
			structure.buildType = StructureType::ROAD_VERTICAL;
			//CR_TRACE("Road x: {0}, Road y: {1}", structure.position.x, structure.position.y);
			//CR_TRACE("ITS A VERTICAL ROAD");

		}
		else if (normX > closest.position.x)
		{
			structure.position.x = rightNeighborXMidpoint;
			structure.position.y = rightNeighborYMidpoint;
			structure.position.z = closest.position.z;
			structure.buildType = StructureType::ROAD_LEFT_UP;
			//CR_TRACE("ITS A LEFT UP ROAD");

		}
		else if (normX < closest.position.x)
		{
			structure.position.x = leftNeighborXMidpoint;
			structure.position.y = leftNeighborYMidpoint;
			structure.position.z = closest.position.z;
			structure.buildType = StructureType::ROAD_RIGHT_UP;
			//CR_TRACE("ITS A RIGHT UP ROAD");

		}
		structure.nearestCrossPoint = closest.position;
		m_Players.at(m_CurrentPlayer)->AddStructure(structure);
	}

	
	m_Selection = StructureType::NONE;
}

void GameLayer::HandleP1PlacementEvents(float normX, float normY, StructureType structure)
{
	// take money from the gamers
	int rec_amount[5];
	for (int i = 0; i < 5; i++) rec_amount[i] = m_Players.at(m_CurrentPlayer)->GetResources().at(i);

	// BRICK, SHEEP, STONE, WHEAT, WOOD

	switch (structure)
	{
	case StructureType::ROAD:

		if (rec_amount[0] > 0 && rec_amount[4] > 0) { // 0 -> brick . 4 -> wood
			CR_TRACE("PAID FOR ROAD");
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::BRICK, 1);
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::WOOD, 1);
			m_Selection = StructureType::ROAD;
		}
		break;
	case StructureType::CITY:

		if (rec_amount[3] > 1 && rec_amount[2] > 2) {
			CR_TRACE("PAID FOR CITY");
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::WHEAT, 2);
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::STONE, 3);
			m_Selection = StructureType::CITY;
			m_Players.at(m_CurrentPlayer)->IncrementScore(2);
		}
		break;
	case StructureType::SETTLEMENT:

		if (rec_amount[0] > 0 && rec_amount[3] > 0 && rec_amount[1] > 0 && rec_amount[4] > 0) {
			CR_TRACE("PAID FOR SETTLEMENT");
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::BRICK, 1);
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::WHEAT, 1);
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::SHEEP, 1);
			m_Players.at(m_CurrentPlayer)->RemoveResource(Resource::WOOD, 1);
			m_Selection = StructureType::SETTLEMENT;
			m_Players.at(m_CurrentPlayer)->IncrementScore(1);
		}
		break;
	}
}

void GameLayer::RollDiceEvent()
{
	// TESTING PURPOSES:
	/*
	m_Players.at(0)->AddResource(Resource::BRICK, 1);
	m_Players.at(0)->AddResource(Resource::SHEEP, 1);
	m_Players.at(0)->AddResource(Resource::STONE, 1);
	m_Players.at(0)->AddResource(Resource::WHEAT, 1);
	m_Players.at(0)->AddResource(Resource::WOOD, 1);

	m_Players.at(1)->AddResource(Resource::BRICK, 1);
	m_Players.at(1)->AddResource(Resource::SHEEP, 1);
	m_Players.at(1)->AddResource(Resource::STONE, 1);
	m_Players.at(1)->AddResource(Resource::WHEAT, 1);
	m_Players.at(1)->AddResource(Resource::WOOD, 1);
	*/

	srand(time(NULL));
	m_DiceRoll1 = rand() % 6;
	m_DiceRoll2 = rand() % 6;
	m_CurrentDiceRoll = m_DiceRoll1 + m_DiceRoll2 + 2;

	CR_TRACE("Current Dice Roll: {0} {1}", m_DiceRoll1, m_DiceRoll2);
	CR_TRACE("Current Total Dice Roll: {0}", m_CurrentDiceRoll);
}

void GameLayer::InitNodeMap(float xAnchor, float yAnchor)
{
	constexpr float z = 1.0f;
	constexpr float tileOffsetX = 2.1f;
	constexpr float tileOffsetY = 1.8f;
	const float edgeXOffset = tileOffsetX * 0.5f;
	const float vertYOffset = tileOffsetY * 0.66f;
	const float edgeYOffset = tileOffsetY * 0.33f;
	float currX = xAnchor + tileOffsetX;
	float currY = yAnchor - tileOffsetY;

	currY = yAnchor - tileOffsetY + vertYOffset;
	for (int i = 0; i < 3; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({currX, currY, z});
		currNode.leftNeighbor.position = glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		currNode.vertNeighbor.position = glm::vec3(-17.0f);
		currNode.rightNeighbor.position = glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		m_NodeMap.push_back(currNode);
	}

	currX = xAnchor + tileOffsetX / 2;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 4; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });
		currNode.leftNeighbor.position = glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		currNode.vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z }); 
		currNode.rightNeighbor.position = glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		m_NodeMap.push_back(currNode);
	}

	currX = xAnchor;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 5; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });
		currNode.leftNeighbor.position = glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		currNode.vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		currNode.rightNeighbor.position = glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		m_NodeMap.push_back(currNode);
	}

	currX = xAnchor - tileOffsetX / 2;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 6; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });
		currNode.leftNeighbor.position = (i == 0) ? glm::vec3(-17.0f) : glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		currNode.vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		currNode.rightNeighbor.position = (i == 5) ? glm::vec3(-17.0f) : glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		m_NodeMap.push_back(currNode);
	}

	currX = xAnchor;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 5; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });
		currNode.leftNeighbor.position = (i == 0) ? glm::vec3(-17.0f) : glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		currNode.vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		currNode.rightNeighbor.position = (i == 4) ? glm::vec3(-17.0f) : glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		m_NodeMap.push_back(currNode);
	}

	currX = xAnchor + tileOffsetX / 2;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 4; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });
		currNode.leftNeighbor.position = (i == 0) ? glm::vec3(-17.0f) : glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		currNode.vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		currNode.rightNeighbor.position = (i == 3) ? glm::vec3(-17.0f) : glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		m_NodeMap.push_back(currNode);
	}
	
	

}