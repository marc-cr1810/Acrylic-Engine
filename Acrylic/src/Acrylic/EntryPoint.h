#pragma once

#ifdef AC_PLATFORM_WINDOWS

extern Acrylic::Application* Acrylic::CreateApplication();

int main(int argc, char** argv)
{
	printf("Acrylic Engine");
	auto app = Acrylic::CreateApplication();
	app->Run();
	delete app;
}

#endif