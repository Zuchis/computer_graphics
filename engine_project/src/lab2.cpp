#include <iostream>
#include "matrixfactory.h"
#include <cmath>

//Matrix3 operator * (double k, const Matrix3 &m1) {
    //int height = 3;
    //int width =  3;
    //Matrix3 m = Matrix3();
    //int i, j, index;
    //for (i = 0; i < height; i++) {
        //for (j = 0; j < width; j++) {
            //m.setElement(i,j,m1.getElement(i,j) * k);
        //}
    //}
    //return m;
//}


int main(){
    Vector3 v0 = Vector3(1,0,0);
    Vector3 v1 = Vector3(0,2,0);
    Vector3 v2 = Vector3(0,0,3);
    double angle = 90.0;

    Matrix3 Rv0 = MatrixFactory::CreateAxisRotation(90,v0);
    Matrix3 Rv1 = MatrixFactory::CreateAxisRotation(90,v1);
    Matrix3 Rv2 = MatrixFactory::CreateAxisRotation(90,v2);

    Rv0.print();
    std::cout << std::endl;
    Rv1.print();
    std::cout << std::endl;
    Rv2.print();

    std::cout << "Rv0 rotations: " << std::endl;
    (Rv0 * v0).print();
    (Rv0 * v1).print();
    (Rv0 * v2).print();
    
    std::cout << "Rv1 rotations: " << std::endl;
    (Rv1 * v0).print();
    (Rv1 * v1).print();
    (Rv1 * v2).print();

    std::cout << "Rv2 rotations: " << std::endl;
    (Rv2 * v0).print();
    (Rv2 * v1).print();
    (Rv2 * v2).print();
}
