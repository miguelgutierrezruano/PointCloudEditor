
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

namespace gli
{

    /// <summary>
    /// Interface acting as bridge between OpenGL and QtOpenGLWidget for Qt projects
    /// </summary>
    class Renderer
    {
    public:

        virtual ~Renderer() = default;

        /// <summary>
        /// Method called when QtWidget does first render action
        /// </summary>
        virtual void initialize () = 0;

        /// <summary>
        /// Method called when QtApplication window resizes
        /// </summary>
        /// <param name="new_viewport_width">New width</param>
        /// <param name="new_viewport_height">New height</param>
        virtual void resize (int new_viewport_width, int new_viewport_height) = 0;

        /// <summary>
        /// Called everytime QtOpenGLWidget wants to render
        /// </summary>
        virtual void render () = 0;

    };

}
