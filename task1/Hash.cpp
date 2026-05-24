#include <string>
#include "Hash.h"

size_t Hash(const std::string& str){
    size_t res=0;
    for (char c: str){
        res = res*137 + static_cast<unsigned char>(c);
    }
    return res;
}