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

		void OpenSceneHierarchy() { m_SceneHierarchyOpen = true; }
		void OpenProperties() { m_PropertiesOpen = true; }
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;

		bool m_SceneHierarchyOpen = true, m_PropertiesOpen = true;
	};
}
