#include "long.h"
#include "task3.h"
#include "task2.h"
#include <iostream>

void main_task1(){
    int n_of_task;
    std::cout<<"Enter the task number (1-5): ";
    std::cin>>n_of_task;
    switch (n_of_task)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;
    default:
        break;
    }{}
}




int main(){
    int n_of_task;
    std::cout<<"Enter the task number (1-3): ";
    std::cin>>n_of_task;
    switch (n_of_task){
        case 1:
            main_task1();
            break;
        case 2:
            main_task2();
            break;
        case 3:
            funk1();
            break;
    }
    return 0;
}