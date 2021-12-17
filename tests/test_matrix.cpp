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

    // bad initialisation
    EXPECT_THROW({
        try {
            math::Matrixi c({
                {1, 1, 1},
                {1, 1, 1},
                {1, 1}
            });
        }
        catch (const std::logic_error &e ) {
            EXPECT_STREQ( "Matrix content do not always have the same dimension", e.what() );
            throw;
        }
    }, std::logic_error );

}

TEST(TestMatrix, accessors) {
    math::Matrixi a({
        {1, 2, 3},
        {2, 1, -1},
        {2, -4, 1}
    });

    // square bracket accessor
    ASSERT_EQ(a[2], std::vector<int>({2, -4, 1}));
    ASSERT_EQ(a[0], std::vector<int>({1, 2, 3}));
    ASSERT_EQ(a[0][2], 3);
    const auto constVal = a[0][2];
    ASSERT_EQ(constVal, 3);
    // no bounding check
    EXPECT_NO_THROW({
        a[5][2];
    });
    EXPECT_NO_THROW({
        a[2][10];
    });
    // col accessor
    ASSERT_EQ(a.col(2), std::vector<int>({3, -1, 1}));
    ASSERT_EQ(a.col(0), std::vector<int>({1, 2, 2}));
    EXPECT_NO_THROW({
        a.col(-1);
    });
    // at accessor
    ASSERT_EQ(a.at(2), std::vector<int>({2, -4, 1}));
    ASSERT_EQ(a.at(0), std::vector<int>({1, 2, 3}));
    ASSERT_EQ(a.at(0, 2), 3);
    // bound checking
    EXPECT_THROW({
        try {
            a.at(5, 2);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexes are out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
    EXPECT_THROW({
        try {
            a.at(1, 4);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexes are out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
    EXPECT_THROW({
        try {
            a.at(-1, 2);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexes are out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
    // col accessor
    ASSERT_EQ(a.atCol(2), std::vector<int>({3, -1, 1}));
    ASSERT_EQ(a.atCol(0), std::vector<int>({1, 2, 2}));
    // bound checking
    EXPECT_THROW({
        try {
            a.atCol(23);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexe is out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
    EXPECT_THROW({
        try {
            a.atCol(-1);
        }
        catch (const std::out_of_range &e ) {
            EXPECT_STREQ( "indexe is out of range", e.what() );
            throw;
        }
    }, std::out_of_range );
}

TEST(TestMatrix, isSquare) {
    math::Matrixi square({
        {1, 2, 3},
        {2, 1, -1},
        {2, -4, 1}
    });
    math::Matrixi notSquare({
        {1, 2, 3, 4, 5},
        {2, 1, -1, 4, 2},
        {2, -4, 1, 1, 2}
    });
    ASSERT_FALSE(notSquare.isSquare());
    ASSERT_TRUE(square.isSquare());
}