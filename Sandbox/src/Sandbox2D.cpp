#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_Checkerboard = Crumble::Texture2D::Create("assets/textures/Checkerboard.png");

}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Crumble::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Crumble::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Crumble::RenderCommand::Clear();

	Crumble::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Crumble::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, {0.8f, 0.2, 0.3f, 1.0f });
	Crumble::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2, 0.3f, 1.0f });
	Crumble::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Crumble::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, glm::radians(45.0f), m_Checkerboard, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));

	Crumble::Renderer2D::EndScene();

}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Crumble::Event& e)
{
	m_CameraController.OnEvent(e);
}