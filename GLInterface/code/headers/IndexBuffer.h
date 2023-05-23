
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

namespace gli
{
	// TODO: Make template with different int types
	class IndexBuffer
	{

	private:

		// ID of vertex buffer given by OpenGL
		unsigned int id;

		unsigned int count;

	public:

		IndexBuffer() { id = 0; count = 0; }

		IndexBuffer(const unsigned int* data, unsigned int bufferCount);
	   ~IndexBuffer();

	public:

		void bind();
		void unbind();

		void upload_to_gpu(const unsigned int* data, unsigned int bufferCount);

		unsigned int GetCount() const { return count; }
	};
}

