#include "acpch.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

///////////////////////////////////
////////// Vertex Buffer //////////
///////////////////////////////////

Acrylic::OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size)
{
	AC_PROFILE_FUNCTION();

	glCreateBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

Acrylic::OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
{
	AC_PROFILE_FUNCTION();

	glCreateBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

Acrylic::OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	AC_PROFILE_FUNCTION();

	glDeleteBuffers(1, &m_RendererID);
}

void Acrylic::OpenGLVertexBuffer::Bind() const
{
	AC_PROFILE_FUNCTION();

	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void Acrylic::OpenGLVertexBuffer::Unbind() const
{
	AC_PROFILE_FUNCTION();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Acrylic::OpenGLVertexBuffer::SetData(const void* data, uint32_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

///////////////////////////////////
////////// Index Buffer  //////////
///////////////////////////////////

Acrylic::OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
	: m_Count(count)
{
	AC_PROFILE_FUNCTION();

	glCreateBuffers(1, &m_RendererID);

	// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
	// Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state. 
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
}

Acrylic::OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	AC_PROFILE_FUNCTION();

	glDeleteBuffers(1, &m_RendererID);
}

void Acrylic::OpenGLIndexBuffer::Bind() const
{
	AC_PROFILE_FUNCTION();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void Acrylic::OpenGLIndexBuffer::Unbind() const
{
	AC_PROFILE_FUNCTION();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
