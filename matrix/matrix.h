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
        
};



#endif
