#include "HashTable.h"
#include <cassert>
#include <iostream>

size_t Hash1(const std::string& key){
    size_t res=0;
    for (char c: key){
        res = res*137 + static_cast<unsigned char>(c);
    }
    return res;
}


HashTable::HashTable() : hashCat(10),countEl(0){};

void HashTable::add(const std::string& product1, int price1){
    size_t index = Hash1 (product1)% hashCat.size();
    auto& list = hashCat[index];  
    for (auto& item : list){
        if (item.product == product1){
            item.price = price1;
            return;
        }
    }
    list.emplace_back(product1,price1);
    ++countEl;
    hashCat.reserve(countEl);
    }


bool HashTable::remove(const std::string& product2){
    size_t index = Hash1 (product2)% hashCat.size();
    auto& list = hashCat[index];
    size_t oldSize = hashCat.size();  
    list.remove_if([&product2](const Item& item){
        return item.product == product2;
    });
    if (list.size() < oldSize){
        --countEl;
        hashCat.reserve(countEl);
        return true;
    }
    return false;
}

int HashTable::find(const std::string& product3) const {
    size_t index = Hash1 (product3)% hashCat.size();
    auto& list = hashCat[index];
    for (auto& item : list){
        if (item.product == product3){
            return item.price;
        }
    }
    return 0;
}

    bool HashTable::isEmpty() const{
        return (countEl == 0);
    }

    size_t HashTable::size() const{
        return countEl;
    }
