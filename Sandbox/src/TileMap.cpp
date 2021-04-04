#include "TileMap.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <random>

using namespace Crumble;

struct TileValuePair
{
	Ref<Texture2D> tile;
	Ref<Texture2D> value;
};

TileMap::TileMap()
	: Layer("TileMap"), m_CameraController(1280.0f / 720.0f)
{
	auto& window = Crumble::Application::Get().GetWindow();
	CreateCamera(window.GetWidth(), window.GetHeight());

}

void TileMap::OnAttach()
{
	m_Checkerboard = Crumble::Texture2D::Create("assets/textures/Checkerboard.png");

	m_BrickTile = Crumble::Texture2D::Create("assets/textures/BrickTile.png");
	m_SandTile = Crumble::Texture2D::Create("assets/textures/SandTile.png");
	m_SheepTile = Crumble::Texture2D::Create("assets/textures/SheepTile.png");
	m_StoneTile = Crumble::Texture2D::Create("assets/textures/StoneTile.png");
	m_WaterTile = Crumble::Texture2D::Create("assets/textures/WaterTile.png");
	m_WheatTile = Crumble::Texture2D::Create("assets/textures/WheatTile.png");
	m_WoodTile = Crumble::Texture2D::Create("assets/textures/WoodTile.png");

	for (int i = 0; i < 4; i++)
	{
		m_Tiles.push_back(m_WoodTile);
		m_Tiles.push_back(m_WheatTile);
		m_Tiles.push_back(m_SheepTile);
	}
	for (int i = 0; i < 3; i++)
	{
		m_Tiles.push_back(m_BrickTile);
		m_Tiles.push_back(m_StoneTile);
	}
	m_Tiles.push_back(m_SandTile);

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_Tiles.begin(), m_Tiles.end(), std::default_random_engine(seed));
}

void TileMap::OnDetach()
{
}

void TileMap::OnUpdate(Crumble::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Crumble::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Crumble::RenderCommand::Clear();

	Crumble::Renderer2D::BeginScene(m_CameraController.GetCamera());
	/*Crumble::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2, 0.3f, 1.0f });
	Crumble::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2, 0.3f, 1.0f });
	Crumble::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });*/

	glm::vec2 standardSize = glm::vec2(1.0f);
	float currX = 0;
	float currY = 0;
	float currZ = 0;
	int row = 1;
	int i = 0;
	for (; i < 3; i++)
	{
		Crumble::Renderer2D::DrawQuad({ currX, currY, currZ }, standardSize, m_Tiles.at(i));
		currZ += 0.01;
		currX += 0.7;
	}

	currX = 0 - 0.35;
	currY = -0.6f;
	for (; i < 7; i++)
	{
		Crumble::Renderer2D::DrawQuad({ currX, currY, currZ }, standardSize, m_Tiles.at(i));
		currZ += 0.01;
		currX += 0.7;
	}

	currX = 0 - 0.35 * 2;
	currY = -0.6f * 2;
	for (; i < 12; i++)
	{
		Crumble::Renderer2D::DrawQuad({ currX, currY, currZ }, standardSize, m_Tiles.at(i));
		currZ += 0.01;
		currX += 0.7;
	}

	currX = 0 - 0.35;
	currY = -0.6f * 3;
	for (; i < 16; i++)
	{
		Crumble::Renderer2D::DrawQuad({ currX, currY, currZ }, standardSize, m_Tiles.at(i));
		currZ += 0.01;
		currX += 0.7;
	}

	currX = 0;
	currY = -0.6f * 4;
	for (; i < m_Tiles.size(); i++)
	{
		Crumble::Renderer2D::DrawQuad({ currX, currY, currZ }, standardSize, m_Tiles.at(i));
		currZ += 0.01;
		currX += 0.7;
	}


	/*Crumble::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, m_StoneTile);
	Crumble::Renderer2D::DrawQuad({ 0.7f, 0.0f, 0.1f}, { 1.0f, 1.0f }, m_WoodTile);
	Crumble::Renderer2D::DrawQuad({ 0.35f, 0.6f, 0.2f }, { 1.0f, 1.0f }, m_SheepTile);*/

	Crumble::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, glm::radians(45.0f), m_Checkerboard, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));

	Crumble::Renderer2D::EndScene();

}

void TileMap::OnImGuiRender()
{
	ImGui::Begin("Settings");
	//ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void TileMap::OnEvent(Crumble::Event& e)
{
	m_CameraController.OnEvent(e);
}

bool TileMap::OnWindowResize(Crumble::WindowResizeEvent& e)
{
	CreateCamera(e.GetWidth(), e.GetHeight());
	return false;
}

void TileMap::CreateCamera(uint32_t width, uint32_t height)
{
	float aspectRatio = (float)width / (float)height;

	float camWidth = 8.0f;
	float bottom = -camWidth;
	float top = camWidth;
	float left = bottom * aspectRatio;
	float right = top * aspectRatio;
	m_Camera = Crumble::CreateScope<Crumble::OrthographicCamera>(left, right, bottom, top);
}