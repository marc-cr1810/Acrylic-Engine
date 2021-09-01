#pragma once

#include "Acrylic/Core/Base.h"
#include "Acrylic/Scene/Entity.h"

namespace Acrylic
{
	class PropertiesPanel
	{
	public:
		PropertiesPanel() = default;

		void OnImGuiRender(const Entity& context);

		void Open() { m_Open = true; }
	private:
		void DrawComponents(Entity entity);
	private:
		bool m_Open = true;
	};
}
