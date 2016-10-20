#include <iostream>
#include "matrixfactory.h"
#include <cmath>

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

Matrix2 MatrixFactory::Create2DRotation(double angle){
    double radToDegree = (M_PI * angle) / 180;
    double sin0 = sin(radToDegree);
    double cos0 = cos(radToDegree);
    Matrix2 rot = Matrix2(cos0,sin0 * -1, sin0, cos0);
    return rot;
}

Matrix3 MatrixFactory::Create3DZRotation(double angle){
    double radToDegree = (M_PI * angle) / 180;
    double sin0 = sin(radToDegree);
    double cos0 = cos(radToDegree);
    Matrix3 rot = Matrix3(cos0,sin0 * -1,0,sin0,cos0,0,0,0,1);
    return rot;
}

Matrix3 MatrixFactory::Create3DYRotation(double angle){
    double radToDegree = (M_PI * angle) / 180;
    double sin0 = sin(radToDegree);
    double cos0 = cos(radToDegree);
    Matrix3 rot = Matrix3(cos0,0,sin0,0,1,0,sin0 * -1,0,cos0);
    return rot;
}

Matrix3 MatrixFactory::Create3DXRotation(double angle){
    double radToDegree = (M_PI * angle) / 180;
    double sin0 = sin(radToDegree);
    double cos0 = cos(radToDegree);
    Matrix3 rot = Matrix3(1,0,0,0,cos0,sin0 * -1,0,sin0,cos0);
    return rot;
}

Matrix3 MatrixFactory::Create3DTranslation(double XTranslation, double YTranslation){
    Matrix3 trans = Matrix3(1,0,XTranslation,0,1,YTranslation,0,0,1);
    return trans;
}

Matrix4 MatrixFactory::Create4DTranslation(double XTranslation, double YTranslation, double ZTranslation){
    Matrix4 trans = Matrix4(1,0,0,XTranslation,0,1,0,YTranslation,0,0,1,ZTranslation,0,0,0,1);
    return trans;
}

Matrix2 MatrixFactory::Create2DScalingMatrix(double XFactor, double YFactor){
    Matrix2 scale = Matrix2(XFactor,0,0,YFactor);
    return scale;
}

Matrix3 MatrixFactory::Create3DScalingMatrix(double XFactor, double YFactor, double ZFactor){
    Matrix3 scale = Matrix3(XFactor,0,0,0,YFactor,0,0,0,ZFactor);
    return scale;
}

Matrix3 MatrixFactory::CONVERT_4D_TO_3D_MATRIX(Matrix4 m){
    int i,j;
    int height = 3;
    int width  = 3;
    Matrix3 converted = Matrix3();
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            converted.setElement(i,j,m.getElement(i,j));
        }
    }
    return converted;
}

Matrix2 MatrixFactory::CONVERT_3D_TO_2D_MATRIX(Matrix3 m){
    int i,j;
    int height = 2;
    int width  = 2;
    Matrix2 converted = Matrix2();
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            converted.setElement(i,j,m.getElement(i,j));
        }
    }
    return converted;
}

Matrix3 CONVERT_2D_TO_3D_MATRIX(Matrix2 m){
    int i,j;
    int height = 2;
    int width  = 2;
    Matrix3 converted = Matrix3();
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            converted.setElement(i,j,m.getElement(i,j));
        }
    }
    converted.setElement(2,2,1.0);
    return converted;
}

Matrix4 CONVERT_3D_TO_4D_MATRIX(Matrix3 m){
    int i,j;
    int height = 3;
    int width  = 3;
    Matrix4 converted = Matrix4();
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            converted.setElement(i,j,m.getElement(i,j));
        }
    }
    converted.setElement(3,3,1.0);
    return converted;
}
