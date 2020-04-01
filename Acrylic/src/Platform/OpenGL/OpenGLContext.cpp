#include "acpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Acrylic
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		AC_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AC_CORE_ASSERT(status, "Failed to initialize Glad!");

		AC_CORE_INFO("OpenGL Info:", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
		AC_CORE_INFO("  Vendor:	{0}", glGetString(GL_VENDOR));
		AC_CORE_INFO("  Renderer:	{0}", glGetString(GL_RENDERER));
		AC_CORE_INFO("  Version:	{0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}