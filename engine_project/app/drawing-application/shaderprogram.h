#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include "matrixfactory.h"

#include "GL/glew.h"
#include "GL/freeglut.h"

#define VERTICES 0
#define COLORS 1

namespace GLSLShader {
    enum GLSLShaderType{
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER
    };
};

class ShaderProgramException : public std::runtime_error {
      public:
        ShaderProgramException( const std::string & msg ) :
        std::runtime_error(msg) { }
};

class ShaderProgram {
    private:

        GLuint programID;
        bool linked;
        std::string logString;
        std::unordered_map<std::string,GLint> uniformIDs;

        GLint getUniformLocation(const char* name);

    public:
        ShaderProgram();
        ~ShaderProgram();

        void compileShaderFromFile(const char* fileName, GLSLShader::GLSLShaderType type) throw (ShaderProgramException);
        void compileShaderFromString(const std::string& source, GLSLShader::GLSLShaderType type) throw (ShaderProgramException);
        void link() throw (ShaderProgramException);
        void use() throw (ShaderProgramException);

        std::string log();

        int getProgramID();
        bool isLinked();

            void bindAttribLocation(GLuint location, const char* name);
        void bindFragDataLocation(GLuint location, const char* name);

        void setUniform(const char* name, float x, float y, float z, float w);
        void setUniform(const char* name, float* vec);
        void setUniform(const char* name, const GLfloat* m);
        //void setUniform(const char* name, const float* m);
};

#endif
