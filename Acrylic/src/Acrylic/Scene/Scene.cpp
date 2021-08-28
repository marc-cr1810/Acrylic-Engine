#include "acpch.h"
#include "Acrylic/Scene/Scene.h"

#include "Acrylic/Scene/Entity.h"
#include "Acrylic/Scene/Components.h"
#include "Acrylic/Renderer/Renderer2D.h"

#include <glm/glm.hpp>

namespace Acrylic
{
	static void DoMath(const glm::mat4& transform)
	{

	}

	static void OnTransformConstruct(entt::registry& registry, entt::entity entity)
	{

	}

	Scene::Scene()
	{
#if ENTT_EXAMPLE_CODE
		entt::entity entity = m_Registry.create();
		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));

		m_Registry.on_construct<TransformComponent>().connect<&OnTransformConstruct>();

		if (m_Registry.all_of<TransformComponent>(entity))
			TransformComponent& transform = m_Registry.get<TransformComponent>(entity);

		auto view = m_Registry.view<TransformComponent>();
		for (auto e : view)
		{
			TransformComponent& transform = view.get<TransformComponent>(e);
		}

		auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
		for (auto e : group)
		{
			auto&[transform, mesh] = group.get<TransformComponent, MeshComponent>(e);
		}
#endif
	}

	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto e : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(e);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}
}