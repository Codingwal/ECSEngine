#pragma once

#include <glad.h>
#include <glfw3.h>
#include "ShaderProgram.hpp"
#include <vector>
#include "Texture.hpp"

class Renderer
{
public:
    void Init();
    void Run();
    void Dispose();

private:
    GLFWwindow *window = nullptr;
    ShaderProgram shader;
    std::vector<Texture> textures;
    GLuint vao, vbo, ebo = -1; // vertex array object, vertex buffer object, element buffer object
};