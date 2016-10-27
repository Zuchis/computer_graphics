//#include <fstream>
//#include <sstream>

#include "shaderprogram.h"
//#include "engine.h"

using std::ifstream;
using std::ios;

ShaderProgram::ShaderProgram(){
    programID = 0;
    linked = false;
}

ShaderProgram::~ShaderProgram(){
    GLint numShaders = 0;
    glGetProgramiv(programID, GL_ATTACHED_SHADERS, &numShaders);

    GLuint * shaderNames = new GLuint[numShaders];
    glGetAttachedShaders(programID, numShaders, NULL, shaderNames);

    // Deleting Shaders
    for (int i = 0; i < numShaders; i++)
        glDeleteShader(shaderNames[i]);

    // Deleting Program
    glDeleteProgram (programID);

    delete[] shaderNames;
}

void ShaderProgram::compileShaderFromFile(const char* fileName, GLSLShader::GLSLShaderType type)
    throw( ShaderProgramException ){
    if(programID <= 0 ) {
        programID = glCreateProgram();
        if(programID == 0) {
            throw ShaderProgramException("Unable to create shader program.");
        }
    }

    ifstream inFile( fileName, ios::in );
    if( !inFile ) {
        std::string message = std::string("Unable to open: ") + fileName;
        throw ShaderProgramException(message);
    }

    // Get file contents
    std::stringstream code;
    code << inFile.rdbuf();
    inFile.close();

    std::string source = code.str();
    GLuint shaderID = glCreateShader(type);

    const char * c_code = source.c_str();
    glShaderSource(shaderID, 1, &c_code, NULL );

    // Compile the shader
    glCompileShader(shaderID);

    // Check for errors
    int result;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result );
    if( GL_FALSE == result ) {
        int length = 0;
        std::string logString;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length );
        if( length > 0 ) {
            char * c_log = new char[length];
            int written = 0;
            glGetShaderInfoLog(shaderID, length, &written, c_log);
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

        throw ShaderProgramException(msg);

    } else {
        glAttachShader(programID, shaderID);
    }
}

void ShaderProgram::bindAttribLocation(GLuint location, const char* name){
    glBindAttribLocation(programID, location,name);
}

void ShaderProgram::bindFragDataLocation(GLuint location, const char* name){
    glBindFragDataLocation(programID, location,name);
}

int ShaderProgram::getProgramID(){
    return programID;
}

bool ShaderProgram::isLinked(){
    return linked;
}

void ShaderProgram::link() throw(ShaderProgramException){
    if( linked ) return;
    if( programID <= 0 )
        throw ShaderProgramException("Program has not been compiled.");

    glLinkProgram(programID);

    int status = 0;
    glGetProgramiv( programID, GL_LINK_STATUS, &status);
    if(status == GL_FALSE) {
        int length = 0;
        std::string logString;

        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length );

        if( length > 0 ) {
            char * c_log = new char[length];
            int written = 0;
            glGetProgramInfoLog(programID, length, &written, c_log);
            logString = c_log;
            delete [] c_log;
        }

        throw ShaderProgramException(std::string("Program link failed:\n") + logString);
    } else {
        //uniformLocations.clear();
        linked = true;
    }
}

void ShaderProgram::use() throw(ShaderProgramException){
    if(programID <= 0 || (! linked))
        throw ShaderProgramException("Shader has not been linked");
    glUseProgram(programID);
}

GLint ShaderProgram::getUniformLocation(const char* name){
    std::unordered_map<std::string,GLint>::iterator it;
    it = uniformIDs.find(name);
    if(it == uniformIDs.end())
        uniformIDs[name] = glGetUniformLocation(programID,name);

    return uniformIDs[name];
}

void ShaderProgram::setUniform(const char* name, float x, float y, float z, float w){
    GLint uniformID = getUniformLocation(name);
    glUniform4f(uniformID,(GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}


void ShaderProgram::setUniform(const char* name, const GLfloat* m){
    GLint uniformID = getUniformLocation(name);
    glUniformMatrix4fv(uniformID,1,GL_FALSE,m);
}

//void ShaderProgram::setUniform(const char* name, const float* m){
    //GLint uniformID = getUniformLocation(name);
    //glUniformMatrix4fv(uniformID,1,GL_FALSE,m);
//}
