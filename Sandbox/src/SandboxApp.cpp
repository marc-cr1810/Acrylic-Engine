#include <Acrylic.h>

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
		PushOverlay(new Acrylic::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Acrylic::Application* Acrylic::CreateApplication()
{
	return new Sandbox();
}