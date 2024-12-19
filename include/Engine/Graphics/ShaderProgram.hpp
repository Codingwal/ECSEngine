#pragma once

#include <glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ShaderProgram
{
public:
    ShaderProgram() : id(-1) {}
    ~ShaderProgram();

    void init(const std::string &vertexPath, const std::string &fragmentPath);
    void use();

    void setBool(const char *name, bool value) const;
    void setInt(const char *name, int value) const;
    void setFloat(const char *name, float value) const;

public:
    unsigned int id;
};