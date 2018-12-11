#include "acpch.h"
#include "Application.h"

#include "Acrylic/Events/ApplicationEvent.h"
#include "Acrylic/Log.h"

namespace Acrylic {

	Application::Application()
	{ }


	Application::~Application()
	{ }

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
			AC_TRACE(e);
		else if (e.IsInCategory(EventCategoryInput))
			AC_TRACE(e);

		while (true);
	}

}