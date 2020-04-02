#pragma once

#include "Acrylic/Renderer/RenderCommand.h"
#include "Acrylic/Renderer/OrthographicCamera.h"
#include "Acrylic/Renderer/Shader.h"

namespace Acrylic
{
	class Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* s_SceneData;
	};
}