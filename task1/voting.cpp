#include "voting.h"
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <string>


void votingS::enrolled(const std::string& file){
    std::fstream fs;
    std::string name;
    fs.open(file);
    std::string surname;
    while (std::getline(fs,surname)){
        size_t hashName = Hash(surname);
        if (hashVot.find(hashName) == hashVot.end()){
            hashVot.insert(hashName);
            listVot.push_back(surname);
        }
        else{
            ++duplicate;
        }
}fs.close();
}
void votingS::unenrolled(const std::string& surname){
    size_t hashName = Hash(surname);
        if (hashVot.find(hashName) == hashVot.end()){
            hashVot.insert(hashName);
            listVot.push_back(surname);
        }
        else{
            ++duplicate;
        }
}

void votingS::PrintResults(){
    std::cout<<"\nCount of voting people: "<< listVot.size();
    std::cout<<"\nCount of duplicates: "<< duplicate;
    std::cout<<"\nSurnames of those people, who want to skip a pair: \n";
    for (const auto& list : listVot){
        std::cout<<list<<std::endl;
    }
}