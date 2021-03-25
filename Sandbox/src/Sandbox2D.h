#pragma once

#include "Crumble.h"

class Sandbox2D : public Crumble::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	void OnUpdate(Crumble::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Crumble::Event& e) override;
		
private:
	Crumble::OrthographicCameraController m_CameraController;
	Crumble::Ref<Crumble::VertexArray> m_SquareVA;
	Crumble::Ref<Crumble::Texture2D> m_Checkerboard;
	Crumble::Ref<Crumble::Shader> m_FlatColorShader;
	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};