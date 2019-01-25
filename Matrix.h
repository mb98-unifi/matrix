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
        for (int i = 0; i < rows * cols; ++i) {
            values[i] = 0;
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

    void setCol(int y, Matrix<T> &icol) {
        if (icol.cols == 1 && y >= 0 && y < cols) {
            if (rows == icol.rows) {
                for (int i = 0; i < rows; ++i) {
                    setValue(i, y, icol.getValue(i, 0));
                }

            } else {
                throw Invalid_Matrix_Dimensions("Not the same rows");
            }
        } else {
            throw Invalid_Matrix_Dimensions("Input Matrix isn't a column Matrix or column index is invalid");
        }
    }

    void setRow(int x, Matrix<T> &irow) {
        if (irow.rows == 1 && x >= 0 && x < rows) {
            if (cols == irow.cols) {
                for (int i = 0; i < cols; ++i) {
                    setValue(x, i, irow.getValue(0, i));
                }

            } else {
                throw Invalid_Matrix_Dimensions("Not the same cols");
            }
        } else {
            throw Invalid_Matrix_Dimensions("Input Matrix isn't a row Matrix or column index is invalid");
        }
    }

    void setCol(int y, T *vals) {
        for (int i = 0; i < rows; ++i)
            setValue(i, y, vals[i]);
    }

    void setRow(int x, T *vals) {
        for (int i = 0; i < cols; ++i)
            setValue(x, i, vals[i]);
    }

    Matrix<T> getTransposed() {
        Matrix<T> transMatrix(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transMatrix.setValue(j, i, getValue(i, j));
            }
        }
        return transMatrix;
    }

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

    Matrix<T> &operator*(const T num) {
        for (int i = 0; i < rows * cols; ++i) {
            values[i] *= num;
        }
        return *this;
    }

    bool operator==(const Matrix<T> &m) {
        if (rows == m.rows && cols == m.cols) {
            for (int i = 0; i < rows * cols; ++i) {
                if (values[i] != m.values[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    Matrix<T> &operator=(const Matrix<T> &m) {
        if (rows == m.rows && cols == m.cols) {
            for (int i = 0; i < rows * cols; ++i) {
                values[i] = m.values[i];
            }
        } else {
            throw Invalid_Matrix_Dimensions("Rows and Cols doesn't match");
        }
        return *this;
    }

    ~Matrix() {
        delete[] values;
    }

private:
    T *values;
    int rows, cols;
};


#endif //MATRIX_MATRIX_H
