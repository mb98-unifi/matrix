//
// Created by Mattia Bacci on 19/09/18.
//

#include <gtest/gtest.h>
#include "../Matrix.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Matrix, Constructor) {
    Matrix<int> m(3, 3);
    ASSERT_EQ(0, m.getValue(0, 0));
    ASSERT_EQ(0, m.getValue(2, 2));
}