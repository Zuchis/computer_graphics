#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include "matrix.h"

int Matrix2::getPosition(int i, int j) const {
    return (i + j * width);
}

double Matrix2::getElement(int i,int j) const {
    int index = getPosition(i, j);
    return matrix[index];
}

void Matrix2::setElement(int i,int j,double value){
    int index = getPosition(i, j);
    matrix[index] = value;
    return;
}

void Matrix2::setElement(int index, double value){
    matrix[index] = value;
    return;
}

Matrix2 Matrix2::operator = (Matrix2 m){
    int i,j,index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            matrix[index] = m.getElement(i,j);
        }
    }
}

Matrix2 Matrix2::copy(){
    Matrix2 copypasta = Matrix2();
    int i,j,index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            copypasta.setElement(index,matrix[index]);
        }
    }
    return copypasta;
}

Matrix2 Matrix2::translated(){
    Matrix2 trans = Matrix2();
    int i,j,index;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            index = getPosition(i,j);
            trans.setElement(i,j,matrix[index]);
        }
    }
}

void Matrix2::print(){
    std::cout << "|";
    int i,j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if(j != width -1)
                std::cout << getElement(i,j) << ", ";
            else
                std::cout << getElement(i,j) << "|" << std::endl;
        }
        if(i != height -1)
            std::cout << "|";
    }
}

Matrix2 Matrix2::operator / (double k) {
    Matrix2 m = Matrix2();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] / k);
        }
    }
    return m;
}

Matrix2 Matrix2::operator * (double k) {
    Matrix2 m = Matrix2();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] * k);
        }
    }
    return m;
}

Matrix2 Matrix2::operator + (double k) {
    Matrix2 m = Matrix2();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] + k);
        }
    }
    return m;
}

Matrix2 Matrix2::operator - (double k) {
    Matrix2 m = Matrix2();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] - k);
        }
    }
    return m;
}

Matrix2 Matrix2::operator + (Matrix2 m2) {
    Matrix2 m = Matrix2();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] + m2.getElement(i,j));
        }
    }
    return m;
}

Matrix2 Matrix2::operator - (Matrix2 m2) {
    Matrix2 m = Matrix2();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] - m2.getElement(i,j));
        }
    }
    return m;
}

double Matrix2::determinant(){
    double a = getElement(0,0);
    double b = getElement(0,1);
    double c = getElement(1,0);
    double d = getElement(1,1);
    return (a * d - b * c);
}

Matrix2 Matrix2::inverted(){
    Matrix2 inv = Matrix2();
    inv.setElement(0,0,getElement(1,1));
    inv.setElement(0,1,getElement(0,1) * -1);
    inv.setElement(1,0,getElement(1,0) * -1);
    inv.setElement(1,1,getElement(0,0));
    return inv / determinant();
}

std::vector<double> Matrix2::row(int r){
    std::vector<double> elements;
    int index, j;
    for (j = 0; j < width; j++) {
        index = getPosition(r,j);
        elements.insert(elements.end(),matrix[index]);
    }
    return elements;
}

std::vector<double> Matrix2::column(int col){
    std::vector<double> elements;
    int i, index;
    for (i = 0; i < height; i++) {
        index = getPosition(i,col);
        elements.insert(elements.end(),matrix[index]);
    }
    return elements;
}


Matrix2 Matrix2::operator * (Matrix2 m){
    Matrix2 mul = Matrix2();
    int i,j,k,index;
    double currentValue = 0.0;
    std::vector<double> r, c;
    std::vector<double>::size_type size_;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            r = row(i);
            c = m.column(j);
            size_ = c.size();
            for (k = 0; k < size_; k++) {
                currentValue += r[k] * c[k];
            }
            index = getPosition(i,j);
            mul.setElement(index,currentValue);
            currentValue = 0.0;
        }
    }
    return mul;
}

Vector2 Matrix2::operator * (Vector2 v){
    Vector2 mul = Vector2();
    int i,j,k,index;
    double currentValue = 0.0;
    mul.x = getElement(0,0) * v.x + getElement(0,1) * v.y;
    mul.y = getElement(1,0) * v.x + getElement(1,1) * v.y;
    return mul;    
}

bool Matrix2::operator == (const Matrix2 &m){
    double eps = std::numeric_limits<double>::epsilon();
    int i,j,index;
    double diff;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            diff = matrix[index] - m.getElement(i,j);
            if(diff < eps && -diff < eps)
                continue;
            else
                return false;
        }
    }
    return true;
}

bool Matrix2::operator != (const Matrix2 &m){
    return !(*this == m);
}

// Matrix 3D Implementations

int Matrix3::getPosition(int i, int j) const {
    return (i + j * width);
}

double Matrix3::getElement(int i,int j) const {
    int index = getPosition(i, j);
    return matrix[index];
}

void Matrix3::setElement(int i,int j,double value){
    int index = getPosition(i, j);
    matrix[index] = value;
    return;
}

void Matrix3::setElement(int index, double value){
    matrix[index] = value;
    return;
}

