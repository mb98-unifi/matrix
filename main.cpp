#include <iostream>
#include "Matrix.h"
#include "MatrixFactory.h"
int main() {
    Matrix<int> m(3, 3);
    Matrix<int> s(3, 3);

    m.setRow(0, new int[3]{1, 2, 3});
    m.setRow(1, new int[3]{4, 5, 6});
    m.setRow(2, new int[3]{7, 8, 9});
    s.setRow(0, new int[3]{1, 2, 3});
    s.setRow(1, new int[3]{4, 5, 6});
    s.setRow(2, new int[3]{7, 8, 9});


    if (m == s) {
        std::cout << "ok";
    }

    Matrix<int> c(3, 1);
    c = m.getCol(0);
    c.printMatrix();
    return 0;
}