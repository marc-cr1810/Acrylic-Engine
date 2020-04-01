#include <Acrylic.h>

#include "imgui/imgui.h"

class ExampleLayer : public Acrylic::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		if (Acrylic::Input::IsKeyPressed(AC_KEY_TAB))
			AC_INFO("Tab key is pressed! (poll)");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}

	void OnEvent(Acrylic::Event& event) override
	{
		if (event.GetEventType() == Acrylic::EventType::KeyPressed)
		{
			Acrylic::KeyPressedEvent& e = (Acrylic::KeyPressedEvent&)event;
			if (e.GetKeyCode() == AC_KEY_TAB)
				AC_INFO("Tab key is pressed! (event)");
		}
	}
};

class Sandbox : public Acrylic::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Acrylic::Application* Acrylic::CreateApplication()
{
	return new Sandbox();
}