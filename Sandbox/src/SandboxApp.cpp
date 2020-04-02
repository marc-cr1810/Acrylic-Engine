#include <Acrylic.h>

#include "imgui/imgui.h"

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

		std::shared_ptr<Acrylic::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Acrylic::VertexBuffer::Create(vertices, sizeof(vertices)));
		Acrylic::BufferLayout layout = {
			{ Acrylic::ShaderDataType::Float3, "a_Position" },
			{ Acrylic::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Acrylic::IndexBuffer> indexBuffer;
		indexBuffer.reset(Acrylic::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Acrylic::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Acrylic::VertexBuffer> squareVB;
		squareVB.reset(Acrylic::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Acrylic::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Acrylic::IndexBuffer> squareIB;
		squareIB.reset(Acrylic::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
						
			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
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

		m_Shader.reset(new Acrylic::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);		
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;

			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Acrylic::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
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

		Acrylic::Renderer::Submit(m_BlueShader, m_SquareVA);
		Acrylic::Renderer::Submit(m_Shader, m_VertexArray);

		Acrylic::Renderer::EndScene();

	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(Acrylic::Event& event) override
	{

	}
private:
	std::shared_ptr<Acrylic::Shader> m_Shader;
	std::shared_ptr<Acrylic::VertexArray> m_VertexArray;

	std::shared_ptr<Acrylic::Shader> m_BlueShader;
	std::shared_ptr<Acrylic::VertexArray> m_SquareVA;

	Acrylic::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
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