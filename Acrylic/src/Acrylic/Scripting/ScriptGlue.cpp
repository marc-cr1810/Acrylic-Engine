#include "acpch.h"
#include "ScriptGlue.h"
#include "ScriptEngine.h"

#include "Acrylic/Core/UUID.h"
#include "Acrylic/Core/KeyCodes.h"
#include "Acrylic/Core/Input.h"

#include "Acrylic/Scene/Scene.h"
#include "Acrylic/Scene/Entity.h"

#include "mono/metadata/object.h"
#include "mono/metadata/reflection.h"

#include "box2d/b2_body.h"

namespace Acrylic
{

	static std::unordered_map<MonoType*, std::function<bool(Entity)>> s_EntityHasComponentFuncs;
#define AC_ADD_INTERNAL_CALL(Name) mono_add_internal_call("Acrylic.InternalCalls::" #Name, Name)


#pragma region Entity

	static bool Entity_HasComponent(UUID entityID, MonoReflectionType* componentType)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		AC_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		AC_CORE_ASSERT(entity);

		MonoType* managedType = mono_reflection_type_get_type(componentType);
		AC_CORE_ASSERT(s_EntityHasComponentFuncs.find(managedType) != s_EntityHasComponentFuncs.end());
		return s_EntityHasComponentFuncs.at(managedType)(entity);
	}

#pragma endregion

#pragma region TransformComponent

	static void TransformComponent_GetTranslation(UUID entityID, glm::vec3* outTranslation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		AC_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		AC_CORE_ASSERT(entity);

		*outTranslation = entity.GetComponent<TransformComponent>().Translation;
	}

	static void TransformComponent_SetTranslation(UUID entityID, glm::vec3* translation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		AC_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		AC_CORE_ASSERT(entity);

		entity.GetComponent<TransformComponent>().Translation = *translation;
	}

#pragma endregion

#pragma region Rigidbody2DComponent

	static void Rigidbody2DComponent_ApplyLinearImpulse(UUID entityID, glm::vec2* impulse, glm::vec2* point, bool wake)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		AC_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		AC_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->ApplyLinearImpulse(b2Vec2(impulse->x, impulse->y), b2Vec2(point->x, point->y), wake);
	}

	static void Rigidbody2DComponent_ApplyLinearImpulseToCenter(UUID entityID, glm::vec2* impulse, bool wake)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		AC_CORE_ASSERT(scene);
		Entity entity = scene->GetEntityByUUID(entityID);
		AC_CORE_ASSERT(entity);

		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		b2Body* body = (b2Body*)rb2d.RuntimeBody;
		body->ApplyLinearImpulseToCenter(b2Vec2(impulse->x, impulse->y), wake);
	}

#pragma endregion

#pragma region Input

	static bool Input_IsKeyDown(KeyCode keycode)
	{
		return Input::IsKeyPressed(keycode);
	}

#pragma endregion

	template<typename... Component>
	static void RegisterComponent()
	{
		([]()
			{
				std::string_view typeName = typeid(Component).name();
				size_t pos = typeName.find_last_of(':');
				std::string_view structName = typeName.substr(pos + 1);
				std::string managedTypename = fmt::format("Acrylic.{}", structName);

				MonoType* managedType = mono_reflection_type_from_name(managedTypename.data(), ScriptEngine::GetCoreAssemblyImage());
				if (!managedType)
				{
					AC_CORE_ERROR("Could not find component type {}", managedTypename);
					return;
				}
				s_EntityHasComponentFuncs[managedType] = [](Entity entity) { return entity.HasComponent<Component>(); };
			}(), ...);
	}

	template<typename... Component>
	static void RegisterComponent(ComponentGroup<Component...>)
	{
		RegisterComponent<Component...>();
	}

	void ScriptGlue::RegisterComponents()
	{
		RegisterComponent(AllComponents{});
	}

	void ScriptGlue::RegisterFunctions()
	{
		AC_ADD_INTERNAL_CALL(Entity_HasComponent);

		AC_ADD_INTERNAL_CALL(TransformComponent_GetTranslation);
		AC_ADD_INTERNAL_CALL(TransformComponent_SetTranslation);

		AC_ADD_INTERNAL_CALL(Rigidbody2DComponent_ApplyLinearImpulse);
		AC_ADD_INTERNAL_CALL(Rigidbody2DComponent_ApplyLinearImpulseToCenter);

		AC_ADD_INTERNAL_CALL(Input_IsKeyDown);
	}
}
