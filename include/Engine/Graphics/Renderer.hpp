#pragma once

#include <glad.h>
#include <glfw3.h>
#include <vector>
#include "Texture.hpp"
#include <string>
#include "Math/Math.hpp"
#include "ShaderProgram.hpp"
#include <map>

namespace ECSEngine
{
    struct Mesh
    {
        std::vector<float> vertices;
        std::vector<int> indices;
        Mesh(std::vector<float> _vertices, std::vector<int> _indices)
        {
            vertices = _vertices;
            indices = _indices;
        }
    };

    using MeshID = uint32_t;
    using MaterialID = uint32_t;
    struct RenderingInfo
    {
        MeshID mesh;
        MaterialID material;
    };
    struct Object
    {
        Float4x4 transformMatrix;
        RenderingInfo info;
    };
    class Renderer
    {
    public:
        void Init(const std::string &ressourcesFolderPath);
        void Update();
        void Dispose();
        float GetTime();
        bool ShouldStop();
        // void CreateTexture();
        // void CreateMesh();

    public:
        std::vector<Object> objects;

    private:
        GLFWwindow *window = nullptr;
        ESCEngine::ShaderProgram shader;
        GLuint vao, vbo, ebo = -1; // vertex array object, vertex buffer object, element buffer object

        std::vector<Texture> textures;
        std::map<std::string, GLuint> vaos;
    
        std::string pathRessourcesFolder;
        std::string pathShadersFolder;
        std::string pathImagesFolder;
        std::string pathMeshesFolder;
    };
}