#pragma once
#include "Acrylic.h"

#include "Benchmark.h"
#include "ParticleSystem.h"

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

	Acrylic::Ref<Acrylic::Texture2D> m_Spritesheet;
	Acrylic::Ref<Acrylic::SubTexture2D> m_TextureStairs;
	Acrylic::Ref<Acrylic::SubTexture2D> m_TextureBarrel;
	Acrylic::Ref<Acrylic::SubTexture2D> m_TextureTree;

	glm::vec4 m_SquareColor = { 0.8f, 0.2f, 0.3f, 1.0f };
	float m_SquareRotation = 0.0f;

	Benchmark m_Benchmark;
	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;

	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, Acrylic::Ref<Acrylic::SubTexture2D>> m_TextureMap;
};