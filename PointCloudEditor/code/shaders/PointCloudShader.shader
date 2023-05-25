
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

out vec4 vColor;

void main()
{
    vColor = color;
    gl_Position = vec4(position, 1);
}

#shader fragment
#version 330 core

in vec4 vColor;

out vec4 color;

void main()
{
    color = vColor;
}