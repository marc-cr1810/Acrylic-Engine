#pragma once
#include "Acrylic/Core/Base.h"
#include "Acrylic/Core/Application.h"

#ifdef AC_PLATFORM_WINDOWS

extern Acrylic::Application* Acrylic::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Acrylic::Log::Init();
	AC_CORE_INFO("Initialized Log!");

	AC_PROFILE_BEGIN_SESSION("Startup", "AcrylicProfile-Startup.json");
	auto app = Acrylic::CreateApplication({ argc, argv });
	AC_PROFILE_END_SESSION();

	AC_PROFILE_BEGIN_SESSION("Runtime", "AcrylicProfile-Runtime.json");
	app->Run();
	AC_PROFILE_END_SESSION();

	AC_PROFILE_BEGIN_SESSION("Shutdown", "AcrylicProfile-Shutdown.json");
	delete app;
	AC_PROFILE_END_SESSION();
}

#endif
