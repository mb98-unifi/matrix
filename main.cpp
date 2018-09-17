#include <iostream>
#include "Matrix.h"
int main() {
    Matrix<int> m(2, 2);
    Matrix<int> s(2, 2);
    m.setValue(0, 0, 3);
    m.setValue(0, 1, 5);
    m.setValue(1, 0, 4);
    m.setValue(1, 1, 6);
    s.setValue(0, 0, 3);
    s.setValue(0, 1, 5);
    s.setValue(1, 0, 4);
    s.setValue(1, 1, 6);

    m.printMatrix();
    /* s.printMatrix();
     try {
         (m * s).printMatrix();
     } catch (Invalid_Matrix_Dimensions &e) {
         std::cout << e.what() << std::endl;
     }*/

    (m * 2).printMatrix();


    return 0;
}