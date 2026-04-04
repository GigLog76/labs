#include "task2.h"
#include <iostream>

void main_task2(){
    std::cout<<"Enter dividend and divisor: ";
    int a,b;
    std::cin>>a;
    std::cin>>b;
 
    int remainder;
    asm
    (
       "movl %1, %%eax\n\t" 
      "cdq\n\t"             
      "idivl %2\n\t"        
      "movl %%eax, %0\n\t"  
      : "=r"(remainder)     
      : "r"(a), "r"(b)      
      : "%eax", "%edx", "cc" 
    );
    std::cout<<remainder;
}