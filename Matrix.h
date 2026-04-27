#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>
#include <random>

class matrix{
    protected:
    int yrows = 0;
    int ycolumns = 0;
    std::vector<std::vector<int>>data;
public:
    int messenger_max() const; 
    void def();
    int getRows() const ;
    void null_mat(int rows, int columns);
    int getColumns() const ;
    std::vector<int>& operator[](int index){return data[index];}
    const std::vector<int>& operator[](int index) const {return data[index];}
    void create(int rows, int columns);
private:
    


    

    




};
matrix operator+(const matrix &matrix1, const matrix &matrix2);
matrix operator-(const matrix &matrix1, const matrix &matrix2);
matrix operator*(const matrix &matrix1, const int num);
matrix operator*(const matrix &matrix1, const matrix &matrix2);
bool operator==(const matrix &matrix1, const matrix &matrix2);
std::ostream& operator<<(std::ostream& os, const matrix& m);
std::istream& operator>>(std::istream& is, matrix& m);

//int messenger_max (const matrix &matrix1);
#endif