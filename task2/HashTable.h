#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <utility>

class HashTable{
public:
    HashTable();
    void add(const std::string& product1, int price1);

    bool remove(const std::string& product2);

    int find(const std::string& product3) const;

    bool isEmpty() const;

    size_t size() const;
private:
    struct Item{
        std::string product;
        int price;
        Item (const std::string k, int v){
            product = k;
            price = v;
        }
    };
    std::vector<std::list<Item>> hashCat;
    size_t countEl;
    size_t Hash(const std::string& key) const;

};
