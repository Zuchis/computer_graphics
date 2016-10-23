#include <iostream>
#include <cmath>
#include <limits>
#include "vector.h"


Vector3 Vector3::operator + (Vector3 v){
    return Vector3(x + v.x,
                    y + v.y,
                    z + v.z);
}

Vector3 Vector3::operator + (double k){
    return Vector3(x + k,
                    y + k,
                    z + k);
}

Vector3 Vector3::operator - (Vector3 v){
    return Vector3(x - v.x,
                    y - v.y,
                    z - v.z);
}

Vector3 Vector3::operator - (double k){
    return Vector3(x - k,
                    y - k,
                    z - k);
}

Vector3 Vector3::operator / (double k){
    return Vector3(x / k,
                    y / k,
                    z / k);
}

Vector3 Vector3::operator * (double k){
    return Vector3(x * k,
                    y * k,
                    z * k);
}

Vector3 Vector3::operator * (Matrix3 m){
    Vector3 mul = Vector3();
    mul.x = m.getElement(0,0) * x + m.getElement(1,0) * y + m.getElement(2,0) * z;
    mul.y = m.getElement(0,1) * x + m.getElement(1,1) * y + m.getElement(2,1) * z;
    mul.z = m.getElement(0,2) * x + m.getElement(1,2) * y + m.getElement(2,2) * z;
    return mul;    
}

Vector3 Vector3::operator = (Vector3 v){
    x = v.x;
    y = v.y;
    z = v.z;
}

bool Vector3::operator == (const Vector3 &u){
    double eps = std::numeric_limits<double>::epsilon();
    double diff1 = x - u.x;
    double diff2 = y - u.y;
    double diff3 = z - u.z;
    return ((diff1 < eps && -diff1 < eps) &&
            (diff2 < eps && -diff2 < eps) &&
            (diff3 < eps && -diff3 < eps));
}

bool Vector3::operator != (const Vector3 &u){
    return !(*this == u);
}

