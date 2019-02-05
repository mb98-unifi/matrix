//
// Created by Mattia Bacci on 19/09/18.
//

#include <gtest/gtest.h>
#include "../Matrix.h"

TEST(Matrix, Constructor) {
    Matrix<int> m(3, 3);
    ASSERT_EQ(0, m.getValue(0, 0));
    ASSERT_EQ(0, m.getValue(2, 2));
}

TEST(Matrix, setValue) {
    Matrix<int> m(2, 2);
    m.setValue(1, 0, 5);
    ASSERT_EQ(5, m.getValue(1, 0));
}

TEST(Matrix, setValue_Exception) {
    Matrix<int> m(2, 2);
    ASSERT_THROW(m.setValue(10, 0, 5), std::out_of_range);
}



