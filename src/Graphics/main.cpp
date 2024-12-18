#include <iostream>
#include <math.h>
#include <glad.h>
#include <glfw3.h>
#include "stb_image.hpp"
#include "ShaderProgram.hpp"
#include "Texture.hpp"

#define WIDTH 800
#define HEIGHT 800

#define BASE_PATH "C:\\Users\\flori\\Documents\\Coding\\C++\\OpenGL\\"
#define VERTEX_SHADER_PATH "C:\\Users\\flori\\Documents\\Coding\\C++\\OpenGL\\shaders\\shader.vert"
#define FRAGMENT_SHADER_PATH "C:\\Users\\flori\\Documents\\Coding\\C++\\OpenGL\\shaders\\shader.frag"
#define CONTAINER_JPG_PATH "C:\\Users\\flori\\Documents\\Coding\\C++\\OpenGL\\container.jpg"
#define SMILEY_PNG_PATH "C:\\Users\\flori\\Documents\\Coding\\C++\\OpenGL\\awesomeface.png"

void createVAOandVBO(GLuint *vao, GLuint *vbo, GLuint *ebo)
{
    GLfloat vertices[] =
        {
            0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // Upper right corner
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // Lower right corner
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Lower left corner
            -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  // Upper left corner
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // The value at location 1 in the fragment shader is the color vec3
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // The value at location 2 in the fragment shader is the texture coords vec2
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // unbind the vao & vbo so they are not accidentally modified
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
int main()
{
    glfwInit();

    // OpenGL version 3.3 and only the modern functions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window, handle errors and add it to the context
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    gladLoadGL();

    glViewport(0, 0, WIDTH, HEIGHT);

    ShaderProgram shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

    stbi_set_flip_vertically_on_load(true);
    Texture texture1(CONTAINER_JPG_PATH, GL_RGB);
    Texture texture2(SMILEY_PNG_PATH, GL_RGBA);

    GLuint vao, vbo, ebo; // vertex array object, vertex buffer object
    createVAOandVBO(&vao, &vbo, &ebo);

    shader.use();
    shader.setInt("tex1", 0);
    shader.setInt("tex2", 1);

    while (!glfwWindowShouldClose(window))
    {
        // Clear the screen
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1.id);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2.id);

        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);

        glBindVertexArray(0);

        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}