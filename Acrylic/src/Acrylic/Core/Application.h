#pragma once

#include "Acrylic/Core/Core.h"

#include "Acrylic/Core/Window.h"
#include "Acrylic/Core/LayerStack.h"
#include "Acrylic/Events/Event.h"
#include "Acrylic/Events/ApplicationEvent.h"

#include "Acrylic/ImGui/ImGuiLayer.h"

namespace Acrylic 
{
	class ACRYLIC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();

}