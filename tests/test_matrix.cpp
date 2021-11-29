/*
 * Created on Mon Nov 29 2021
 *
 * Arthur Lang
 * test_matrix.cpp
 */

#include <gtest/gtest.h>

#include "Matrix.hpp"

TEST(TestMatrix, matrixInitialisation) {
    // testing::internal::CaptureStdout();

    math::Matrix<int> empty(3, 3);
    math::Matrixf a(3., 3.)
    math::Matrixi b({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    })
    // math::Vector3f a(1, 1, 1);
    // math::Vector3<float> b(a);
    // math::Vector3i c(1, 3, 3);
    // math::Vector3i d(-1, 3, -3);
    // math::Vector3i e({4, 2, -3});

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;
    // std::cout << e << std::endl;
    // auto output = splitOutput(testing::internal::GetCapturedStdout());
    // ASSERT_EQ(output[0], "(1,1,1)");
    // ASSERT_EQ(output[1], "(1,1,1)");
    // ASSERT_EQ(output[2], "(1,3,3)");
    // ASSERT_EQ(output[3], "(-1,3,-3)");
    // ASSERT_EQ(output[4], "(4,2,-3)");
}
