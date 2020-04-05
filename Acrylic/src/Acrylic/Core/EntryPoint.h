#pragma once
#include "Acrylic/Core/Core.h"

#ifdef AC_PLATFORM_WINDOWS

extern Acrylic::Application* Acrylic::CreateApplication();

int main(int argc, char** argv)
{
	Acrylic::Log::Init();
	AC_CORE_WARN("Initialized Log!");
	int a = 5;
	AC_INFO("Hello! Var={0}", a);

	AC_PROFILE_BEGIN_SESSION("Startup", "AcrylicProfile-Startup.json");
	auto app = Acrylic::CreateApplication();
	AC_PROFILE_END_SESSION();

	AC_PROFILE_BEGIN_SESSION("Runtime", "AcrylicProfile-Runtime.json");
	app->Run();
	AC_PROFILE_END_SESSION();

	AC_PROFILE_BEGIN_SESSION("Startup", "AcrylicProfile-Shutdown.json");
	delete app;
	AC_PROFILE_END_SESSION();
}

#endif