#include <iostream>
#include "matrix.h"

int main() {

    Matrix3 chu = Matrix3(1,2,3,0,1,4,5,6,0);
    std::cout << chu.determinant() << std::endl;
    (chu.inverted()).print();
    return 0;
}



