#include "voting.h"
#include <iostream>
#include <fstream>
#include <string>


void task1(){
    std::cout<<"Who want's to skip pair?"<<std::endl;
    votingS voting;
    std::string fs="student.txt";
    voting.enrolled(fs);
    std::string name;
    while (name != "end"){
        std::cin>>name;
        voting.unenrolled(name);
    }
    voting.PrintResults();
}