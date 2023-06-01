
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

namespace gli
{
	/// <summary>
	/// OpenGL Element Array Buffer handler
	/// </summary>
	class IndexBuffer
	{

	private:

		// ID of vertex buffer given by OpenGL
		unsigned int id;

		// Element count
		unsigned int count;

	public:

		IndexBuffer() { id = 0; count = 0; }

		/// <summary>
		/// Constructor to create an element array buffer on GPU
		/// </summary>
		/// <param name="data">Data to upload to GPU</param>
		/// <param name="bufferCount">Data elements count</param>
		IndexBuffer(const unsigned int* data, unsigned int bufferCount);
	   ~IndexBuffer();

	public:

		/// <summary>
		/// Bind element array buffer
		/// </summary>
		void bind();

		/// <summary>
		/// Unbind element array buffer
		/// </summary>
		void unbind();

		/// <summary>
		/// Create a new element array buffer on GPU
		/// </summary>
		/// <param name="data">Data to upload to GPU</param>
		/// <param name="bufferCount">Data elements count</param>
		void upload_to_gpu(const unsigned int* data, unsigned int bufferCount);

		unsigned int GetCount() const { return count; }
	};
}

