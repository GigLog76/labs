#include "task3.h"
#include <iostream>

void funk5()
{
  double num = 1.0;
  throw(num);
}

void funk4(){ 
        std::cout << "funk4 start" << std::endl;
        funk5();
        std::cout << "funk4 press" << std::endl;
    }

void funk3(){
    std::cout << "funk3 start" << std::endl;
        try{
            funk4();
        }
        catch (int num){
            std::cerr << "int exception"<<std::endl; 
        }


        std::cout << "funk3 press" << std::endl;
}

void funk2(){
    std::cout << "funk2 start" << std::endl;
    try{
        try{
            funk3();
        }
        catch (int num){
            std::cerr << "int exception"<<std::endl; 
        }
    }
    catch(double e){
    std::cerr << "double exception" << std::endl;
    }

        std::cout << "funk2 press" << std::endl;
}

void funk1(){ 
        std::cout << "funk1 start" << std::endl;
        funk2();
        std::cout << "funk1 press" << std::endl;
    }