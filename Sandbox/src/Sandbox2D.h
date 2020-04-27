#pragma once
#include "Acrylic.h"

#include "Benchmark.h"

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

	Benchmark m_Benchmark;
};