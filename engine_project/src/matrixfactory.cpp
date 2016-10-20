#include <iostream>
#include "matrixfactory.h"

Matrix2 MatrixFactory::Create2DIdentity(){
    Matrix2 identity = Matrix2(1,0,0,1);
    return identity;
}

Matrix3 MatrixFactory::Create3DIdentity(){
    Matrix3 identity = Matrix3(1,0,0,0,1,0,0,0,1);
    return identity;
}

Matrix4 MatrixFactory::Create4DIdentity(){
    Matrix4 identity = Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
    return identity;
}
