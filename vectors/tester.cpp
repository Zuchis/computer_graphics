#include <iostream>
#include "vector.h"

int main (){
    Vector v = Vector(2.0,4.0,6.0);
    Vector u = Vector(1.0,3.0,5.0);

    Vector s = v + u;

    std::cout << "the value of s is: ";
    s.print();

    if (v == u){
        std::cout << "v and u are equal" << std::endl;
    }

    if (v != u){
        std::cout << "v and u are not equal" << std::endl;
    }

    return 0;
}
