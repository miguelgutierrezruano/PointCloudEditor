
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glad/glad.h>

#include "VertexBuffer.h"

namespace gli
{
	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		upload_to_gpu(data, size);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void VertexBuffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void VertexBuffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::upload_to_gpu(const void* data, unsigned int size)
	{
		// Delete current buffer if there is data
		if (id != 0)
			glDeleteBuffers(1, &id);

		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
}