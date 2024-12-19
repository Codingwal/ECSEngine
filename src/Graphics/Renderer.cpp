#include "Graphics/Renderer.hpp"

#include <iostream>
#include <math.h>
#include <glad.h>
#include <glfw3.h>
#include "Graphics/stb_image.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Texture.hpp"
#include "Math/Math.hpp"

#define WIDTH 800
#define HEIGHT 800

#define DEFAULT_SHADER_FRAG "default.frag"
#define DEFAULT_SHADER_VERT "default.vert"

void createVAOandVBO(GLuint *vao, GLuint *vbo, GLuint *ebo)
{
    GLfloat vertices[] =
        {
            0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // Upper right corner
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // Lower right corner
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // Lower left corner
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,  // Upper left corner
        };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3, // second triangle
    };

    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(*vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // The value at location 0 in the fragment shader is the position vec3
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // The value at location 1 in the fragment shader is the texture coords vec2
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // unbind the vao & vbo so they are not accidentally modified
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void ECSEngine::Renderer::Init(const std::string &ressourcesFolderPath)
{
    pathRessourcesFolder = ressourcesFolderPath;
    pathShadersFolder = pathRessourcesFolder + "shaders/";
    pathImagesFolder = pathRessourcesFolder + "images/";

    glfwInit();

    // OpenGL version 3.3 and only the modern functions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window, handle errors and add it to the context
    window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    gladLoadGL();

    glViewport(0, 0, WIDTH, HEIGHT);

    shader.Init(pathShadersFolder + DEFAULT_SHADER_VERT, pathShadersFolder + DEFAULT_SHADER_FRAG);

    stbi_set_flip_vertically_on_load(true);
    textures.push_back(Texture(pathImagesFolder + "container.jpg", GL_RGB));
    textures.push_back(Texture(pathImagesFolder + "awesomeface.png", GL_RGBA));

    vao, vbo, ebo; // vertex array object, vertex buffer object
    createVAOandVBO(&vao, &vbo, &ebo);

    shader.Use();
    shader.SetInt("tex1", 0);
    shader.SetInt("tex2", 1);
}

void ECSEngine::Renderer::Update()
{
    // Clear the screen
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader.Use();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures.at(0).id);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textures.at(1).id);

    glBindVertexArray(vao);

    Float4x4 view = Float4x4::Identity();
    Float4x4 projection = Float4x4::Identity();
    view = Float4x4::Translate(view, Float3(0, -3, -3));
    projection = Float4x4::Perspective(45, 0.1f, 100.0f);
    shader.SetFloat4x4("projection", projection);

    for (const auto &obj : objects)
    {
        shader.SetFloat4x4("transform", obj.transformMatrix);
        shader.SetFloat4x4("view", view);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glBindVertexArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void ECSEngine::Renderer::Dispose()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    glfwDestroyWindow(window);
    glfwTerminate();
}
float ECSEngine::Renderer::GetTime()
{
    return (float)glfwGetTime();
}
bool ECSEngine::Renderer::ShouldStop()
{
    return glfwWindowShouldClose(window);
}
