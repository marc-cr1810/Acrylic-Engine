#include <Acrylic.h>
#include "Acrylic/Core/EntryPoint.h"

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Acrylic::Application
{
public:
	Sandbox(const Acrylic::ApplicationSpecification& spec)
			: Application(spec)
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{}
};

Acrylic::Application* Acrylic::CreateApplication(ApplicationCommandLineArgs args)
{
	return new Sandbox();
}
