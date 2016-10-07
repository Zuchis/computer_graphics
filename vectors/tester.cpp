#include <iostream>
#include "vector.h"

int main (){
    Vector v = Vector(2.0,4.0,6.0);
    Vector u = Vector(1.0,3.0,5.0);

    Vector s = v + u;
    Vector *w = new Vector();

    std::cout << "v: ";
    v.print();
    std::cout << "u: ";
    u.print();

    std::cout << "the value of s is v + u, which is: ";
    s.print();

    if (v == u){
        std::cout << "v and u are equal" << std::endl;
    }

    if (v != u){
        std::cout << "Testing v != u: ";
        std::cout << "v and u are not equal" << std::endl;
    }

    *w = s.copy();
    std::cout << "w is a copy of s: ";
    w->print();

    std::cout << "s - 1: ";
    (s - 1).print();

    std::cout << "s + 1: ";
    (s + 1).print();

    std::cout << "s * 2: ";
    (s * 2).print();

    std::cout << "s / 2: ";
    (s / 2).print();

    std::cout << std::endl;

    std::cout << "s - u: ";
    (s - u).print();

    std::cout << "v's norm: " << v.norm() << std::endl;

    std::cout << "v normalized: ";
    v.normalized().print();

    std::cout << "v dot u: " << v.dot(u) << std::endl;

    std::cout << "v cross u: ";
    (v.cross(u)).print();


    delete w;
        
    return 0;
}