void Vector3::operator += (Vector3 v){
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector3::operator += (double k){
    x += k;
    y += k;
    z += k;
}

void Vector3::operator -= (Vector3 v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3::operator -= (double k){
    x -= k;
    y -= k;
    z -= k;
}

void Vector3::operator *= (double k){
    x *= k;
    y *= k;
    z *= k;
}

void Vector3::operator /= (double k){
    x /= k;
    y /= k;
    z /= k;
}

double Vector3::norm(){
    return sqrt(x * x + y * y + z * z);
}

double Vector3::quadrance(){
    return (x * x + y * y + z * z);

}

Vector3 Vector3::copy(){
    return Vector3(x, y, z);
}

void Vector3::normalize(){
    *this = *this / norm();
    return;
}

Vector3 Vector3::normalized(){
    Vector3 u = copy();
    u.normalize();
    return u;
}

double Vector3::dot (Vector3 v){
    return (x * v.x +
            y * v.y +
            z * v.z);
}

Vector3 Vector3::cross (Vector3 v){
    return Vector3(y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}

void Vector3::clean(){
    double small = 1.0e-15;
    if (x < small && -x < small)
        x = 0.0;
    if (y < small && -y < small)
        y = 0.0;
    if (z < small && -z < small)
        z = 0.0;
}

void Vector3::print(){
    clean();
    std::cout << "( " << x << ", " << y << ", " << z << " )" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Vector3& v){
    v.clean();
    os << "( " << v.x << ", " << v.y << ", " << v.z << " )";
    return os;
}

// Vector 2D Implementations

Vector2 Vector2::operator + (Vector2 v){
    return Vector2(x + v.x,
                    y + v.y);
}

Vector2 Vector2::operator + (double k){
    return Vector2(x + k,
                    y + k);
}

Vector2 Vector2::operator - (Vector2 v){
    return Vector2(x - v.x,
                    y - v.y);
}

Vector2 Vector2::operator - (double k){
    return Vector2(x - k,
                    y - k);
}

Vector2 Vector2::operator / (double k){
    return Vector2(x / k,
                    y / k);
}

Vector2 Vector2::operator * (double k){
    return Vector2(x * k,
                    y * k);
}

Vector2 Vector2::operator * (Matrix2 m){
    Vector2 mul = Vector2();
    mul.x = m.getElement(0,0) * x + m.getElement(1,0) * y;
    mul.y = m.getElement(0,1) * x + m.getElement(1,1) * y;
    return mul;    
}

Vector2 Vector2::operator = (Vector2 v){
    x = v.x;
    y = v.y;
}

bool Vector2::operator == (const Vector2 &u){
    double eps = std::numeric_limits<double>::epsilon();
    double diff1 = x - u.x;
    double diff2 = y - u.y;
    return ((diff1 < eps && -diff1 < eps) &&
            (diff2 < eps && -diff2 < eps));
}

bool Vector2::operator != (const Vector2 &u){
    return !(*this == u);
}

void Vector2::operator += (Vector2 v){
    x += v.x;
    y += v.y;
}

void Vector2::operator += (double k){
    x += k;
    y += k;
}

void Vector2::operator -= (Vector2 v){
    x -= v.x;
    y -= v.y;
}

void Vector2::operator -= (double k){
    x -= k;
    y -= k;
}

void Vector2::operator *= (double k){
    x *= k;
    y *= k;
}

void Vector2::operator /= (double k){
    x /= k;
    y /= k;
}

double Vector2::norm(){
    return sqrt(x * x + y * y);
}

double Vector2::quadrance(){
    return (x * x + y * y);

}

Vector2 Vector2::copy(){
    return Vector2(x, y);
}

void Vector2::normalize(){
    *this = *this / norm();
    return;
}

Vector2 Vector2::normalized(){
    Vector2 u = copy();
    u.normalize();
    return u;
}

double Vector2::dot (Vector2 v){
    return (x * v.x +
            y * v.y);
}

void Vector2::clean(){
    double small = 1.0e-15;
    if (x < small && -x < small)
        x = 0.0;
    if (y < small && -y < small)
        y = 0.0;
}

void Vector2::print(){
    clean();
    std::cout << "( " << x << ", " << y << " )" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Vector2& v){
    v.clean();
    os << "( " << v.x << ", " << v.y  << " )";
    return os;
}

// Vector 4 Implementations

Vector4 Vector4::operator + (Vector4 v){
    return Vector4( x + v.x,
                    y + v.y,
                    z + v.z,
                    w + v.w);
}

Vector4 Vector4::operator + (double k){
    return Vector4( x + k,
                    y + k,
                    z + k,
                    w + k);
}

Vector4 Vector4::operator - (Vector4 v){
    return Vector4(x - v.x,
                   y - v.y,
                   z - v.z,
                   w - v.w);
}

Vector4 Vector4::operator - (double k){
    return Vector4(x - k,
                   y - k,
                   z - k,
                   w - k);
}

Vector4 Vector4::operator / (double k){
    return Vector4(x / k,
                   y / k,
                   z / k,
                   w / k);
}

Vector4 Vector4::operator * (double k){
    return Vector4(x * k,
                   y * k,
                   z * k,
                   w * k);
}

Vector4 Vector4::operator * (Matrix4 m){
    Vector4 mul = Vector4();
    mul.x = m.getElement(0,0) * x + m.getElement(1,0) * y + m.getElement(2,0) * z + m.getElement(3,0) * w;
    mul.y = m.getElement(0,1) * x + m.getElement(1,1) * y + m.getElement(2,1) * z + m.getElement(3,1) * w;
    mul.z = m.getElement(0,2) * x + m.getElement(1,2) * y + m.getElement(2,2) * z + m.getElement(3,2) * w;
    mul.w = m.getElement(0,3) * x + m.getElement(1,3) * y + m.getElement(2,3) * z + m.getElement(3,3) * w;
    return mul;    
}

Vector4 Vector4::operator = (Vector4 v){
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

bool Vector4::operator == (const Vector4 &u){
    double eps = std::numeric_limits<double>::epsilon();
    double diff1 = x - u.x;
    double diff2 = y - u.y;
    double diff3 = z - u.z;
    double diff4 = w - u.w;
    return ((diff1 < eps && -diff1 < eps) &&
            (diff2 < eps && -diff2 < eps) &&
            (diff3 < eps && -diff3 < eps) && 
            (diff4 < eps && -diff4 < eps));
}

bool Vector4::operator != (const Vector4 &u){
    return !(*this == u);
}

void Vector4::operator += (Vector4 v){
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
}

void Vector4::operator += (double k){
    x += k;
    y += k;
    z += k;
    w += k;
}

void Vector4::operator -= (Vector4 v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
}

void Vector4::operator -= (double k){
    x -= k;
    y -= k;
    z -= k;
    w -= k;
}

void Vector4::operator *= (double k){
    x *= k;
    y *= k;
    z *= k;
    w *= k;
}

void Vector4::operator /= (double k){
    x /= k;
    y /= k;
    z /= k;
    w /= k;
}

double Vector4::norm(){
    return sqrt(x * x + y * y + z * z + w * w);
}

double Vector4::quadrance(){
    return (x * x + y * y + z * z + w * w);

}

Vector4 Vector4::copy(){
    return Vector4(x, y, z, w);
}

void Vector4::normalize(){
    *this = *this / norm();
    return;
}

Vector4 Vector4::normalized(){
    Vector4 u = copy();
    u.normalize();
    return u;
}

double Vector4::dot (Vector4 v){
    return (x * v.x +
            y * v.y +
            z * v.z +
            w * v.w);
}

void Vector4::clean(){
    double small = 1.0e-15;
    if (x < small && -x < small)
        x = 0.0;
    if (y < small && -y < small)
        y = 0.0;
    if (z < small && -z < small)
        z = 0.0;
    if (w < small && -w < small)
        w = 0.0;
}

void Vector4::print(){
    clean();
    std::cout << "( " << x << ", " << y << ", " << z << ", " << w << " )" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Vector4& v){
    v.clean();
    os << "( " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " )";
    return os;
}