Matrix3 Matrix3::operator = (Matrix3 m){
    int i,j,index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            matrix[index] = m.getElement(i,j);
        }
    }
}

Matrix3 Matrix3::copy(){
    Matrix3 copypasta = Matrix3();
    int i,j,index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            copypasta.setElement(index,matrix[index]);
        }
    }
    return copypasta;
}

Matrix3 Matrix3::translated(){
    Matrix3 trans = Matrix3();
    int i,j,index;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            index = getPosition(i,j);
            trans.setElement(i,j,matrix[index]);
        }
    }
}

void Matrix3::print(){
    std::cout << "|";
    int i,j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if(j != width -1)
                std::cout << getElement(i,j) << ", ";
            else
                std::cout << getElement(i,j) << "|" << std::endl;
        }
        if(i != height -1)
            std::cout << "|";
    }
}

Matrix3 Matrix3::operator / (double k) {
    Matrix3 m = Matrix3();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] / k);
        }
    }
    return m;
}

Matrix3 Matrix3::operator * (double k) {
    Matrix3 m = Matrix3();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] * k);
        }
    }
    return m;
}

Matrix3 Matrix3::operator + (double k) {
    Matrix3 m = Matrix3();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] + k);
        }
    }
    return m;
}

Matrix3 Matrix3::operator - (double k) {
    Matrix3 m = Matrix3();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] - k);
        }
    }
    return m;
}

Matrix3 Matrix3::operator + (Matrix3 m2) {
    Matrix3 m = Matrix3();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] + m2.getElement(i,j));
        }
    }
    return m;
}

Matrix3 Matrix3::operator - (Matrix3 m2) {
    Matrix3 m = Matrix3();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] - m2.getElement(i,j));
        }
    }
    return m;
}

double Matrix3::determinant(){
    double det = getElement(0, 0) * (getElement(1, 1) * getElement(2, 2) - getElement(2, 1) * getElement(1, 2)) -
                 getElement(0, 1) * (getElement(1, 0) * getElement(2, 2) - getElement(1, 2) * getElement(2, 0)) +
                 getElement(0, 2) * (getElement(1, 0) * getElement(2, 1) - getElement(1, 1) * getElement(2, 0));
    return det;
}

Matrix3 Matrix3::inverted(){
    double det = determinant();
    double inverseDeterminant = 1 / det;

    Matrix3 inverse = Matrix3();
    inverse.setElement(0, 0,((getElement(1, 1) * getElement(2, 2) - getElement(2, 1) * getElement(1, 2)) * inverseDeterminant));
    inverse.setElement(0, 1,((getElement(0, 2) * getElement(2, 1) - getElement(0, 1) * getElement(2, 2)) * inverseDeterminant));
    inverse.setElement(0, 2,((getElement(0, 1) * getElement(1, 2) - getElement(0, 2) * getElement(1, 1)) * inverseDeterminant));
    inverse.setElement(1, 0,((getElement(1, 2) * getElement(2, 0) - getElement(1, 0) * getElement(2, 2)) * inverseDeterminant));
    inverse.setElement(1, 1,((getElement(0, 0) * getElement(2, 2) - getElement(0, 2) * getElement(2, 0)) * inverseDeterminant));
    inverse.setElement(1, 2,((getElement(1, 0) * getElement(0, 2) - getElement(0, 0) * getElement(1, 2)) * inverseDeterminant));
    inverse.setElement(2, 0,((getElement(1, 0) * getElement(2, 1) - getElement(2, 0) * getElement(1, 1)) * inverseDeterminant));
    inverse.setElement(2, 1,((getElement(2, 0) * getElement(0, 1) - getElement(0, 0) * getElement(2, 1)) * inverseDeterminant));
    inverse.setElement(2, 2,((getElement(0, 0) * getElement(1, 1) - getElement(1, 0) * getElement(0, 1)) * inverseDeterminant));

    return inverse;
}

std::vector<double> Matrix3::row(int r){
    std::vector<double> elements;
    int index, j;
    for (j = 0; j < width; j++) {
        index = getPosition(r,j);
        elements.insert(elements.end(),matrix[index]);
    }
    return elements;
}

std::vector<double> Matrix3::column(int col){
    std::vector<double> elements;
    int i, index;
    for (i = 0; i < height; i++) {
        index = getPosition(i,col);
        elements.insert(elements.end(),matrix[index]);
    }
    return elements;
}


Matrix3 Matrix3::operator * (Matrix3 m){
    Matrix3 mul = Matrix3();
    int i,j,k,index;
    double currentValue = 0.0;
    std::vector<double> r, c;
    std::vector<double>::size_type size_;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            r = row(i);
            c = m.column(j);
            size_ = c.size();
            for (k = 0; k < size_; k++) {
                currentValue += r[k] * c[k];
            }
            index = getPosition(i,j);
            mul.setElement(index,currentValue);
            currentValue = 0.0;
        }
    }
    return mul;
}

