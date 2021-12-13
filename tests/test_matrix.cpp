/*
 * Created on Mon Nov 29 2021
 *
 * Arthur Lang
 * test_matrix.cpp
 */

#include <gtest/gtest.h>
#include <exception>

#include "Matrix.hpp"

TEST(TestMatrix, matrixInitialisation) {
    // testing::internal::CaptureStdout();

    math::Matrix<int> empty(3, 3);
    math::Matrixf a(3, 3);
    math::Matrixi b({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    });
    ASSERT_TRUE(empty.size().first == 3 && empty.size().second == 3);
    ASSERT_TRUE(a.size().first == 3 && a.size().second == 3);
    ASSERT_TRUE(b.size().first == 3 && b.size().second == 3);
}

TEST(TestMatrix, accessors) {
    math::Matrixi a({
        {1, 2, 3},
        {2, 1, -1},
        {2, -4, 1}
    });
    ASSERT_EQ(a(2, 1), -4);
    const auto constVal = a(0, 2);
    ASSERT_EQ(constVal, 3);
    // out of bound
    EXPECT_THROW({
        try {
            a(5, 2);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexes are out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
    EXPECT_THROW({
        try {
            a(1, 4);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexes are out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
    EXPECT_THROW({
        try {
            a(-1, 2);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexes are out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
}
