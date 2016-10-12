#ifndef MATRIX_H
#define MATRIX_H

class Matrix2{
    private:
        double *matrix;
        int width = 2;
        int height = 2;

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

        int getPosition(int,int);
        double getElement(int,int);
        void setElement(int,int,double);
        void setElement(int,double);
        Matrix2 copy();
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
};
#endif
