#pragma once

#include <glad.h>
#include <glfw3.h>
#include <vector>
#include "Texture.hpp"
#include <string>
#include "Math/Math.hpp"
#include "ShaderProgram.hpp"

namespace ECSEngine
{
    // struct Mesh
    // {
    // };
    struct Object
    {
        Float4x4 transformMatrix;
        // Mesh mesh;
    };
    class Renderer
    {
    public:
        void Init(const std::string &ressourcesFolderPath);
        void Update();
        void Dispose();
        float GetTime();
        bool ShouldStop();
        void CreateTexture();

    public:
        std::vector<Object> objects;

    private:
        GLFWwindow *window = nullptr;
        ESCEngine::ShaderProgram shader;
        std::vector<Texture> textures;
        GLuint vao, vbo, ebo = -1; // vertex array object, vertex buffer object, element buffer object

        std::string pathRessourcesFolder;
        std::string pathShadersFolder;
        std::string pathImagesFolder;
    };
}