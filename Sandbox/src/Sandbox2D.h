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

	// Temp
	Acrylic::Ref<Acrylic::VertexArray> m_SquareVA;
	Acrylic::Ref<Acrylic::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};