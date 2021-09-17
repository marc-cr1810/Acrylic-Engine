#pragma once

#include <entt.hpp>

#include "Acrylic/Core/Timestep.h"
#include "Acrylic/Renderer/EditorCamera.h"

namespace Acrylic
{
	class Entity;

	class Scene
	{
	public:
		Scene(const std::string& name = "Untitled");
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		void DestroyEntity(Entity entity);

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateEditor(Timestep ts, EditorCamera& camera);

		void Scene::OnViewportResize(uint32_t width, uint32_t height);

		Entity GetPrimaryCameraEntity();
		std::string GetName() { return m_Name; }
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);
	private:
		std::string m_Name;

		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};
}
