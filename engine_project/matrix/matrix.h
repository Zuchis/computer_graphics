#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

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
        Matrix2 operator * (double k);
        Matrix2 operator / (double k);
        bool operator == (const Matrix2 &m);
        bool operator != (const Matrix2 &m);
        std::vector<double> row(int r);
        std::vector<double> column(int col);
};
#endif
