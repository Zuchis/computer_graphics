#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include "matrix.h"

class MatrixFactory{
    private:

    public:
        static Matrix2 Create2DIdentity();
        static Matrix3 Create3DIdentity();
        static Matrix4 Create4DIdentity();

        static Matrix2 Create2DRotation(double angle);
        static Matrix3 Create3DZRotation(double angle);
        static Matrix3 Create3DYRotation(double angle);
        static Matrix3 Create3DXRotation(double angle);

        static Matrix3 Create3DTranslation(double XTranslation, double YTranslation);
        static Matrix4 Create4DTranslation(double XTranslation, double YTranslation, double ZTranslation);

        static Matrix2 Create2DScalingMatrix(double XFactor, double YFactor);
        static Matrix3 Create3DScalingMatrix(double XFactor, double YFactor, double ZFactor);

        static Matrix3 CONVERT_4D_TO_3D_MATRIX(Matrix4 m);
        static Matrix2 CONVERT_3D_TO_2D_MATRIX(Matrix3 m);

        static Matrix3 CONVERT_2D_TO_3D_MATRIX(Matrix2 m);
        static Matrix4 CONVERT_3D_TO_4D_MATRIX(Matrix3 m);

};




#endif
