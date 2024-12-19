#pragma once

#include <glad.h>
#include <string>

namespace ECSEngine
{
    class Texture
    {
    public:
        GLuint id;

    private:
        Texture(const std::string &filePath, GLuint format);

        friend class Renderer;
    };
}