Vector3 Matrix3::operator * (Vector3 v){
    Vector3 mul = Vector3();
    int i,j,k,index;
    mul.x = getElement(0,0) * v.x + getElement(0,1) * v.y + getElement(0,2) * v.z;
    mul.y = getElement(1,0) * v.x + getElement(1,1) * v.y + getElement(1,2) * v.z;
    mul.z = getElement(2,0) * v.x + getElement(2,1) * v.y + getElement(2,2) * v.z;
    return mul;    
}

bool Matrix3::operator == (const Matrix3 &m){
    double eps = std::numeric_limits<double>::epsilon();
    int i,j,index;
    double diff;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            diff = matrix[index] - m.getElement(i,j);
            if(diff < eps && -diff < eps)
                continue;
            else
                return false;
        }
    }
    return true;
}

bool Matrix3::operator != (const Matrix3 &m){
    return !(*this == m);
}

// Matrix 4D Implementations

int Matrix4::getPosition(int i, int j) const {
    return (i + j * width);
}

double Matrix4::getElement(int i,int j) const {
    int index = getPosition(i, j);
    return matrix[index];
}

void Matrix4::setElement(int i,int j,double value){
    int index = getPosition(i, j);
    matrix[index] = value;
    return;
}

void Matrix4::setElement(int index, double value){
    matrix[index] = value;
    return;
}

Matrix4 Matrix4::operator = (Matrix4 m){
    int i,j,index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            matrix[index] = m.getElement(i,j);
        }
    }
}

Matrix4 Matrix4::copy(){
    Matrix4 copypasta = Matrix4();
    int i,j,index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            copypasta.setElement(index,matrix[index]);
        }
    }
    return copypasta;
}

Matrix4 Matrix4::translated(){
    Matrix4 trans = Matrix4();
    int i,j,index;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            index = getPosition(i,j);
            trans.setElement(i,j,matrix[index]);
        }
    }
}

void Matrix4::print(){
    std::cout << "|";
    int i,j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if(j != width -1)
                std::cout << getElement(i,j) << ", ";
            else
                std::cout << getElement(i,j) << "|" << std::endl;
        }
        if(i != height -1)
            std::cout << "|";
    }
}

Matrix4 Matrix4::operator / (double k) {
    Matrix4 m = Matrix4();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] / k);
        }
    }
    return m;
}

Matrix4 Matrix4::operator * (double k) {
    Matrix4 m = Matrix4();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] * k);
        }
    }
    return m;
}

Matrix4 Matrix4::operator + (double k) {
    Matrix4 m = Matrix4();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] + k);
        }
    }
    return m;
}

Matrix4 Matrix4::operator - (double k) {
    Matrix4 m = Matrix4();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] - k);
        }
    }
    return m;
}

Matrix4 Matrix4::operator + (Matrix4 m2) {
    Matrix4 m = Matrix4();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] + m2.getElement(i,j));
        }
    }
    return m;
}

Matrix4 Matrix4::operator - (Matrix4 m2) {
    Matrix4 m = Matrix4();
    int i, j, index;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            m.setElement(index,matrix[index] - m2.getElement(i,j));
        }
    }
    return m;
}

std::vector<double> Matrix4::row(int r){
    std::vector<double> elements;
    int index, j;
    for (j = 0; j < width; j++) {
        index = getPosition(r,j);
        elements.insert(elements.end(),matrix[index]);
    }
    return elements;
}

std::vector<double> Matrix4::column(int col){
    std::vector<double> elements;
    int i, index;
    for (i = 0; i < height; i++) {
        index = getPosition(i,col);
        elements.insert(elements.end(),matrix[index]);
    }
    return elements;
}


Matrix4 Matrix4::operator * (Matrix4 m){
    Matrix4 mul = Matrix4();
    int i,j,k,index;
    double currentValue = 0.0;
    std::vector<double> r, c;
    std::vector<double>::size_type size_;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            r = row(i);
            c = m.column(j);
            size_ = c.size();
            for (k = 0; k < size_; k++) {
                currentValue += r[k] * c[k];
            }
            index = getPosition(i,j);
            mul.setElement(index,currentValue);
            currentValue = 0.0;
        }
    }
    return mul;
}

//Vector4 Matrix4::operator * (Vector4 v){
    //Vector3 mul = Vector3();
    //int i,j,k,index;
    //mul.x = getElement(0,0) * v.x + getElement(0,1) * v.y + getElement(0,2) * v.z;
    //mul.y = getElement(1,0) * v.x + getElement(1,1) * v.y + getElement(1,2) * v.z;
    //mul.z = getElement(2,0) * v.x + getElement(2,1) * v.y + getElement(2,2) * v.z;
    //return mul;    
//}

bool Matrix4::operator == (const Matrix4 &m){
    double eps = std::numeric_limits<double>::epsilon();
    int i,j,index;
    double diff;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = getPosition(i,j);
            diff = matrix[index] - m.getElement(i,j);
            if(diff < eps && -diff < eps)
                continue;
            else
                return false;
        }
    }
    return true;
}

bool Matrix4::operator != (const Matrix4 &m){
    return !(*this == m);
}
