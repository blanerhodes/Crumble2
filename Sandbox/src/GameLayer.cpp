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
	m_Player1 = CreateRef<Player>("Player1");
	m_Player2 = CreateRef<Player>("Player2");

	Random::Init();
	InitNodeMap(-6.0f, 6.5f);
	CR_TRACE("NodeMap size: {0}", m_NodeMap.size());
}

void GameLayer::OnAttach()
{
	m_TileMap.Init();

	ImGuiIO io = ImGui::GetIO();
	//m_Font = io.Fonts->AddFontFromFileTTF("assets/OpenSans-Regular.ttf", 120.0f);
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(Timestep ts)
{
	m_TileMap.OnUpdate(ts);
	RenderCommand::SetClearColor({ 0.0f, 0.0f, 0.0f, 1 });
	RenderCommand::Clear();
	Renderer2D::BeginScene(*m_Camera);
	m_TileMap.OnRender(m_NodeMap);
	Renderer2D::EndScene();
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
	float aspectRatio = (float)width / (float)height;

	float camWidth = 8.0f;
	float bottom = -camWidth;
	float top = camWidth;
	float left = bottom * aspectRatio;
	float right = top * aspectRatio;
	m_Camera = CreateScope<OrthographicCamera>(left, right, bottom, top);
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
		
		CrossPoint leftNeighbor;
		leftNeighbor.position = glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		CrossPoint vertNeighbor;
		vertNeighbor.position = glm::vec3(-17.0f);
		CrossPoint rightNeighbor;
		rightNeighbor.position = glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		std::vector<CrossPoint> currNodeNeighbors;
		currNodeNeighbors.push_back(currNode);
		currNodeNeighbors.push_back(leftNeighbor);
		currNodeNeighbors.push_back(vertNeighbor);
		currNodeNeighbors.push_back(rightNeighbor);
		m_NodeMap.push_back(currNodeNeighbors);
	}

	currX = xAnchor + tileOffsetX / 2;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 4; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });

		CrossPoint leftNeighbor;
		leftNeighbor.position = glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		CrossPoint vertNeighbor;
		vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z }); 
		CrossPoint rightNeighbor;
		rightNeighbor.position = glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		std::vector<CrossPoint> currNodeNeighbors;
		currNodeNeighbors.push_back(currNode);
		currNodeNeighbors.push_back(leftNeighbor);
		currNodeNeighbors.push_back(vertNeighbor);
		currNodeNeighbors.push_back(rightNeighbor);
		m_NodeMap.push_back(currNodeNeighbors);
	}

	currX = xAnchor;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 5; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });

		CrossPoint leftNeighbor;
		leftNeighbor.position = glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		CrossPoint vertNeighbor;
		vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		CrossPoint rightNeighbor;
		rightNeighbor.position = glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		std::vector<CrossPoint> currNodeNeighbors;
		currNodeNeighbors.push_back(currNode);
		currNodeNeighbors.push_back(leftNeighbor);
		currNodeNeighbors.push_back(vertNeighbor);
		currNodeNeighbors.push_back(rightNeighbor);
		m_NodeMap.push_back(currNodeNeighbors);
	}

	currX = xAnchor - tileOffsetX / 2;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 6; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });

		CrossPoint leftNeighbor;
		leftNeighbor.position = (i == 0) ? glm::vec3(-17.0f) : glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		CrossPoint vertNeighbor;
		vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		CrossPoint rightNeighbor;
		rightNeighbor.position = (i == 5) ? glm::vec3(-17.0f) : glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		std::vector<CrossPoint> currNodeNeighbors;
		currNodeNeighbors.push_back(currNode);
		currNodeNeighbors.push_back(leftNeighbor);
		currNodeNeighbors.push_back(vertNeighbor);
		currNodeNeighbors.push_back(rightNeighbor);
		m_NodeMap.push_back(currNodeNeighbors);
	}

	currX = xAnchor;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 5; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });

		CrossPoint leftNeighbor;
		leftNeighbor.position = (i == 0) ? glm::vec3(-17.0f) : glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		CrossPoint vertNeighbor;
		vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		CrossPoint rightNeighbor;
		rightNeighbor.position = (i == 4) ? glm::vec3(-17.0f) : glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		std::vector<CrossPoint> currNodeNeighbors;
		currNodeNeighbors.push_back(currNode);
		currNodeNeighbors.push_back(leftNeighbor);
		currNodeNeighbors.push_back(vertNeighbor);
		currNodeNeighbors.push_back(rightNeighbor);
		m_NodeMap.push_back(currNodeNeighbors);
	}

	currX = xAnchor + tileOffsetX / 2;
	currY -= vertYOffset + edgeYOffset;
	for (int i = 0; i < 4; i++)
	{
		currX += tileOffsetX;
		CrossPoint currNode;
		currNode.position = glm::vec3({ currX, currY, z });

		CrossPoint leftNeighbor;
		leftNeighbor.position = (i == 0) ? glm::vec3(-17.0f) : glm::vec3({ currX - edgeXOffset, currY - edgeYOffset, z });
		CrossPoint vertNeighbor;
		vertNeighbor.position = glm::vec3({ currX, currY + vertYOffset, z });
		CrossPoint rightNeighbor;
		rightNeighbor.position = (i == 3) ? glm::vec3(-17.0f) : glm::vec3({ currX + edgeXOffset, currY - edgeYOffset, z });
		std::vector<CrossPoint> currNodeNeighbors;
		currNodeNeighbors.push_back(currNode);
		currNodeNeighbors.push_back(leftNeighbor);
		currNodeNeighbors.push_back(vertNeighbor);
		currNodeNeighbors.push_back(rightNeighbor);
		m_NodeMap.push_back(currNodeNeighbors);
	}
}