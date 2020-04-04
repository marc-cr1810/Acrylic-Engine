#include "Sandbox2D.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{
	m_SquareVA = Acrylic::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
}

void Sandbox2D::OnDetach()
{
	
}

void Sandbox2D::OnUpdate(Acrylic::Timestep ts)
{

}

void Sandbox2D::OnImGuiRender()
{

}

void Sandbox2D::OnEvent(Acrylic::Event & e)
{
	m_CameraController.OnEvent(e);
}
