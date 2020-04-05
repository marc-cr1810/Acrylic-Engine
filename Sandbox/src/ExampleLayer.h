#pragma once

#include "Acrylic.h"

class ExampleLayer : public Acrylic::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Acrylic::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Acrylic::Event& e) override;
private:
	Acrylic::ShaderLibrary m_ShaderLibrary;
	Acrylic::Ref<Acrylic::Shader> m_Shader;
	Acrylic::Ref<Acrylic::VertexArray> m_VertexArray;

	Acrylic::Ref<Acrylic::Shader> m_FlatColorShader;
	Acrylic::Ref<Acrylic::VertexArray> m_SquareVA;

	Acrylic::Ref<Acrylic::Texture2D> m_Texture, m_DuckTexture;

	Acrylic::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};