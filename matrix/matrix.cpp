#include <iostream>
#include <cmath>
#include "matrix.h"

int Matrix2::getPosition(int i, int j){
    return (i + j * width);
}

double Matrix2::getElement(int i,int j){
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

Matrix2 Matrix2::operator = (const Matrix2 &m){
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

}

Matrix2 translated(); 
Matrix2 inverted();

Matrix2 operator = (Matrix2 m);
Matrix2 operator + (Matrix2 m);
Matrix2 operator - (Matrix2 m);
Matrix2 operator * (Matrix2 m);
Matrix2 operator * (double k);
Matrix2 operator / (double k);
bool operator == (const Matrix2 &m);
bool operator != (const Matrix2 &m);
