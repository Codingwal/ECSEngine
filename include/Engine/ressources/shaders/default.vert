#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vTexCoord;

out vec2 fTexCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(vPos, 1.0f);
    fTexCoord = vTexCoord;
}