#include <iostream>
#include "matrix.h"

int main () {
   Matrix2 m = Matrix2();
   m.print();
   double values[4] = {1,2,3,4};
   Matrix2 n = Matrix2(values);
   n.print();
}
