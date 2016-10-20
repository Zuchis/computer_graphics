#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include "matrix.h"

class MatrixFactory{
    private:

    public:
        static Matrix2 Create2DIdentity();
        static Matrix3 Create3DIdentity();
        static Matrix4 Create4DIdentity();

};




#endif
