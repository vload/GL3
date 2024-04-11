#version 430 core

layout (location = 0) in ivec2 in_position;
layout (location = 1) in vec4 in_color;

out vec4 vert_color;

uniform mat4 projection;

void main()
{
    gl_Position = projection * vec4(in_position, 0.0, 1.0);
    vert_color = in_color;
}