#pragma once

#include <glad.h>
#include <string>

class Texture
{
public:
    GLuint id;
    Texture(const std::string &filePath, GLuint format);
};