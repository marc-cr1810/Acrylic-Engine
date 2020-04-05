#include "acpch.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

///////////////////////////////////
////////// Vertex Buffer //////////
///////////////////////////////////

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

///////////////////////////////////
////////// Index Buffer  //////////
///////////////////////////////////

Acrylic::OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
	: m_Count(count)
{
	AC_PROFILE_FUNCTION();

	glCreateBuffers(1, &m_RendererID);
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
