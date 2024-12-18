#pragma once

#include <glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ShaderProgram
{
public:
    unsigned int id;

    ShaderProgram() : id(-1) {}
    ShaderProgram(const char *vertexPath, const char *fragmentPath);
    ~ShaderProgram();

    void use();

    void setBool(const char *name, bool value) const;
    void setInt(const char *name, int value) const;
    void setFloat(const char *name, float value) const;
};