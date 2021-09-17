#pragma once

#include <entt.hpp>

#include "Acrylic/Core/UUID.h"
#include "Acrylic/Core/Timestep.h"
#include "Acrylic/Renderer/EditorCamera.h"

class b2World;

namespace Acrylic
{
	class Entity;

	class Scene
	{
	public:
		Scene(const std::string &name = "Untitled");
		~Scene();

		Entity CreateEntity(const std::string &name = std::string());
		void DestroyEntity(Entity entity);

		void OnRuntimeStart();
		void OnRuntimeStop();

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateEditor(Timestep ts, EditorCamera &camera);

		void Scene::OnViewportResize(uint32_t width, uint32_t height);

		Entity GetPrimaryCameraEntity();
		std::string GetName() { return m_Name; }
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T &component);
	private:
		UUID m_SceneID;
		std::string m_Name;

		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		entt::entity m_SceneEntity;

		b2World *m_Box2DWorld = nullptr;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};
}
