
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#include <glad/glad.h>
#include <iostream>

namespace gli
{
    void GLClearError()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    bool GLLogCall()
    {
        while (GLenum error = glGetError())
        {
            std::cout << "[OpenGL Error] (" << error << ")" << std::endl;
            return false;
        }

        return true;
    }
}