#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

class Matrix2;
class Matrix3;
class Matrix4;

class Vector3{
    private:

    public:
        double x, y, z;

        Vector3(double x1 = 0, double y1 = 0, double z1 = 0){
            x = x1;
            y = y1;
            z = z1;
        }

        Vector3(const Vector3 &v){
            x = v.x;
            y = v.y;
            z = v.z;
        }

        Vector3 operator + (Vector3 v);
        Vector3 operator + (double k);
        Vector3 operator - (Vector3 v);
        Vector3 operator - (double k);
        Vector3 operator / (double k);
        Vector3 operator * (double k);
        Vector3 operator * (Matrix3 m);
        Vector3 operator = (Vector3 v);
        bool operator == (const Vector3 &u);
        bool operator != (const Vector3 &u);
        void operator += (Vector3 v);
        void operator += (double k);
        void operator -= (double k);
        void operator -= (Vector3 v);
        void operator *= (double k);
        void operator /= (double k);
        double dot (Vector3 v);
        double norm();
        double quadrance();
        Vector3 copy();
        Vector3 cross(Vector3 v);
        void normalize();
        Vector3 normalized();
        void clean();
        void print();
};


class Vector2{
    private:

    public:
        double x, y;

        Vector2(double x1 = 0, double y1 = 0){
            x = x1;
            y = y1;
        }

        Vector2(const Vector2 &v){
            x = v.x;
            y = v.y;
        }

        Vector2 operator + (Vector2 v);
        Vector2 operator + (double k);
        Vector2 operator - (Vector2 v);
        Vector2 operator - (double k);
        Vector2 operator / (double k);
        Vector2 operator * (double k);
        Vector2 operator * (Matrix2 m);
        Vector2 operator = (Vector2 v);
        bool operator == (const Vector2 &u);
        bool operator != (const Vector2 &u);
        void operator += (Vector2 v);
        void operator += (double k);
        void operator -= (double k);
        void operator -= (Vector2 v);
        void operator *= (double k);
        void operator /= (double k);
        double norm();
        Vector2 copy();
        double dot (Vector2 v);
        double quadrance();
        void normalize();
        Vector2 normalized();
        void clean();
        void print();
};

class Vector4{
    private:

    public:
        double x, y, z, w;

        Vector4(double x1 = 0, double y1 = 0, double z1 = 0, double w1 = 0){
            x = x1;
            y = y1;
            z = z1;
            w = w1;
        }

        Vector4(const Vector4 &v){
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }

        Vector4 operator + (Vector4 v);
        Vector4 operator + (double k);
        Vector4 operator - (Vector4 v);
        Vector4 operator - (double k);
        Vector4 operator / (double k);
        Vector4 operator * (double k);
        Vector4 operator * (Matrix4 m);
        Vector4 operator = (Vector4 v);
        bool operator == (const Vector4 &u);
        bool operator != (const Vector4 &u);
        void operator += (Vector4 v);
        void operator += (double k);
        void operator -= (double k);
        void operator -= (Vector4 v);
        void operator *= (double k);
        void operator /= (double k);
        double dot (Vector4 v);
        double norm();
        double quadrance();
        Vector4 copy();
        void normalize();
        Vector4 normalized();
        void clean();
        void print();
};

#endif
