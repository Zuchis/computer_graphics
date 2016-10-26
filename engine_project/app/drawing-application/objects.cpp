#include "objects.h"

namespace Objects{
    RightTriangle::RightTriangle(){
        convertedVertices = new GLfloat[vertCount * 4];
        convertedColors   = new GLfloat[vertCount * 4];
	glGenVertexArrays(1, &VaoId);
    }

};
