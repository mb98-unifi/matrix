//
// Created by Mattia Bacci on 19/09/18.
//

#include <gtest/gtest.h>
#include "../Matrix.h"

class TestMatrixSuite : public ::testing::Test {

protected:

    TestMatrixSuite() : m(3, 3) {}

    virtual void SetUp() {
        m.setRow(0, new int[3]{1, 2, 3});
        m.setRow(1, new int[3]{4, 5, 6});
        m.setRow(2, new int[3]{7, 8, 9});
    }

    Matrix<int> m;
};



