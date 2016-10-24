namespace GLSLShader {
    enum GLSLShaderType{
        VERTEX,FRAGMENT
    };
};

class GLSLProgram {
    private:
        int handle;
        bool linked;
        std::string logString;
        int getUniformLocation(const char* name);
        bool fileExists (const std::string& fileName);

    public:
        GLSLProgram();

        bool compileShaderFromFile(const char* fileName, GLSLShader::GLSLShaderType type);
        bool compileShaderFromString(const std::string& source, GLSLShader::GLSLShaderType type);
        bool link();
        void use();

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
