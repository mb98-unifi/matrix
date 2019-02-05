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

TEST_F(TestMatrixSuite, getCol) {
    Matrix<int> c(3, 1);
    c = m.getCol(0);
    ASSERT_EQ(1, m.getValue(0, 0));
    ASSERT_EQ(4, m.getValue(1, 0));
    ASSERT_EQ(7, m.getValue(2, 0));
}

TEST_F(TestMatrixSuite, getRow) {
    Matrix<int> c(1, 3);
    c = m.getRow(0);
    ASSERT_EQ(1, m.getValue(0, 0));
    ASSERT_EQ(2, m.getValue(0, 1));
    ASSERT_EQ(3, m.getValue(0, 2));
}

TEST_F(TestMatrixSuite, setCol_Matrix) {
    Matrix<int> c(3, 1);
    c.setValue(0, 0, 11);
    c.setValue(1, 0, 12);
    c.setValue(2, 0, 13);
    m.setCol(1, c);
    ASSERT_EQ(11, m.getValue(0, 1));
    ASSERT_EQ(12, m.getValue(1, 1));
    ASSERT_EQ(13, m.getValue(2, 1));
}

TEST_F(TestMatrixSuite, setRow_Matrix) {
    Matrix<int> c(1, 3);
    c.setValue(0, 0, 11);
    c.setValue(0, 1, 12);
    c.setValue(0, 2, 13);
    m.setRow(1, c);
    ASSERT_EQ(11, m.getValue(1, 0));
    ASSERT_EQ(12, m.getValue(1, 1));
    ASSERT_EQ(13, m.getValue(1, 2));
}

TEST_F(TestMatrixSuite, setCol_Array) {
    m.setCol(1, new int[3]{11, 12, 13});
    ASSERT_EQ(11, m.getValue(0, 1));
    ASSERT_EQ(12, m.getValue(1, 1));
    ASSERT_EQ(13, m.getValue(2, 1));
}

TEST_F(TestMatrixSuite, setRow_Array) {
    m.setRow(1, new int[3]{11, 12, 13});
    ASSERT_EQ(11, m.getValue(1, 0));
    ASSERT_EQ(12, m.getValue(1, 1));
    ASSERT_EQ(13, m.getValue(1, 2));
}

TEST_F(TestMatrixSuite, getTransposed) {
    Matrix<int> c(3, 3);
    c.setRow(0, new int[3]{1, 4, 7});
    c.setRow(1, new int[3]{2, 5, 8});
    c.setRow(2, new int[3]{3, 6, 9});
    bool condition = false;
    if (m.getTransposed() == c) {
        condition = true;
    }
    ASSERT_TRUE(condition);
}

TEST_F(TestMatrixSuite, sum_Matrix) {
    Matrix<int> c(3, 3);
    Matrix<int> sum(3, 3);
    Matrix<int> s(3, 3);
    c.setRow(0, new int[3]{1, 5, 7});
    c.setRow(1, new int[3]{2, 2, 8});
    c.setRow(2, new int[3]{3, 7, 9});
    s.setRow(0, new int[3]{2, 7, 10});
    s.setRow(1, new int[3]{6, 7, 14});
    s.setRow(2, new int[3]{10, 15, 18});
    sum = m + c;
    bool condition = false;
    if (sum == s) {
        condition = true;
    }
    ASSERT_TRUE(condition);
}

TEST_F(TestMatrixSuite, sum_Scalar) {
    Matrix<int> sum(3, 3);
    Matrix<int> s(3, 3);
    s.setRow(0, new int[3]{4, 5, 6});
    s.setRow(1, new int[3]{7, 8, 9});
    s.setRow(2, new int[3]{10, 11, 12});
    sum = m + 3;
    bool condition = false;
    if (sum == s) {
        condition = true;
    }
    ASSERT_TRUE(condition);
}

TEST_F(TestMatrixSuite, product_Matrix) {
    Matrix<int> c(3, 3);
    Matrix<int> prod(3, 3);
    Matrix<int> p(3, 3);
    c.setRow(0, new int[3]{1, 5, 7});
    c.setRow(1, new int[3]{2, 2, 8});
    c.setRow(2, new int[3]{3, 7, 9});
    p.setRow(0, new int[3]{14, 30, 50});
    p.setRow(1, new int[3]{32, 72, 122});
    p.setRow(2, new int[3]{50, 114, 194});
    prod = m * c;
    bool condition = false;
    if (prod == p) {
        condition = true;
    }
    ASSERT_TRUE(condition);
}

TEST_F(TestMatrixSuite, product_Scalar) {
    Matrix<int> prod(3, 3);
    Matrix<int> p(3, 3);
    p.setRow(0, new int[3]{3, 6, 9});
    p.setRow(1, new int[3]{12, 15, 18});
    p.setRow(2, new int[3]{21, 24, 27});
    prod = m * 3;
    bool condition = false;
    if (prod == p) {
        condition = true;
    }
    ASSERT_TRUE(condition);
}

TEST_F(TestMatrixSuite, comparisonOperator) {
    Matrix<int> c(3, 3);
    c.setRow(0, new int[3]{1, 2, 3});
    c.setRow(1, new int[3]{4, 5, 6});
    c.setRow(2, new int[3]{7, 8, 9});
    bool condition = false;

    if (m == c) {
        condition = true;
    }
    ASSERT_TRUE(condition);

    condition = false;
    c.setValue(0, 2, 10);

    if (m == c) {
        condition = true;
    }
    ASSERT_FALSE(condition);
}

TEST_F(TestMatrixSuite, copyOperator) {
    Matrix<int> c(3, 3);
    c.setRow(0, new int[3]{1, 2, 4});
    c.setRow(1, new int[3]{7, 5, 5});
    c.setRow(2, new int[3]{7, 2, 9});

    m = c;

    bool condition = false;
    if (m == c) {
        condition = true;
    }
    ASSERT_TRUE(condition);
}

//TODO test eccezioni