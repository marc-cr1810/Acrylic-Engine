#include "PropertiesPanel.h"
#include "UIWidgets.h"

#include "Acrylic/Scripting/ScriptEngine.h"
#include "Acrylic/Scene/Components.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include <glm/gtc/type_ptr.hpp>

namespace Acrylic
{
	extern const std::filesystem::path g_AssetPath;

	PropertiesPanel::PropertiesPanel()
	{
		m_TransformIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/TransformIcon.png");
		m_SpriteRendererIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/SpriteRendererIcon.png");
		m_CircleRendererIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/CircleRendererIcon.png");
		m_CameraIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/CameraIcon.png");
		m_Rigidbody2DIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/Rigidbody2DIcon.png");
		m_BoxCollider2DIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/BoxCollider2DIcon.png");
		m_CircleCollider2DIcon = Texture2D::Create("Resources/Icons/Panels/Properties/Components/CircleCollider2DIcon.png");
	}

	void PropertiesPanel::OnImGuiRender(const Entity& context)
	{
		if (m_Open)
		{
			ImGui::Begin("Properties", &m_Open);
			if (context)
			{
				DrawComponents(context);
			}

			ImGui::End();
		}
	}

	template<typename T, typename UIFunction>
	static void DrawComponent(const std::string& name, Entity entity, ImTextureID texture, UIFunction uiFunction)
	{
		const ImGuiTreeNodeFlags treeNodeFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_AllowItemOverlap | ImGuiTreeNodeFlags_FramePadding;
		if (entity.HasComponent<T>())
		{
			auto& component = entity.GetComponent<T>();
			ImVec2 contentRegionAvailable = ImGui::GetContentRegionAvail();

			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 4, 4 });
			float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
			ImGui::Separator();
			bool open = UI::DrawTreeNodeWithImage(texture, (void*)typeid(T).hash_code(), treeNodeFlags, name.c_str());
			ImGui::PopStyleVar();
			ImGui::SameLine(contentRegionAvailable.x - lineHeight * 0.5f);
			if (ImGui::Button("+", ImVec2{ lineHeight, lineHeight }))
			{
				ImGui::OpenPopup("ComponentSettings");
			}

			bool removeComponent = false;
			if (ImGui::BeginPopup("ComponentSettings"))
			{
				if (ImGui::MenuItem("Remove component"))
					removeComponent = true;

				ImGui::EndPopup();
			}

			if (open)
			{
				uiFunction(component);
				ImGui::TreePop();
			}

