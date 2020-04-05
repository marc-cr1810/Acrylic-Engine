#pragma once

#include "Acrylic/Core/Core.h"

#include "Acrylic/Core/Window.h"
#include "Acrylic/Core/LayerStack.h"
#include "Acrylic/Core/Timestep.h"

#include "Acrylic/Events/Event.h"
#include "Acrylic/Events/ApplicationEvent.h"

#include "Acrylic/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Acrylic 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		void Run();
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in client
	Application* CreateApplication();

}