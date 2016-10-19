#include <iostream>
#include "matrix.h"

int main() {

    Matrix3 chu = Matrix3(1,2,4,3,4,4,2,1,2);
    std::cout << chu.determinant() << std::endl;
    return 0;
}



