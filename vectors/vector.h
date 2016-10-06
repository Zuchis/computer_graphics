#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    private:

    public:
        double x, y, z;

        Vector(double x1 = 0, double y1 = 0, double z1 = 0){
            x = x1;
            y = y1;
            z = z1;
        }

        Vector operator + (Vector v);
        Vector operator + (double k);
        Vector operator - (Vector v);
        Vector operator - (double k);
        Vector operator / (double k);
        Vector operator * (double k);
        Vector operator = (Vector v);
        bool operator == (const Vector &u);
        bool operator != (const Vector &u);
        double dot (Vector v);
        double norm();
        Vector copy();
        Vector cross(Vector v);
        void normalize();
        void print();
};

#endif
