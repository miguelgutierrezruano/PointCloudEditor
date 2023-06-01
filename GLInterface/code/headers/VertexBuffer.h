
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

namespace gli
{
	/// <summary>
	/// OpenGL Vertex Buffer handler
	/// </summary>
	class VertexBuffer
	{

	private:

		// ID of vertex buffer given by OpenGL
		unsigned int id;

	public:

		VertexBuffer() { id = 0; }

		/// <summary>
		/// Create new vertex buffer on GPU
		/// </summary>
		/// <param name="data">Vertex data</param>
		/// <param name="size">Data size in bytes</param>
		VertexBuffer(const void* data, unsigned int size);
	   ~VertexBuffer();

	public:

		/// <summary>
		/// Bind vertex buffer
		/// </summary>
		void bind();

		/// <summary>
		/// Unbind vertex buffer
		/// </summary>
		void unbind();

		/// <summary>
		/// Create new vertex buffer on GPU
		/// </summary>
		/// <param name="data">Vertex data</param>
		/// <param name="size">Data size in bytes</param>
		void upload_to_gpu(const void* data, unsigned int size);
	};
}

