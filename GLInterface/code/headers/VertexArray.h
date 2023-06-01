
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace gli
{
	/// <summary>
	/// OpenGL Vertex Array handler
	/// </summary>
	class VertexArray
	{
		
	private:

		unsigned int id;

	public:

		/// <summary>
		/// Create a new Vertex Array object in GPU
		/// </summary>
		VertexArray();
	   ~VertexArray();

	   /// <summary>
	   /// Add a vertex buffer to vertex array object
	   /// </summary>
	   /// <param name="vb">Vertex buffer object</param>
	   /// <param name="layout">Layout of vertex buffer</param>
	   void addBuffer(VertexBuffer& vb, const VertexBufferLayout& layout);

	   /// <summary>
	   /// Bind vertex array object
	   /// </summary>
	   void bind();

	   /// <summary>
	   /// Unbind vertex array object
	   /// </summary>
	   void unbind();
	};
}
