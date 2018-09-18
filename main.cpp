#include <iostream>
#include "Matrix.h"
int main() {
    Matrix<int> m(2, 2);
    Matrix<int> s(2, 1);
    Matrix<int> j(1, 2);

    m.setValue(0, 0, 3);
    m.setValue(0, 1, 5);
    m.setValue(1, 0, 4);
    m.setValue(1, 1, 6);
    s.setValue(0, 0, 7);
    s.setValue(1, 0, 8);
    j.setValue(0, 0, 9);
    j.setValue(0, 1, 0);


    m.printMatrix();
    s.printMatrix();

    (m * 3).printMatrix();

    /*m.setCol(0, s);
    m.setRow(1, j);
    m.printMatrix();*/

    return 0;
}