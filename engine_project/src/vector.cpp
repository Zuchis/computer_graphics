#include <iostream>
#include <cmath>
#include <limits>
#include "vector.h"

//std::ostream& operator << (std::ostream& os, const Vector& v){
    //os << "( " << v.x << ", " << v.y << ", " << v.z << " )";
    //return os;
//}

Vector Vector::operator + (Vector v){
    return Vector(x + v.x,
                    y + v.y,
                    z + v.z);
}

Vector Vector::operator + (double k){
    return Vector(x + k,
                    y + k,
                    z + k);
}

Vector Vector::operator - (Vector v){
    return Vector(x - v.x,
                    y - v.y,
                    z - v.z);
}

Vector Vector::operator - (double k){
    return Vector(x - k,
                    y - k,
                    z - k);
}

Vector Vector::operator / (double k){
    return Vector(x / k,
                    y / k,
                    z / k);
}

Vector Vector::operator * (double k){
    return Vector(x * k,
                    y * k,
                    z * k);
}

Vector Vector::operator = (Vector v){
    x = v.x;
    y = v.y;
    z = v.z;
}

bool Vector::operator == (const Vector &u){
    double eps = std::numeric_limits<double>::epsilon();
    double diff1 = x - u.x;
    double diff2 = y - u.y;
    double diff3 = z - u.z;
    return ((diff1 < eps && -diff1 < eps) &&
            (diff2 < eps && -diff2 < eps) &&
            (diff3 < eps && -diff3 < eps));
}

bool Vector::operator != (const Vector &u){
    return !(*this == u);
}

void Vector::operator += (Vector v){
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector::operator += (double k){
    x += k;
    y += k;
    z += k;
}

void Vector::operator -= (Vector v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector::operator -= (double k){
    x -= k;
    y -= k;
    z -= k;
}

void Vector::operator *= (double k){
    x *= k;
    y *= k;
    z *= k;
}

void Vector::operator /= (double k){
    x /= k;
    y /= k;
    z /= k;
}

double Vector::norm(){
    return sqrt(x * x + y * y + z * z);
}

double Vector::quadrance(){
    return (x * x + y * y + z * z);

}

Vector Vector::copy(){
    return Vector(x, y, z);
}

void Vector::normalize(){
    *this = *this / norm();
    return;
}

Vector Vector::normalized(){
    Vector u = copy();
    u.normalize();
    return u;
}

double Vector::dot (Vector v){
    return (x * v.x +
            y * v.y +
            z * v.z);
}

Vector Vector::cross (Vector v){
    return Vector(y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}

void Vector::print(){
    std::cout << "( " << x << ", " << y << ", " << z << " )" << std::endl;
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

void Vector2::print(){
    std::cout << "( " << x << ", " << y << " )" << std::endl;
}
