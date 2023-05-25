
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

namespace gli
{
	class VertexBuffer
	{

	private:

		// ID of vertex buffer given by OpenGL
		unsigned int id;

	public:

		VertexBuffer() { }

		VertexBuffer(const void* data, unsigned int size);
	   ~VertexBuffer();

	public:

		void bind();
		void unbind();

		void upload_to_gpu(const void* data, unsigned int size);
	};
}

