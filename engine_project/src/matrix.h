#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "vector.h"

class Matrix2{
    private:
        double *matrix;
        int width = 2;
        int height = 2;
        int getPosition(int,int) const;

    public:
        Matrix2(){
            matrix = new double[width * height];
            int i, j;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    matrix[i + j * width] = 0.0;
                }
            }
        }

        Matrix2(const Matrix2 &m){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = m.getElement(i,j);
                }
            }
        }

        Matrix2(double values[4]){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = values[j + i * height];
                }
            }
        }

        Matrix2(std::vector<double> values){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = values[j + i * height];
                }
            }
        }

        Matrix2(double a00, double a01,
                double a10, double a11){
            matrix = new double[width * height];
            matrix[0] = a00;
            matrix[1] = a10;
            matrix[2] = a01;
            matrix[3] = a11;
        }

        double getElement(int,int) const;
        void setElement(int,int,double);
        void setElement(int,double);
        Matrix2 copy();
        Matrix2 translated(); 
        double determinant();
        Matrix2 inverted();
        void print();
        
        Matrix2 operator = (Matrix2 m);
        Matrix2 operator + (Matrix2 m);
        Matrix2 operator + (double k);
        Matrix2 operator - (Matrix2 m);
        Matrix2 operator - (double k);
        Matrix2 operator * (Matrix2 m);
        Vector2 operator * (Vector2 v);
        Matrix2 operator * (double k);
        Matrix2 operator / (double k);
        bool operator == (const Matrix2 &m);
        bool operator != (const Matrix2 &m);
        std::vector<double> row(int r);
        std::vector<double> column(int col);
};

class Matrix3{
    private:
        double *matrix;
        int width  = 3;
        int height = 3;
        int getPosition(int,int) const;

    public:
        Matrix3(){
            matrix = new double[width * height];
            int i, j;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    matrix[i + j * width] = 0.0;
                }
            }
        }

        Matrix3(const Matrix3 &m){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = m.getElement(i,j);
                }
            }
        }

        Matrix3(double values[9]){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = values[j + i * height];
                }
            }
        }

        Matrix3(std::vector<double> values){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = values[j + i * height];
                }
            }
        }

        Matrix3(double a00, double a01, double a02,
                double a10, double a11, double a12,
                double a20, double a21, double a22){
            matrix = new double[width * height];
            matrix[0] = a00;
            matrix[1] = a10;
            matrix[2] = a20;
            matrix[3] = a01;
            matrix[4] = a11;
            matrix[5] = a21;
            matrix[6] = a02;
            matrix[7] = a12;
            matrix[8] = a22;
        }

        double getElement(int,int) const;
        void setElement(int,int,double);
        void setElement(int,double);
        Matrix3 copy();
        Matrix3 translated(); 
        double determinant();
        Matrix3 inverted();
        void print();
        
        Matrix3 operator = (Matrix3 m);
        Matrix3 operator + (Matrix3 m);
        Matrix3 operator + (double k);
        Matrix3 operator - (Matrix3 m);
        Matrix3 operator - (double k);
        Matrix3 operator * (Matrix3 m);
        Vector3 operator * (Vector3 v);
        Matrix3 operator * (double k);
        Matrix3 operator / (double k);
        bool operator == (const Matrix3 &m);
        bool operator != (const Matrix3 &m);
        std::vector<double> row(int r);
        std::vector<double> column(int col);
};

class Matrix4{
    private:
        double *matrix;
        int width  = 4;
        int height = 4;
        int getPosition(int,int) const;

    public:
        Matrix3(){
            matrix = new double[width * height];
            int i, j;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    matrix[i + j * width] = 0.0;
                }
            }
        }

        Matrix3(const Matrix3 &m){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = m.getElement(i,j);
                }
            }
        }

        Matrix3(double values[16]){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = values[j + i * height];
                }
            }
        }

        Matrix3(std::vector<double> values){
            matrix = new double[width * height];
            int i, j, index;
            for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                    index = i + j * width;
                    matrix[index] = values[j + i * height];
                }
            }
        }

        Matrix3(double a00, double a01, double a02, double a03,
                double a10, double a11, double a12, double a03,
                double a20, double a21, double a22, double a03,
                double a30, double a31, double a32, double a33){
            matrix = new double[width * height];
            matrix[0]  = a00;
            matrix[1]  = a10;
            matrix[2]  = a20;
            matrix[3]  = a30;
            matrix[4]  = a01;
            matrix[5]  = a11;
            matrix[6]  = a21;
            matrix[7]  = a31;
            matrix[8]  = a02;
            matrix[9]  = a12;
            matrix[10] = a22;
            matrix[11] = a32;
            matrix[12] = a03;
            matrix[13] = a13;
            matrix[14] = a23;
            matrix[15] = a33;
        }

        double getElement(int,int) const;
        void setElement(int,int,double);
        void setElement(int,double);
        Matrix3 copy();
        Matrix3 translated(); 
        double determinant();
        Matrix3 inverted();
        void print();
        
        Matrix3 operator = (Matrix3 m);
        Matrix3 operator + (Matrix3 m);
        Matrix3 operator + (double k);
        Matrix3 operator - (Matrix3 m);
        Matrix3 operator - (double k);
        Matrix3 operator * (Matrix3 m);
        Vector3 operator * (Vector3 v);
        Matrix3 operator * (double k);
        Matrix3 operator / (double k);
        bool operator == (const Matrix3 &m);
        bool operator != (const Matrix3 &m);
        std::vector<double> row(int r);
        std::vector<double> column(int col);
};
#endif
