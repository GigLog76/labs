#include "Matrix.h"
#include <random>




void matrix::def() {
    data.assign(2, std::vector<int>{0,0});
    ycolumns = 2;
    yrows = 2;
}

void matrix::create(int rows, int columns) {
    data.assign(rows, std::vector<int>(columns));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,20);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            data[i][j] = distrib(gen);
        }
    }
    ycolumns = columns;
    yrows = rows;
}

void matrix::null_mat(int rows, int columns) {
    data.assign(rows, std::vector<int>(columns, 0));
    yrows = rows;
    ycolumns = columns;   // !!! обязательно обновить размеры
}

int matrix::getRows() const { return yrows; }
int matrix::getColumns() const { return ycolumns; }

int matrix::messenger_max()const{
    int maxx = -9999;
    for (int i = 0; i < yrows; i++) {
        for (int j = 0; j < ycolumns; j++) {
            if (maxx<data[i][j]){
                maxx=data[i][j];
            }
        }
    }
    return maxx;
}


matrix operator+(const matrix &matrix1, const matrix &matrix2) {
    int input = 0;   
    matrix err;
    err.def();
    try {
        if (matrix1.getRows() != matrix2.getRows() || matrix1.getColumns() != matrix2.getColumns()) {
            throw (input);
        }
    } catch(int input) {
        std::cerr << "Can't add" << std::endl;
        return err;
    }
    matrix summ;
    summ.null_mat(matrix1.getRows(), matrix1.getColumns());
    for (int i = 0; i < matrix1.getRows(); i++) {
        for (int j = 0; j < matrix1.getColumns(); j++) {
            summ[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return summ;
}

matrix operator-(const matrix &matrix1, const matrix &matrix2) {
    int input = 0;   // инициализируем
    matrix err;
    err.def();
    try {
        if (matrix1.getRows() != matrix2.getRows() || matrix1.getColumns() != matrix2.getColumns()) {
            throw (input);
        }
    } catch(int input) {
        std::cerr << "Can't subtract" << std::endl;
        return err;
    }
    matrix diff;
    diff.null_mat(matrix1.getRows(), matrix1.getColumns());
    for (int i = 0; i < matrix1.getRows(); i++) {
        for (int j = 0; j < matrix1.getColumns(); j++) {
            diff[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return diff;
}

matrix operator*(const matrix &matrix1, const int num) {
    matrix res;
    res.null_mat(matrix1.getRows(), matrix1.getColumns());
    for (int i = 0; i < matrix1.getRows(); i++) {
        for (int j = 0; j < matrix1.getColumns(); j++) {
            res[i][j] = matrix1[i][j] * num;
        }
    }
    return res;
}

matrix operator*(const matrix &matrix1, const matrix &matrix2) {
    int input = 0;   
    matrix err;
    err.def();
    try {
        if (matrix1.getColumns() != matrix2.getRows()) {
            throw (input);
        }
    } catch(int input) {
        std::cerr << "Can't multiply" << std::endl;
        return err;
    }
    matrix res;
    res.null_mat(matrix1.getRows(), matrix2.getColumns());  // правильный размер
    for (int i = 0; i < matrix1.getRows(); i++) {
        for (int j = 0; j < matrix2.getColumns(); j++) {
            int sum = 0;
            for (int k = 0; k < matrix1.getColumns(); k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
}

bool operator==(const matrix &matrix1, const matrix &matrix2){
    if (matrix1.getRows() != matrix2.getRows() || matrix1.getColumns() != matrix2.getColumns()) {
        return false;
    }
    for (int i = 0; i < matrix1.getRows(); i++) {
        for (int j = 0; j < matrix2.getColumns(); j++) {
            if (matrix1[i][j]!=matrix2[i][j]){
                return false;
            }
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& os, const matrix& m){
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getColumns(); j++) {
            os<<m[i][j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}
std::istream& operator>>(std::istream& is,  matrix& m){
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getColumns(); j++) {
            is>>(m[i][j]);
        }
    }
    return is;
}