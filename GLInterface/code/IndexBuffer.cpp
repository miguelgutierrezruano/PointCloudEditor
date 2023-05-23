
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glad/glad.h>

#include "IndexBuffer.h"

namespace gli
{
	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int bufferCount)
	{
		upload_to_gpu(data, bufferCount);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void IndexBuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IndexBuffer::upload_to_gpu(const unsigned int* data, unsigned int bufferCount)
	{
		count = bufferCount;

		glGenBuffers(1, &id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}
}