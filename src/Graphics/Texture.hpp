#pragma once

#include <glad.h>

class Texture
{
public:
    GLuint id;
    Texture(const char*filePath, GLuint format);
};