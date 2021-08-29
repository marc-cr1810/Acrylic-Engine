#pragma once

#include "Acrylic.h"
#include "Panels/SceneHierarchyPanel.h"

#include "Acrylic/Renderer/EditorCamera.h"

namespace Acrylic
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		bool OnKeyPressed(KeyPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
	private:
		OrthographicCameraController m_CameraController;
		EditorCamera m_EditorCamera;

		Ref<Framebuffer> m_Framebuffer;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

		int m_GizmoType = -1;

		Ref<Scene> m_ActiveScene;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;

		// Temp
		Ref<Texture2D> m_CheckerboardTexture;
		Ref<Texture2D> m_DuckTexture;

		Entity m_CameraEntity;
		Entity m_SecondCamera;
		bool m_PrimaryCamera = true;

		glm::vec4 m_SquareColor = { 0.8f, 0.2f, 0.3f, 1.0f };
		float m_SquareRotation = 0.0f;
	};
}
