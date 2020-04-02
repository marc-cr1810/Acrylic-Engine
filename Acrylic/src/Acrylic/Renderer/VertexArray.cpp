#include "acpch.h"
#include "VertexArray.h"

#include "Acrylic/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Acrylic
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    AC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexArray();
		}

		AC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}