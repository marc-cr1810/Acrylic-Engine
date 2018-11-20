#pragma once

#include "Core.h"

namespace Acrylic {

	class ACRYLIC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}