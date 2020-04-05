#include "acpch.h"
#include "Acrylic/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Acrylic
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}