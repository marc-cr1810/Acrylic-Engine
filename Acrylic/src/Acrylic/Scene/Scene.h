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

		static Ref<Scene> Copy(Ref<Scene> other);

		Entity CreateEntity(const std::string &name = std::string());
		Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
		void DestroyEntity(Entity entity);

		void OnRuntimeStart();
		void OnRuntimeStop();

		void OnSimulationStart();
		void OnSimulationStop();

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateSimulation(Timestep ts, EditorCamera& camera);
		void OnUpdateEditor(Timestep ts, EditorCamera &camera);

		void Scene::OnViewportResize(uint32_t width, uint32_t height);

		void DuplicateEntity(Entity entity);

		Entity GetEntityByTag(std::string_view name);
		Entity GetEntityByUUID(UUID uuid);

		Entity GetPrimaryCameraEntity();

		bool IsRunning() const { return m_Running; }

		template<typename... Components>
		auto GetAllEntitiesWith()
		{
			return m_Registry.view<Components...>();
		}

		std::string GetName() { return m_Name; }
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T &component);

		void OnPhysics2DStart();
		void OnPhysics2DStop();

		void RenderScene(EditorCamera& camera);
	private:
		UUID m_SceneID;
		std::string m_Name;

		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
		bool m_Running = false;

		entt::entity m_SceneEntity;

		b2World *m_Box2DWorld = nullptr;

		std::unordered_map<UUID, entt::entity> m_EntityMap;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};
}
