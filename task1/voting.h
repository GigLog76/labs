#pragma once
#include <string>
#include <unordered_set>
#include <vector>

class votingS{
public:
    void enrolled(const std::string& file);
    void unenrolled (const std::string& surname);
    void PrintResults();
private:
    std::unordered_set<size_t> hashVot;
    std::vector<std::string> listVot;
    unsigned int duplicate = 0;
};
