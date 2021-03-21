#pragma once

#include "Crumble/Core/Core.h"
#include "Crumble/Core/Timestep.h"
#include "Crumble/Events/Event.h"

namespace Crumble {

	class CRUMBLE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}