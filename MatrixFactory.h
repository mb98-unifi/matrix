//
// Created by Mattia Bacci on 18/09/18.
//

#ifndef MATRIX_MATRIXFACTORY_H
#define MATRIX_MATRIXFACTORY_H

#include "Matrix.h"

template<typename T>
class MatrixFactory {
    //TODO find usage for this class
public:
    Matrix<T> createMatrix(std::string type, int r, int c) {
        if (type == "") {
            std::cout << "Matrix created" << std::endl;
            Matrix<int> m(r, c);
            return m;
        }

    }

};

#endif //MATRIX_MATRIXFACTORY_H
