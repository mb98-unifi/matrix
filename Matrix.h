//
// Created by Mattia Bacci on 17/09/18.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>

template<typename T>
class Matrix {
public:

    Matrix(int r, int c) : rows(r), cols(c) {
        values = new T[rows * cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                values[i + j * rows] = 0;
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            std::cout << std::endl;
            for (int j = 0; j < cols; ++j) {
                std::cout << values[i + j * rows] << " ";
            }
        }
    }

    void setValue(int x, int y, T value) {
        values[x + y * rows] = value;
    }

    T getValue(int x, int y) {
        return values[x + y * rows];
    }

    Matrix<T> &getCol(int y) {
        Matrix<T> *col = new Matrix(rows, 1);
        for (int i = 0; i < rows; ++i) {
            col->setValue(i, 0, getValue(i, y));
        }
        return *col;
    }

    Matrix<T> getRow(int x) {
        Matrix<T> *row = new Matrix(1, cols);
        for (int i = 0; i < cols; ++i) {
            row->setValue(0, i, getValue(x, i));
        }
        return *row;
    }

    void setCol(int y, T *values);

    void setRow(int x, T *values);

    T *getTrasposed();

    Matrix<T> operator*(const Matrix<T> &);

    Matrix<T> operator*(const int);

    ~Matrix() {
        delete[] values;
    }

private:
    T *values;
    int rows, cols;
};


#endif //MATRIX_MATRIX_H
