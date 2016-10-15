#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>

//typedef std::rand() randInt;

double randomF(){
    return ((double)std::rand() / (double)RAND_MAX);
}

int main(int argc, const char *argv[])
{
    std::srand(std::time(0));
    Vector a, b, c, o1, o2;
    int i;
    for(i = 0; i < 10; i++){
        std::cout << std::endl;
        std::cout << "i: ";
        a = Vector(randomF(),randomF(),randomF());
        a.print();
        std::cout << "\nj: ";
        b = Vector(randomF(),randomF(),randomF());
        b.print();
        std::cout << "\nk: ";
        c = Vector(randomF(),randomF(),randomF());
        c.print();

        std::cout << "\n i x (j x k) = j (i.k) - k (i.j) " << std::endl;
        o1 = (a.cross(b.cross(c)));
        o1.print();
        std::cout << " = ";
        o2 = (b * (a.dot(c)) - c * (a.dot(b)));
        o2.print();
        std::cout << std::endl;
        std::cout << std::endl;
        if (o1 != o2)
            break;
    }

    return 0;
}
