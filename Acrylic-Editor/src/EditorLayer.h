#pragma once
#include "Acrylic.h"

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
		OrthographicCameraController m_CameraController;

		Ref<Texture2D> m_CheckerboardTexture;
		Ref<Texture2D> m_DuckTexture;

		Ref<Framebuffer> m_Framebuffer;

		glm::vec4 m_SquareColor = { 0.8f, 0.2f, 0.3f, 1.0f };
		float m_SquareRotation = 0.0f;

		uint32_t m_MapWidth, m_MapHeight;
		std::unordered_map<char, Ref<SubTexture2D>> m_TextureMap;
	};
}