#include "acpch.h"
#include "Acrylic/Scene/Entity.h"

namespace Acrylic
{
	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}
}