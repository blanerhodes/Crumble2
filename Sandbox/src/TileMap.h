#pragma once

#include "Crumble.h"

class TileMap : public Crumble::Layer
{
public:
	TileMap();
	virtual ~TileMap() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(Crumble::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Crumble::Event& event) override;

	bool OnWindowResize(Crumble::WindowResizeEvent& e);
	bool OnMouseButtonPressed(Crumble::MouseButtonPressedEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
private:
	Crumble::OrthographicCameraController m_CameraController;
	Crumble::Scope<Crumble::OrthographicCamera> m_Camera;
	//ImFont* m_Font;

	Crumble::Ref<Crumble::VertexArray> m_SquareVA;
	Crumble::Ref<Crumble::Texture2D> m_BrickTile;
	Crumble::Ref<Crumble::Texture2D> m_SandTile;
	Crumble::Ref<Crumble::Texture2D> m_SheepTile;
	Crumble::Ref<Crumble::Texture2D> m_StoneTile;
	Crumble::Ref<Crumble::Texture2D> m_WaterTile;
	Crumble::Ref<Crumble::Texture2D> m_WheatTile;
	Crumble::Ref<Crumble::Texture2D> m_WoodTile;
	Crumble::Ref<Crumble::Shader> m_FlatColorShader;

	Crumble::Ref<Crumble::Texture2D> m_Checkerboard;
	std::vector<Crumble::Ref<Crumble::Texture2D>> m_Tiles;

};

