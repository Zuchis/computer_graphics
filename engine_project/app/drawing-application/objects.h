#ifndef OBJECTS_H
#define OBJECTS_H

#include "engine.h"

#include "GLSLProgram.h"

namespace Objects{
    class RightTriangle {

        private:

            const int vertCount = 3;
            GLuint VboId[3];
            GLuint VaoId;
            void convertArrays();


        public:

            GLfloat* convertedVertices;
            GLfloat* convertedColors;
            GLuint indices[] = 
            {
                0,1,2
            };

            Vector4[] vertices = { Vector4(0.00, 0.00, 0.0, 1.0),
                                   Vector4(0.25, 0.00, 0.0, 1.0),
                                   Vector4(0.25, 0.50, 0.0, 1.0)};

            Vector4[] colors   = { Vector4(1.0, 0.0, 0.0, 1.0),
                                   Vector4(0.0, 1.0, 0.0, 1.0),
                                   Vector4(0.0, 0.0, 1.0, 1.0)};


            RightTriangle();

            void translate(double xTranslation,double yTranslation);
            void rotate(double angle);
            void scale(double scalingFactor);
            void transform(double xTranslation,double yTranslation, double angle, double scalingFactor);
            void sendDataToBuffers();
            void draw();
    };                                   
};

#endif
