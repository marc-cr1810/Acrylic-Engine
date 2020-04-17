#pragma once
#include "Acrylic.h"

class Sandbox2D : public Acrylic::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Acrylic::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Acrylic::Event& e) override;
private:
	Acrylic::OrthographicCameraController m_CameraController;

	Acrylic::Ref<Acrylic::Texture2D> m_CheckerboardTexture;
	Acrylic::Ref<Acrylic::Texture2D> m_DuckTexture;

	glm::vec4 m_SquareColor = { 0.8f, 0.2f, 0.3f, 1.0f };
	float m_SquareRotation = 0.0f;

	uint32_t m_FPS = 0;
	uint32_t m_FPSTemp = 0;
	float m_TimePassed = 0.0f;
};