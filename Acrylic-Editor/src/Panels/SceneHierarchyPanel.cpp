#include "SceneHierarchyPanel.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

#include "UIWidgets.h"

#include "Acrylic/Scene/Components.h"

namespace Acrylic
{
	SceneHierarchyPanel::SceneHierarchyPanel()
	{
		m_SceneIcon = Texture2D::Create("Resources/Icons/Panels/SceneHierachy/SceneIcon.png");
		m_GameObjectIcon = Texture2D::Create("Resources/Icons/Panels/SceneHierachy/GameObjectIcon.png");
	}

	SceneHierarchyPanel::SceneHierarchyPanel(const Ref<Scene>& context)
	{
		SetContext(context);
	}

	void SceneHierarchyPanel::SetContext(const Ref<Scene>& context)
	{
		m_Context = context;
		m_SelectionContext = {};
	}

	void SceneHierarchyPanel::OnImGuiRender()
	{
		if (m_Open)
		{
			ImGui::Begin("Scene Hierarchy", &m_Open);

			if (m_Context != nullptr)
			{
				ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
				if (m_Context->m_Registry.size() == 0)
					flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
				else
					flags |= ImGuiTreeNodeFlags_DefaultOpen;
				bool opened = UI::DrawTreeNodeWithImage((ImTextureID)m_SceneIcon->GetRendererID(), (void*)454655, flags, m_Context->m_Name.c_str());

				if (opened && m_Context->m_Registry.size() > 0)
				{
					m_Context->m_Registry.each([&](auto entityID)
						{
							Entity entity{ entityID , m_Context.get() };
							DrawEntityNode(entity);
						});

					ImGui::TreePop();
				}

				if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
					m_SelectionContext = {};

				// Right-click on blank space
				if (ImGui::BeginPopupContextWindow(0, 1, false))
				{
					if (ImGui::MenuItem("Create Empty Entity"))
						m_Context->CreateEntity("Empty Entity");

					ImGui::EndPopup();
				}
			}

			ImGui::End();
		}
	}

	void SceneHierarchyPanel::SetSelectedEntity(Entity entity)
	{
		m_SelectionContext = entity;
	}

	void SceneHierarchyPanel::DrawEntityNode(Entity entity)
	{
		auto& tag = entity.GetComponent<TagComponent>().Tag;

		ImGuiTreeNodeFlags node_flags = ((m_SelectionContext == entity) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
#ifndef HAS_CHILDREN
		node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
#endif
		bool opened = UI::DrawTreeNodeWithImage((ImTextureID)m_GameObjectIcon->GetRendererID(), (void*)(uint64_t)(uint32_t)entity, node_flags, tag.c_str());
		if (ImGui::IsItemClicked())
		{
			m_SelectionContext = entity;
		}

		bool entityDeleted = false;
		if (ImGui::BeginPopupContextItem())
		{
			if (ImGui::MenuItem("Delete Entity"))
				entityDeleted = true;

			ImGui::EndPopup();
		}

#ifdef HAS_CHILDREN
		if (opened)
		{
			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;;
			UI::DrawTreeNodeWithImage((ImTextureID)m_GameObjectIcon->GetRendererID(), (void*)9817239, flags, tag.c_str());
			ImGui::TreePop();
		}
#endif

		if (entityDeleted)
		{
			m_Context->DestroyEntity(entity);
			if (m_SelectionContext == entity)
				m_SelectionContext = {};
		}
	}
}
