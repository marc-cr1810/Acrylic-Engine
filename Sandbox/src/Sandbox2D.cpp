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
	m_DuckTexture = Acrylic::Texture2D::Create("assets/textures/Duck.png");
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
	Acrylic::Renderer2D::ResetStats();
	{
		AC_PROFILE_SCOPE("Renderer Prep");
		Acrylic::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Acrylic::RenderCommand::Clear();
	}

	{
		AC_PROFILE_SCOPE("Renderer Draw");

		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		m_FPSTemp++;
		m_TimePassed += ts;
		if (m_TimePassed >= 1.0f)
		{
			m_FPS = m_FPSTemp;
			m_FPSTemp = 0;
			m_TimePassed = 0.0f;
		}

		Acrylic::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Acrylic::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, m_SquareRotation, m_SquareColor);
		Acrylic::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Acrylic::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.8f, 0.3f, 0.2f, 1.0f });
		Acrylic::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Acrylic::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, -0.01f }, { 1.0f, 1.0f }, rotation, m_DuckTexture);
		Acrylic::Renderer2D::EndScene();

		Acrylic::Renderer2D::BeginScene(m_CameraController.GetCamera());
		float size = 0.25f;

		for (float y = -5.0f; y < 5.0f; y += size)
		{
			for (float x = -5.0f; x < 5.0f; x += size)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Acrylic::Renderer2D::DrawQuad({ x, y }, { size * 0.9f, size * 0.9f }, color);
			}
		}
		Acrylic::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	AC_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = Acrylic::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
	ImGui::Text("FPS: %d", m_FPS);
	ImGui::Text("");

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::SliderFloat("Square Rotation", &m_SquareRotation, 0, 360);
	ImGui::End();
}

void Sandbox2D::OnEvent(Acrylic::Event & e)
{
	m_CameraController.OnEvent(e);
}
