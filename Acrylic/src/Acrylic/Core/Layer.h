#pragma once

#include "Acrylic/Core/Core.h"
#include "Acrylic/Events/Event.h"

namespace Acrylic {

	class ACRYLIC_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate() { }
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) { }

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};

}