#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Matrix.h"
#include "Square_matrix.h"

int main(){
   /* matrix m,n;
    m.create(2,2);
    n.create(2,2);
    std::cout<<m<<std::endl;
    std::cout<<n<<std::endl;
    std::cout<<m+n<<std::endl;
    std::cout<<m*n<<std::endl;
    m.~matrix();
    n.~matrix();
    n.print();
    m.print();
    matrix c = n-m;
    matrix b = n+m;
    c.print();
    b.print();
    m.print();
    n.print();
    matrix c;
    c=m*n;
    m.print();
    n.print();
    std::cout<<(m==n);
    m=n;
    std::cout<<m<<std::endl;
    std::cout<<m.messenger_max();*/
    square_matrix c;
    c.create(3);
    std::cout<<c;
    std::cout<<"determinant: ";
    std::cout<<c.determinant()<<std::endl;
    std::cout<<"simmetry: ";
    std::cout<<c.simmetry()<<std::endl;
    std::cout<<"power of 3: "<<std::endl;
    square_matrix g;
    c.power(3);
    std::cout<<c;
}
