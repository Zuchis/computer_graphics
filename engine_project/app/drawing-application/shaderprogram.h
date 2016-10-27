#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#include <fstream>
#include <sstream>

#include <string>

#include <stdexcept>
#include <iostream>

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

class GLSLProgramException : public std::runtime_error {
      public:
        GLSLProgramException( const std::string & msg ) :
        std::runtime_error(msg) { }
};

class GLSLProgram {
    private:
        GLuint handle;
        bool linked;
        std::string logString;
        int getUniformLocation(const char* name);
        bool fileExists (const std::string& fileName);

    public:
        GLSLProgram();
        ~GLSLProgram();

        void compileShaderFromFile(const char* fileName, GLSLShader::GLSLShaderType type) throw (GLSLProgramException);
        void compileShaderFromString(const std::string& source, GLSLShader::GLSLShaderType type) throw (GLSLProgramException);
        void link() throw (GLSLProgramException);
        void use() throw (GLSLProgramException);

        std::string log();

        int getHandle();
        bool isLinked();

        void bindAttribLocation(GLuint location, const char* name);
        void bindFragDataLocation(GLuint location, const char* name);

        void setUniform(const char* name, float x, float y, float z);
        void setUniform(const char* name, float val);
        void setUniform(const char* name, int val);
        void setUniform(const char* name, bool val);
        void printActiveUniforms();
        void printActiveAttribs();
        
};

#endif
