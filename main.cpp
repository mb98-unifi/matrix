#include <iostream>
#include "Matrix.h"
#include "MatrixFactory.h"
int main() {
    MatrixFactory<int> factory;
    Matrix<int> m = factory.createMatrix("", 3, 3);



    m.setRow(0, new int[3]{1, 2, 3});
    m.setRow(1, new int[3]{4, 5, 6});
    m.setRow(2, new int[3]{5, 6, 7});
    /*m.setValue(2, 0, 7);
    m.setValue(2, 1, 8);
    s.setValue(0, 0, 7);
    s.setValue(1, 0, 8);
    j.setValue(0, 0, 9);
    j.setValue(0, 1, 0);*/


    m.printMatrix();
    //s.printMatrix();

    //m.getTransposed().printMatrix();
    (m * m).printMatrix();
    /*m.setCol(0, s);
    m.setRow(1, j);
    m.printMatrix();*/

    return 0;
}