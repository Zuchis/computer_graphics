#include <iostream>
#include <cmath>
#include "vector.h"

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
    return (x == u.x &&
            y == u.y &&
            z == u.z);
}

bool Vector::operator != (const Vector &u){
    return !(*this == u);
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
    return (x == u.x &&
            y == u.y);
}

bool Vector2::operator != (const Vector2 &u){
    return !(*this == u);
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
