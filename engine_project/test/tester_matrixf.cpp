#include <iostream>
#include "matrixfactory.h"

int main(){
    Matrix2 m = MatrixFactory::Create2DIdentity();
    m.print();

    Matrix2 rot = MatrixFactory::Create2DRotation(90.0);
    rot.print();
    
    Vector2 v = Vector2(2,3);
    v = rot * v;
    v.print();

    return 0;
}
