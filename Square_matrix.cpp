#include "Square_matrix.h"

void square_matrix::create(int size){
    matrix::data.assign(size, std::vector<int>(size));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,20);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data[i][j] = distrib(gen);
        }
    }
    ycolumns = size;
    yrows = size;
}

int square_matrix::determinant() const {
    int n = yrows;
    if (n != ycolumns) {
        std::cerr << "determinant() error: matrix not square" << std::endl;
        return 0;
    }
    if (n == 0) return 1;   
    if (n == 1) return data[0][0];
    if (n == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    
    int det = 0;
    int sign = 1;
    for (int j = 0; j < n; ++j) {
        square_matrix minor;
        minor.null_mat(n - 1, n - 1);

        for (int row = 1; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (col == j) continue;
                int newRow = row - 1;
                int newCol = (col < j) ? col : col - 1;
                minor[newRow][newCol] = data[row][col];
            }
        }
        det += sign * data[0][j] * minor.determinant();
        sign = -sign;
    }
    return det;
}

bool square_matrix::simmetry(){
    for (int i=0; i<yrows;i++){
        for (int j=0; j<ycolumns; j++){
            if (data[i][j]!=data[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

void square_matrix::power(int num){
    try{
        if (num<0){
            throw(num);
        }
    }
    catch(int num){
        std::cerr << "Don't supported" << std::endl;
        return;
    }
    if (num==0){
        int n = getRows(); 
        null_mat(n, n);    
        for (int i = 0; i < n; ++i) {
            data[i][i] = 1;
        }
        return;
    }
    int n = getRows();
    matrix result;
    result.null_mat(n, n);
    for (int i = 0; i < n; ++i) result[i][i] = 1;
    matrix base = *this;

    for (int i = 0; i < num; ++i) {
        result = result * base;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = result[i][j];
}