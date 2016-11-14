#include <iostream>
#include "engine.h"
#include <cmath>

int main(){
    Vector3 v0 = Vector3(1.0f,0.0f,0.0f);
    Vector3 v1 = Vector3(0.0f,2.0f,0.0f);
    Vector3 v2 = Vector3(0.0f,0.0f,3.0f);
    float angle = 90.0f;

    Matrix3 Rv0 = MatrixFactory::CreateAxisRotation(90.0f,v0);
    Matrix3 Rv1 = MatrixFactory::CreateAxisRotation(90.0f,v1);
    Matrix3 Rv2 = MatrixFactory::CreateAxisRotation(90.0f,v2);

    Rv0.print();
    std::cout << std::endl;
    Rv1.print();
    std::cout << std::endl;
    Rv2.print();

    std::cout << "Rv0 rotations: " << std::endl;
    std::cout << (Rv0 * v0) << std::endl;
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

    std::cout << std::endl;
    std::cout << std::endl;
    Vector3* vectors;// = new Vector3[3];
    Vector3 lul[] = {Vector3(1,0,0), Vector3(0,1,0), Vector3(0,0,1)};
    vectors = lul;
    //vectors[0] = Vector3(1,0,0);
    //vectors[1] = Vector3(0,1,0);
    //vectors[2] = Vector3(0,0,1);
    vectors[0].print();
    Matrix3 _damn = MatrixFactory::Create3DIdentity();
    Matrix4 damn = MatrixFactory::CONVERT_3D_TO_4D_MATRIX(_damn);
    damn.setElement(3,-1.0f);
    damn.print();
    std::cout << std::endl;
    float* son = damn.getData();
    std::cout << son[0] << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    Matrix4 tr = MatrixFactory::CreateTransformMatrix(-0.5f,-0.5f,0.0f,0.0f,1.0f);
    tr.print();
}
