
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec3 vColor;

// Object transform
uniform mat4 model;

// View (Camera transform)
uniform mat4 view;

// Projection to NDC
uniform mat4 projection;

void main()
{
    vColor = color;
    gl_Position = projection * view * model * vec4(position, 1);
}

#shader fragment
#version 330 core

in vec3 vColor;

out vec4 color;

void main()
{
    color = vec4(vColor, 1);
}