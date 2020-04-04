#include <Acrylic.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Acrylic::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{ 
		m_VertexArray.reset(Acrylic::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Acrylic::Ref<Acrylic::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Acrylic::VertexBuffer::Create(vertices, sizeof(vertices)));
		Acrylic::BufferLayout layout = {
			{ Acrylic::ShaderDataType::Float3, "a_Position" },
			{ Acrylic::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Acrylic::Ref<Acrylic::IndexBuffer> indexBuffer;
		indexBuffer.reset(Acrylic::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Acrylic::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Acrylic::Ref<Acrylic::VertexBuffer> squareVB;
		squareVB.reset(Acrylic::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Acrylic::ShaderDataType::Float3, "a_Position" },
			{ Acrylic::ShaderDataType::Float2, "a_TexCoord" }
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Acrylic::Ref<Acrylic::IndexBuffer> squareIB;
		squareIB.reset(Acrylic::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
						
			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(Acrylic::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;
			
			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader.reset(Acrylic::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));

		std::string textureShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_TexCoord;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec2 v_TexCoord;

			void main()
			{
				v_TexCoord = a_TexCoord;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string textureShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec2 v_TexCoord;
			
			uniform sampler2D u_Texture;

			void main()
			{
				color = texture(u_Texture, v_TexCoord);
			}
		)";

		m_TextureShader.reset(Acrylic::Shader::Create(textureShaderVertexSrc, textureShaderFragmentSrc));

		m_Texture = Acrylic::Texture2D::Create("assets/textures/Checkerboard.png");
		m_DuckTexture = Acrylic::Texture2D::Create("assets/textures/Duck.png");

		std::dynamic_pointer_cast<Acrylic::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Acrylic::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);

	}

	void OnUpdate(Acrylic::Timestep ts) override
	{
		if (Acrylic::Input::IsKeyPressed(AC_KEY_A))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (Acrylic::Input::IsKeyPressed(AC_KEY_D))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Acrylic::Input::IsKeyPressed(AC_KEY_W))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Acrylic::Input::IsKeyPressed(AC_KEY_S))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Acrylic::Input::IsKeyPressed(AC_KEY_Q))
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		if (Acrylic::Input::IsKeyPressed(AC_KEY_E))
			m_CameraRotation += m_CameraRotationSpeed * ts;

		Acrylic::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Acrylic::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Acrylic::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Acrylic::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Acrylic::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = -10; y < 10; y++)
		{
			for (int x = -10; x < 10; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Acrylic::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		Acrylic::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_DuckTexture->Bind();
		Acrylic::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		//Acrylic::Renderer::Submit(m_Shader, m_VertexArray);

		Acrylic::Renderer::EndScene();

	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Acrylic::Event& event) override
	{

	}
private:
	Acrylic::Ref<Acrylic::Shader> m_Shader;
	Acrylic::Ref<Acrylic::VertexArray> m_VertexArray;

	Acrylic::Ref<Acrylic::Shader> m_FlatColorShader, m_TextureShader;
	Acrylic::Ref<Acrylic::VertexArray> m_SquareVA;

	Acrylic::Ref<Acrylic::Texture2D> m_Texture, m_DuckTexture;

	Acrylic::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Acrylic::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Acrylic::Application* Acrylic::CreateApplication()
{
	return new Sandbox();
}