#pragma once
#include<glad/glad.h>
#include<string>
#include<fstream>
#include <iostream>
#include <glm/glm.hpp>

std::string GetFileContents(const char* filename);

namespace BGRCore {

    class Shader
    {
    public:
        GLuint ID;
        Shader(const char* vertexFile, const char* fragmentFile);

        void Activate();
        void Delete();

        void SetFloat(std::string name, float val);
        void SetUniform1i(std::string name, GLuint val);
        void SetUniformMatrix4(std::string name, glm::mat4 val);
    private:
        void CompileErrors(unsigned int shader, const char* type);
    };
}