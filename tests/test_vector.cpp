/*
 * Created on Fri Oct 29 2021
 *
 * Arthur Lang
 * test_vector.cpp
 */

#include <gtest/gtest.h>

#include "Vector3.hpp"
#include "utils.hpp"

TEST(TestVector, vectorInitialisation) {
    testing::internal::CaptureStdout();

    math::Vector3f a(1, 1, 1);
    math::Vector3<float> b(a);
    math::Vector3i c(1, 3, 3);
    math::Vector3i d(-1, 3, -3);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    auto output = splitOutput(testing::internal::GetCapturedStdout());
    ASSERT_EQ(output[0], "(1,1,1)");
    ASSERT_EQ(output[1], "(1,1,1)");
    ASSERT_EQ(output[2], "(1,3,3)");
    ASSERT_EQ(output[3], "(-1,3,-3)");
}

TEST(TestVector, assertion) {
    math::Vector3i a(2, 4, 6);
    math::Vector3<int> b(2, 4, 6);
    math::Vector3i c(6, 4, 8);
    math::Vector3i d(6, 10, 3);

    ASSERT_TRUE(a == b);
    ASSERT_FALSE(a != b);
    ASSERT_FALSE(a == c);
    ASSERT_TRUE(a != c);
    ASSERT_TRUE(a < d);
    ASSERT_TRUE(a <= a);
    ASSERT_TRUE(c > a);
    ASSERT_TRUE(c >= a);
}

TEST(TestVector, operation) {
    math::Vector3i a(2, 5, 5);
    math::Vector3i b(6, 4, 2);

    auto sum = a + b;
    auto dif = a - b;

    ASSERT_EQ(sum,  math::Vector3i(8, 9, 7));
    ASSERT_EQ(dif, math::Vector3i(-4, 1, 3));
}

TEST(TestVector, normlization) {
    math::Vector3f a(0, 3, 4);
    a.normalize();
    ASSERT_EQ(a, math::Vector3f(0, 0.6, 0.8));
    math::Vector3i b(0, 3, 4);
    b.normalize();
    ASSERT_EQ(b, math::Vector3i(0, 0, 0));
}