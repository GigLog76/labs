#include <iostream>
#include <fstream>
void task1();
void task2();
void task3();

int main(){
    std::cout<<"Enter number of task: ";
    int n_task;
    std::cin>>n_task;
    switch (n_task)
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
    default:
        break;
    }
    
}
