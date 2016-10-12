#include <iostream>
#include <cmath>
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

Matrix2 operator / (double k) {
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

Matrix2 operator * (double k) {
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

Matrix2 operator * (double k) {
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

Matrix2 operator + (double k) {
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

Matrix2 operator - (double k) {
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

Matrix2 operator + (Matrix2 m2) {
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

Matrix2 operator - (Matrix2 m2) {
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

Matrix2 inverted(){
    Matrix2 inv = Matrix2();
    inv.setElement(0,0,getElement(1,1));
    inv.setElement(0,1,getElement(0,1) * -1);
    inv.setElement(1,0,getElement(1,0) * -1);
    inv.setElement(1,1,getElement(0,0));
    return inv / determinant();
}

//Matrix2 operator * (Matrix2 m);
//Matrix2 operator * (double k);
//bool operator == (const Matrix2 &m);
//bool operator != (const Matrix2 &m);
