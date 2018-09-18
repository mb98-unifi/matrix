//
// Created by Mattia Bacci on 17/09/18.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include "Invalid_Matrix_Dimesions.h"
#include <stdexcept>

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
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            values[x + y * rows] = value;
        } else {
            throw std::out_of_range("Out of range");
        }
    }

    T getValue(int x, int y) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            return values[x + y * rows];
        } else {
            throw std::out_of_range("Out of range");
        }
    }

    Matrix<T> getCol(int y) {
        Matrix<T> col(rows, 1);
        for (int i = 0; i < rows; ++i) {
            col.setValue(i, 0, getValue(i, y));
        }
        return col;
    }

    Matrix<T> getRow(int x) {
        Matrix<T> row(1, cols);
        for (int i = 0; i < cols; ++i) {
            row.setValue(0, i, getValue(x, i));
        }
        return row;
    }

    void setCol(int y, T *values);

    void setRow(int x, T *values);

    T *getTrasposed();

    Matrix<T> operator*(const Matrix<T> &m) {
        if (cols == m.rows) {
            Matrix<T> prod(rows, m.cols);
            T tmp = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < m.cols; ++j) {
                    for (int k = 0; k < cols; ++k) {
                        tmp += values[i + k * rows] * m.values[k + j * rows];
                    }
                    prod.values[i + j * rows] = tmp;
                    tmp = 0;
                }

            }
            return prod;
        } else {
            throw Invalid_Matrix_Dimensions("Rows and Cols doesn't match");
        }
    }

    Matrix<T> operator*(const T num) {
        Matrix<T> prod(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                prod.values[i + j * rows] = num * values[i + j * rows];
            }
        }
        return prod;
    }

    ~Matrix() {
        delete[] values;
    }

private:
    T *values;
    int rows, cols;
};


#endif //MATRIX_MATRIX_H
