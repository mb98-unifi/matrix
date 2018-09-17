#include <iostream>
#include "Matrix.h"
int main() {
    Matrix<int> m(3, 7);
    m.setValue(1, 1, 3);
    m.printMatrix();
    Matrix<int> col = m.getCol(1);
    col.printMatrix();
    Matrix<int> row = m.getRow(1);
    row.printMatrix();

    return 0;
}