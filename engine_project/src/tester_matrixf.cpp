#include <iostream>
#include "matrixfactory.h"

int main(){
    Matrix2 m = MatrixFactory::Create2DIdentity();
    m.print();
    return 0;
}
