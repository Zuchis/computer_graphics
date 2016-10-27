#include <fstream>
#include <sstream>

#include "GLSLProgram.h"

using std::ifstream;
using std::ios;

GLSLProgram::GLSLProgram(){
    handle = 0;
    linked = false;
}

GLSLProgram::~GLSLProgram(){
    GLint numShaders = 0;
    glGetProgramiv(handle, GL_ATTACHED_SHADERS, &numShaders);

    GLuint * shaderNames = new GLuint[numShaders];
    glGetAttachedShaders(handle, numShaders, NULL, shaderNames);

    // Deleting Shaders
    for (int i = 0; i < numShaders; i++)
        glDeleteShader(shaderNames[i]);

    // Deleting Program
    glDeleteProgram (handle);

    delete[] shaderNames;
}

void GLSLProgram::compileShaderFromFile(const char* fileName, GLSLShader::GLSLShaderType type)
    throw( GLSLProgramException ){
    if( ! fileExists(fileName) ){
        std::string message = std::string("Shader: ") + fileName + " not found.";
        throw GLSLProgramException(message);
    }

    if(handle <= 0 ) {
        handle = glCreateProgram();
        if(handle == 0) {
            throw GLSLProgramException("Unable to create shader program.");
        }
    }

    ifstream inFile( fileName, ios::in );
    if( !inFile ) {
        std::string message = std::string("Unable to open: ") + fileName;
        throw GLSLProgramException(message);
    }

    // Get file contents
    std::stringstream code;
    code << inFile.rdbuf();
    inFile.close();

    std::string source = code.str();
    GLuint shaderHandle = glCreateShader(type);

    const char * c_code = source.c_str();
    glShaderSource(shaderHandle, 1, &c_code, NULL );

    // Compile the shader
    glCompileShader(shaderHandle);

    // Check for errors
    int result;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &result );
    if( GL_FALSE == result ) {
        int length = 0;
        std::string logString;
        glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &length );
        if( length > 0 ) {
            char * c_log = new char[length];
            int written = 0;
            glGetShaderInfoLog(shaderHandle, length, &written, c_log);
            logString = c_log;
            delete [] c_log;
        }
        std::string msg;
        if( fileName ) {
            msg = std::string(fileName) + ": shader compliation failed\n";
        } else {
            msg = "Shader compilation failed.\n";
        }
        msg += logString;

        throw GLSLProgramException(msg);

    } else {
        glAttachShader(handle, shaderHandle);
    }
}

bool GLSLProgram::fileExists( const std::string & fileName ){
    //struct stat info;
    //int ret = -1;

    //ret = stat(fileName.c_str(), &info);
    //return ret == 0;
    
    return true;
}

void GLSLProgram::bindAttribLocation(GLuint location, const char* name){
    glBindAttribLocation(handle, location,name);
}

void GLSLProgram::bindFragDataLocation(GLuint location, const char* name){
    glBindFragDataLocation(handle, location,name);
}

int GLSLProgram::getHandle(){
    return handle;
}

bool GLSLProgram::isLinked(){
    return linked;
}

void GLSLProgram::link() throw(GLSLProgramException){
    if( linked ) return;
    if( handle <= 0 )
        throw GLSLProgramException("Program has not been compiled.");

    glLinkProgram(handle);

    int status = 0;
    glGetProgramiv( handle, GL_LINK_STATUS, &status);
    if( GL_FALSE == status ) {
        //Store log and return false
        int length = 0;
        std::string logString;

        glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length );

        if( length > 0 ) {
            char * c_log = new char[length];
            int written = 0;
            glGetProgramInfoLog(handle, length, &written, c_log);
            logString = c_log;
            delete [] c_log;
        }

        throw GLSLProgramException(std::string("Program link failed:\n") + logString);
    } else {
        //uniformLocations.clear();
        linked = true;
    }
}

void GLSLProgram::use() throw(GLSLProgramException){
    if(handle <= 0 || (! linked))
        throw GLSLProgramException("Shader has not been linked");
    glUseProgram(handle);
}
