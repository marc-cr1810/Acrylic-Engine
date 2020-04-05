#include <Acrylic.h>
#include "Acrylic/Core/EntryPoint.h"

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class ExampleLayer : public Acrylic::Layer
{
public:
};

class Sandbox : public Acrylic::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{}
};

Acrylic::Application* Acrylic::CreateApplication()
{
	return new Sandbox();
}