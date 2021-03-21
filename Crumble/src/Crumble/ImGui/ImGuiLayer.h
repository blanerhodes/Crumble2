#pragma once

#include "Crumble/Core/Layer.h"

#include "Crumble/Events/ApplicationEvent.h"
#include "Crumble/Events/KeyEvent.h"
#include "Crumble/Events/MouseEvent.h"

namespace Crumble {

	class CRUMBLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}