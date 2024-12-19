#include "Graphics/ShaderProgram.hpp"
#include <cassert>

std::string readFile(const char *fileName)
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
void validateShader(GLuint shader, const char *errorMsg)
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
void validateShaderProgram(GLuint shaderProgram, const char *errorMsg)
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
void ESCEngine::ShaderProgram::init(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::string vertexShaderSourceString = readFile(vertexPath.c_str());
    const char *vertexShaderSource = vertexShaderSourceString.c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    validateShader(vertexShader, "Failed to compile vertex shader.\n");

    std::string fragmentShaderSourceString = readFile(fragmentPath.c_str());
    const char *fragmentShaderSource = fragmentShaderSourceString.c_str();
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    validateShader(fragmentShader, "Failed to compile fragment shader.\n");

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
    validateShaderProgram(id, "Failed to link program.\n");

    // Shaders are now contained by the shader program and can be deleted
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ESCEngine::ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(id);
}

void ESCEngine::ShaderProgram::use()
{
    assert(id != -1 && "Shader has not been correctly constructed.");
    glUseProgram(id);
}

void ESCEngine::ShaderProgram::setBool(const char *name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name), (int)value);
}

void ESCEngine::ShaderProgram::setInt(const char *name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name), value);
}

void ESCEngine::ShaderProgram::setFloat(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name), (int)value);
}
