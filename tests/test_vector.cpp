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
    math::Vector3i e({4, 2, -3});

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    auto output = splitOutput(testing::internal::GetCapturedStdout());
    ASSERT_EQ(output[0], "(1,1,1)");
    ASSERT_EQ(output[1], "(1,1,1)");
    ASSERT_EQ(output[2], "(1,3,3)");
    ASSERT_EQ(output[3], "(-1,3,-3)");
    ASSERT_EQ(output[4], "(4,2,-3)");
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
    auto mul = a * b;

    ASSERT_EQ(sum,  math::Vector3i(8, 9, 7));
    ASSERT_EQ(dif, math::Vector3i(-4, 1, 3));
    ASSERT_EQ(mul, math::Vector3i(12, 20, 10));
}

TEST(TestVector, normlization) {
    math::Vector3f a(0, 3, 4);
    a.normalize();
    ASSERT_EQ(a, math::Vector3f(0, 0.6, 0.8));
    math::Vector3i b(0, 3, 4);
    b.normalize();
    ASSERT_EQ(b, math::Vector3i(0, 0, 0));
}

TEST(TestVector, dotproduct) {
    math::Vector3f a(1, 1, 1);
    math::Vector3<float> b(a);
    math::Vector3i c(1, 3, 3);
    math::Vector3i d(-1, 3, -3);
    math::Vector3i e({4, 2, -3});
    ASSERT_EQ(math::Vector::dot(a, b), 3);
    ASSERT_EQ(math::Vector::dot(c, e), 1);
}

TEST(TestVector, angle) {
    math::Vector3f a(2, 5, 3);
    math::Vector3f b(2, 2, 4);
    math::Vector3f c(2, 5, 3);
    ASSERT_EQ(math::Vector::angle(a, b), static_cast<float>(std::acos(0.860946)));
    ASSERT_EQ(math::Vector::angle(a, c), 0);
}

TEST(TestVector, crossProduct) {
    math::Vector3f a(2, 7, 4);
    math::Vector3f b(3, 9, 9);
    math::Vector3f c(0, 1, 0);
    math::Vector3f d(1, 0, 0);

    ASSERT_EQ(a.cross(b), math::Vector3f(27, -6, -3));
    ASSERT_EQ(math::Vector::crossProduct(c, d), math::Vector3f(0, 0, -1));
    ASSERT_EQ(c.cross(d), math::Vector3f(0, 0, -1));
    ASSERT_EQ(d.cross(c), math::Vector3f(0, 0, 1)); // cross product are anticommutative
    /// TODO more test
}