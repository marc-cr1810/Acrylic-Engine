#include "Sandbox2D.h"

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{
	AC_PROFILE_FUNCTION();

	m_CheckerboardTexture = Acrylic::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	AC_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Acrylic::Timestep ts)
{
	AC_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		AC_PROFILE_SCOPE("Renderer Prep");
		Acrylic::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Acrylic::RenderCommand::Clear();
	}

	{
		AC_PROFILE_SCOPE("Renderer Draw");
		Acrylic::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Acrylic::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(m_SquareRotation), m_SquareColor);
		Acrylic::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.8f, 0.3f, 0.2f, 1.0f });
		Acrylic::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		Acrylic::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	AC_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::SliderFloat("Square Rotation", &m_SquareRotation, 0, 360);
	ImGui::End();
}

void Sandbox2D::OnEvent(Acrylic::Event & e)
{
	m_CameraController.OnEvent(e);
}
