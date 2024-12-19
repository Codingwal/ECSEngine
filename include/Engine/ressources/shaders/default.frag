#version 330 core

out vec4 color;

in vec3 fColor;
in vec2 fTexCoord;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
    color = mix(texture(tex1, fTexCoord), texture(tex2, fTexCoord), 0.3);
}