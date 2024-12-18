#include "Texture.hpp"
#include <iostream>
#include "stb_image.hpp"
#include <cassert>

Texture::Texture(const char *filePath, GLuint format)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, channelsCount;
    unsigned char *data = stbi_load(filePath, &width, &height, &channelsCount, 0);
    if (data)
    {
        if (channelsCount == 1 && format != GL_RED ||
            channelsCount == 2 && format != GL_RG ||
            channelsCount == 3 && format != GL_RGB ||
            channelsCount == 4 && format != GL_RGBA)
        {
            std::cerr << "Invalid format (" << format << ") for texture with " << channelsCount << " channels.\n";
            stbi_image_free(data);
            return;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
        std::cerr << "Failed to load texture.\n";

    stbi_image_free(data);
}