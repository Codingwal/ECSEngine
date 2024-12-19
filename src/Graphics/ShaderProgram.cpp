#include "Graphics/ShaderProgram.hpp"
#include <cassert>

std::string ReadFile(const char *fileName)
{
    std::ifstream stream(fileName);
    if (!stream)
        std::cerr << "Failed to open file \"" << fileName << "\".\n";
    std::stringstream buffer;
    buffer << stream.rdbuf();
    stream.close();
    std::string str = buffer.str();
    return str;
}
void ValidateShader(GLuint shader, const char *errorMsg)
{
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << errorMsg << infoLog << "\n";
    }
}
void ValidateShaderProgram(GLuint shaderProgram, const char *errorMsg)
{
    int success;
    glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << errorMsg << infoLog << "\n";
    }
}
void ESCEngine::ShaderProgram::Init(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::string vertexShaderSourceString = ReadFile(vertexPath.c_str());
    const char *vertexShaderSource = vertexShaderSourceString.c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    ValidateShader(vertexShader, "Failed to compile vertex shader.\n");

    std::string fragmentShaderSourceString = ReadFile(fragmentPath.c_str());
    const char *fragmentShaderSource = fragmentShaderSourceString.c_str();
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    ValidateShader(fragmentShader, "Failed to compile fragment shader.\n");

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
    ValidateShaderProgram(id, "Failed to link program.\n");

    // Shaders are now contained by the shader program and can be deleted
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ESCEngine::ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(id);
}

void ESCEngine::ShaderProgram::Use()
{
    assert(id != -1 && "Shader has not been correctly constructed.");
    glUseProgram(id);
}

void ESCEngine::ShaderProgram::SetBool(const char *name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name), (int)value);
}

void ESCEngine::ShaderProgram::SetInt(const char *name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name), value);
}

void ESCEngine::ShaderProgram::SetFloat(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name), (int)value);
}
void ESCEngine::ShaderProgram::SetFloat4x4(const char *name, Float4x4 matrix) const
{
    glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, matrix.ToColumnMajorArray().begin());
}
