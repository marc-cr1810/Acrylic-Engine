#pragma once

#include "Acrylic/Core/Base.h"
#include "Acrylic/Scene/Scene.h"
#include "Acrylic/Scene/Entity.h"

namespace Acrylic
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();

		Entity GetSelectedEntity() const { return m_SelectionContext; }
		void SetSelectedEntity(Entity entity);

		void Open() { m_Open = true; }
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;

		bool m_Open = true;
	};
}
