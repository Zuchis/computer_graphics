#include <iostream>
#include "matrix.h"

int main () {
   Matrix2 m = Matrix2();
   m.print();
   double values[4] = {1,2,3,4};
   Matrix2 n = Matrix2(values);
   n.print();
   std::vector<double> r = n.row(0);
   std::cout << std::endl;

   for(auto i = r.begin(); i != r.end(); i++)
       std::cout << *i << ' ';
   std::cout << std::endl;

   r = n.column(0);
   for(auto i = r.begin(); i != r.end(); i++)
       std::cout << *i << ' ';
   std::cout << std::endl;

   (n.inverted()).print();

   Matrix2 m2 = Matrix2(1,2,3,4);
   m2.print();
   
}
