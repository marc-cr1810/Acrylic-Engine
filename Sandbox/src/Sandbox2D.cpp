#include "Sandbox2D.h"

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static uint32_t s_MapWidth = 24;
static const char* s_MapTiles =
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWGGGGGGGWWWWWWWWW"
"WWWWWWGGGGGGGGGGWWWWWWWW"
"WWWWGGGGGGWWWWGGGGGWWWWW"
"WWWGGGGGGWWWWWGGGGGGWWWW"
"WWWGGGGGGGGWWGGGGGGGWWWW"
"WWWWGGGGGGGGGGGGGGWWWWWW"
"WWWWWWGGGGGGGGWWWWWWWWWW"
"WWWWWWWWGGGGGWWWWWWWWWWW"
"WWWWWWWWWGGGWWWWWGGWWWWW"
"WWWWWWWWWWWWWWWWWGGWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW";

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{
	AC_PROFILE_FUNCTION();

	m_CheckerboardTexture = Acrylic::Texture2D::Create("assets/textures/Checkerboard.png");
	m_DuckTexture = Acrylic::Texture2D::Create("assets/textures/Duck.png");

	m_Spritesheet = Acrylic::Texture2D::Create("assets/game/textures/spritesheet.png");

	m_TextureStairs = Acrylic::SubTexture2D::CreateFromCoords(m_Spritesheet, { 7, 6 }, { 128, 128 });
	m_TextureBarrel = Acrylic::SubTexture2D::CreateFromCoords(m_Spritesheet, { 8, 2 }, { 128, 128 });
	m_TextureTree = Acrylic::SubTexture2D::CreateFromCoords(m_Spritesheet, { 2, 1 }, { 128, 128 }, { 1, 2 });

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / m_MapWidth;

	m_TextureMap['W'] = Acrylic::SubTexture2D::CreateFromCoords(m_Spritesheet, { 11, 11 }, { 128, 128 });
	m_TextureMap['G'] = Acrylic::SubTexture2D::CreateFromCoords(m_Spritesheet, { 1, 11 }, { 128, 128 });

	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 5.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_Camera.SetOrthographic(10.0f, -5.0f, 5.0f);
	m_CameraController.SetZoomLevel(5.0f);
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
#if 1
	{
		AC_PROFILE_SCOPE("Renderer Draw");

		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		m_Benchmark.OnUpdate(ts);

		Acrylic::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Acrylic::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(m_SquareRotation), m_SquareColor);
		Acrylic::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Acrylic::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.8f, 0.3f, 0.2f, 1.0f });
		Acrylic::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Acrylic::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, -0.01f }, { 1.0f, 1.0f }, glm::radians(rotation), m_DuckTexture);
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

	if (Acrylic::Input::IsMouseButtonPressed(Acrylic::Mouse::ButtonLeft))
	{
		auto pos = Acrylic::Input::GetMousePosition();
		auto x = pos.x;
		auto y = pos.y;
		auto width = Acrylic::Application::Get().GetWindow().GetWidth();
		auto height = Acrylic::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 50; i++)
			m_ParticleSystem.Emit(m_Particle);
	}

	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());

#else
	Acrylic::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			char tileType = s_MapTiles[x + y * m_MapWidth];
			Acrylic::Ref<Acrylic::SubTexture2D> texture;

			if (m_TextureMap.find(tileType) != m_TextureMap.end())
				texture = m_TextureMap[tileType];
			else
				texture = m_TextureBarrel;

			Acrylic::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, m_MapHeight - y - m_MapHeight / 2.0f, 0.0f }, { 1.0f, 1.0f }, texture);
		}
	}

	Acrylic::Renderer2D::EndScene();
#endif
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
	ImGui::Text("Frametime: %f (%d FPS)", m_Benchmark.GetAvgFrameTime(), m_Benchmark.GetFPS());
	ImGui::Text("Low 1.0: %f (%d FPS)", m_Benchmark.GetAvgLow1(), m_Benchmark.GetFPSLow1());
	ImGui::Text("Low 0.1: %f (%d FPS)", m_Benchmark.GetAvgLow01(), m_Benchmark.GetFPSLow01());
	ImGui::Text("");

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::SliderFloat("Square Rotation", &m_SquareRotation, 0, 360);

	ImGui::End();
}

void Sandbox2D::OnEvent(Acrylic::Event & e)
{
	m_CameraController.OnEvent(e);
}