			if (removeComponent)
				entity.RemoveComponent<T>();
		}
	}

	template<typename T>
	void PropertiesPanel::DisplayAddComponentEntry(Entity entity, const std::string& entryName) {
		if (!entity.HasComponent<T>())
		{
			if (ImGui::MenuItem(entryName.c_str()))
			{
				entity.AddComponent<T>();
				ImGui::CloseCurrentPopup();
			}
		}
	}

	void PropertiesPanel::DrawComponents(Entity entity)
	{
		if (entity.HasComponent<TagComponent>())
		{
			auto& tag = entity.GetComponent<TagComponent>().Tag;

			char buffer[256];
			memset(buffer, 0, sizeof(buffer));
			strcpy_s(buffer, sizeof(buffer), tag.c_str());
			if (ImGui::InputText("##Tag", buffer, sizeof(buffer)))
			{
				tag = std::string(buffer);
			}
		}

		ImGui::SameLine();
		ImGui::PushItemWidth(-1);

		if (ImGui::Button("Add Component"))
			ImGui::OpenPopup("AddComponent");

		if (ImGui::BeginPopup("AddComponent"))
		{
			DisplayAddComponentEntry<CameraComponent>(entity, "Camera");
			DisplayAddComponentEntry<SpriteRendererComponent>(entity, "Sprite Renderer");
			DisplayAddComponentEntry<CircleRendererComponent>(entity, "Circle Renderer");
			DisplayAddComponentEntry<ScriptComponent>(entity, "Script");
			DisplayAddComponentEntry<Rigidbody2DComponent>(entity, "Rigidbody 2D");
			DisplayAddComponentEntry<BoxCollider2DComponent>(entity, "Box Collider 2D");
			DisplayAddComponentEntry<CircleCollider2DComponent>(entity, "Circle Collider 2D");

			ImGui::EndPopup();
		}

		ImGui::PopItemWidth();

		DrawComponent<TransformComponent>("Transform", entity, (ImTextureID)m_TransformIcon->GetRendererID(), [](auto& component)
			{
				UI::DrawVec3Control("Translation", component.Translation);
				glm::vec3 rotation = glm::degrees(component.Rotation);
				UI::DrawVec3Control("Rotation", rotation);
				component.Rotation = glm::radians(rotation);
				UI::DrawVec3Control("Scale", component.Scale, 1.0f);
			});

		DrawComponent<SpriteRendererComponent>("Sprite Renderer", entity, (ImTextureID)m_SpriteRendererIcon->GetRendererID(), [](auto& component)
			{
				ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));

				ImGui::Button("Texture", ImVec2(100.0f, 0.0f));
				if (ImGui::BeginDragDropTarget())
				{
					if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("CONTENT_BROWSER_ITEM"))
					{
						const wchar_t* path = (const wchar_t*)payload->Data;
						std::filesystem::path texturePath = std::filesystem::path(g_AssetPath) / path;
						Ref<Texture2D> texture = Texture2D::Create(texturePath.string());
						if (texture->IsLoaded())
							component.Texture = texture;
						else
							AC_WARN("Could not load texture {0}", texturePath.filename().string());
					}
					ImGui::EndDragDropTarget();
				}

				ImGui::DragFloat("Tiling Factor", &component.TilingFactor, 0.1f, 0.0f, 100.0f);
			});

		DrawComponent<CircleRendererComponent>("Circle Renderer", entity, (ImTextureID)m_CircleRendererIcon->GetRendererID(), [](auto& component)
			{
				ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));
				ImGui::DragFloat("Thickness", &component.Thickness, 0.025f, 0.0f, 1.0f);
				ImGui::DragFloat("Fade", &component.Fade, 0.00025f, 0.0f, 1.0f);
			});

		DrawComponent<CameraComponent>("Camera", entity, (ImTextureID)m_CameraIcon->GetRendererID(), [](auto& component)
			{
				auto& camera = component.Camera;

				ImGui::Checkbox("Primary", &component.Primary);

				const char* projectionTypeStrings[] = { "Perspective", "Orthographic" };
				const char* currentProjectionTypeString = projectionTypeStrings[(int)camera.GetProjectionType()];
				if (ImGui::BeginCombo("Projection", currentProjectionTypeString))
				{
					for (int i = 0; i < 2; i++)
					{
						bool isSelected = currentProjectionTypeString == projectionTypeStrings[i];
						if (ImGui::Selectable(projectionTypeStrings[i], isSelected))
						{
							currentProjectionTypeString = projectionTypeStrings[i];
							camera.SetProjectionType((SceneCamera::ProjectionType)i);
						}

						if (isSelected)
							ImGui::SetItemDefaultFocus();
					}

					ImGui::EndCombo();
				}

				if (camera.GetProjectionType() == SceneCamera::ProjectionType::Perspective)
				{
					float perspectiveVerticalFov = glm::degrees(camera.GetPerspectiveVerticalFOV());
					if (ImGui::DragFloat("Vertical FOV", &perspectiveVerticalFov))
						camera.SetPerspectiveVerticalFOV(glm::radians(perspectiveVerticalFov));

					float perspectiveNear = camera.GetPerspectiveNearClip();
					if (ImGui::DragFloat("Near", &perspectiveNear))
						camera.SetPerspectiveNearClip(perspectiveNear);

					float perspectiveFar = camera.GetPerspectiveFarClip();
					if (ImGui::DragFloat("Far", &perspectiveFar))
						camera.SetPerspectiveFarClip(perspectiveFar);
				}

				if (camera.GetProjectionType() == SceneCamera::ProjectionType::Orthographic)
				{
					float orthoSize = camera.GetOrthographicSize();
					if (ImGui::DragFloat("Size", &orthoSize))
						camera.SetOrthographicSize(orthoSize);

					float orthoNear = camera.GetOrthographicNearClip();
					if (ImGui::DragFloat("Near", &orthoNear))
						camera.SetOrthographicNearClip(orthoNear);

					float orthoFar = camera.GetOrthographicFarClip();
					if (ImGui::DragFloat("Far", &orthoFar))
						camera.SetOrthographicFarClip(orthoFar);

					ImGui::Checkbox("Fixed Aspect Ratio", &component.FixedAspectRatio);
				}
			});

		DrawComponent<ScriptComponent>("Script", entity, (ImTextureID)m_SpriteRendererIcon->GetRendererID(), [entity](auto& component) mutable
			{
				bool scriptClassExists = ScriptEngine::EntityClassExists(component.ClassName);

				static char buffer[64];
				strcpy(buffer, component.ClassName.c_str());

				if (!scriptClassExists)
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.9f, 0.2f, 0.3f, 1.0f));

				if (ImGui::InputText("Class", buffer, sizeof(buffer)))
					component.ClassName = buffer;

				// Fields
				Ref<ScriptInstance> scriptInstance = ScriptEngine::GetEntityScriptInstance(entity.GetUUID());
				if (scriptInstance)
				{
					const auto& fields = scriptInstance->GetScriptClass()->GetFields();

					for (const auto& [name, field] : fields)
					{
						if (field.Type == ScriptFieldType::Float || field.Type == ScriptFieldType::Double)
						{
							float data = scriptInstance->GetFieldValue<float>(name);
							if (ImGui::DragFloat(name.c_str(), &data))
							{
								scriptInstance->SetFieldValue(name, data);
							}
						}
						else if (field.Type == ScriptFieldType::Vector2)
						{
							glm::vec2 vec2 = scriptInstance->GetFieldValue<glm::vec2>(name);
							if (UI::DrawVec2Control(name, vec2, 0.0f))
							{
								scriptInstance->SetFieldValue(name, vec2);
							}
						}
						else if (field.Type == ScriptFieldType::Vector3)
						{
							glm::vec3 vec3 = scriptInstance->GetFieldValue<glm::vec3>(name);
							if (UI::DrawVec3Control(name, vec3))
							{
								scriptInstance->SetFieldValue(name, vec3);
							}
						}
						else if (field.Type == ScriptFieldType::Vector4)
						{
							glm::vec4 vec4 = scriptInstance->GetFieldValue<glm::vec4>(name);
							if (UI::DrawVec4Control(name, vec4))
							{
								scriptInstance->SetFieldValue(name, vec4);
							}
						}
					}
				}

				if (!scriptClassExists)
					ImGui::PopStyleColor();
			});


		DrawComponent<Rigidbody2DComponent>("Rigidbody 2D", entity, (ImTextureID)m_Rigidbody2DIcon->GetRendererID(), [](auto &rb2dComponent)
			{
				const char *bodyTypeStrings[] = { "Static", "Dynamic", "Kinematic" };
				const char *currentBodyTypeString = bodyTypeStrings[(int)rb2dComponent.Type];
				if (ImGui::BeginCombo("Type", currentBodyTypeString))
				{
					for (int i = 0; i < 3; i++)
					{
						bool isSelected = currentBodyTypeString == bodyTypeStrings[i];
						if (ImGui::Selectable(bodyTypeStrings[i], isSelected))
						{
							currentBodyTypeString = bodyTypeStrings[i];
							rb2dComponent.Type = (Rigidbody2DComponent::BodyType)i;
						}

						if (isSelected)
							ImGui::SetItemDefaultFocus();
					}

					ImGui::EndCombo();
				}

				ImGui::Checkbox("Fixed Rotation", &rb2dComponent.FixedRotation);
			});

		DrawComponent<BoxCollider2DComponent>("Box Collider 2D", entity, (ImTextureID)m_BoxCollider2DIcon->GetRendererID(), [](auto &bc2dComponent)
			{
				ImGui::DragFloat2("Offset", glm::value_ptr(bc2dComponent.Offset));
				ImGui::DragFloat2("Size", glm::value_ptr(bc2dComponent.Size));
				ImGui::DragFloat("Density", &bc2dComponent.Density, 0.01f, 0.0f, 1.0f);
				ImGui::DragFloat("Friction", &bc2dComponent.Friction, 0.01f, 0.0f, 1.0f);
				ImGui::DragFloat("Restitution", &bc2dComponent.Restitution, 0.01f, 0.0f, 1.0f);
				ImGui::DragFloat("RestitutionThreshold", &bc2dComponent.RestitutionThreshold, 0.01f, 0.0f);
			});

		DrawComponent<CircleCollider2DComponent>("Circle Collider 2D", entity, (ImTextureID)m_CircleCollider2DIcon->GetRendererID(), [](auto& bc2dComponent)
			{
				ImGui::DragFloat2("Offset", glm::value_ptr(bc2dComponent.Offset));
				ImGui::DragFloat("Radius", &bc2dComponent.Radius);
				ImGui::DragFloat("Density", &bc2dComponent.Density, 0.01f, 0.0f, 1.0f);
				ImGui::DragFloat("Friction", &bc2dComponent.Friction, 0.01f, 0.0f, 1.0f);
				ImGui::DragFloat("Restitution", &bc2dComponent.Restitution, 0.01f, 0.0f, 1.0f);
				ImGui::DragFloat("Restitution Threshold", &bc2dComponent.RestitutionThreshold, 0.01f, 0.0f);
			});
	}
}
