#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H
#include "Matrix.h"
class square_matrix : public matrix{

    public: 
    int determinant() const;
    void create(int size);
    bool simmetry();
    void power(int num);
    
};
#endif