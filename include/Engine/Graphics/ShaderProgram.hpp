#pragma once

#include <glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Math/Float4x4.hpp"

namespace ESCEngine
{
    class ShaderProgram
    {
    public:
        ShaderProgram() : id(-1) {}
        ~ShaderProgram();

        void Init(const std::string &vertexPath, const std::string &fragmentPath);
        void Use();

        void SetBool(const char *name, bool value) const;
        void SetInt(const char *name, int value) const;
        void SetFloat(const char *name, float value) const;
        void SetFloat4x4(const char *name, Float4x4 matrix) const;

    public:
        unsigned int id;
    };
}