//
// Created by Mattia Bacci on 17/09/18.
//

#include <iostream>
#include <stdexcept>
#include <string>

#ifndef MATRIX_INVALID_MATRIX_DIMESIONS_H
#define MATRIX_INVALID_MATRIX_DIMESIONS_H

class Invalid_Matrix_Dimensions : public std::logic_error {

public:
    Invalid_Matrix_Dimensions(std::string error) : logic_error(error) {}

};

#endif //MATRIX_INVALID_MATRIX_DIMESIONS_H
