/*
 * Created on Tue Nov 02 2021
 *
 * Arthur Lang
 * test_angle.cpp
 */

#include <gtest/gtest.h>

#include "angle.hpp"

TEST(TestAngle, UnitConvertion) {
    // radian
    ASSERT_FLOAT_EQ(math::angle::toRadian(60), M_PI / 3);
    ASSERT_FLOAT_EQ(math::angle::toRadian(90), M_PI / 2);
    ASSERT_FLOAT_EQ(math::angle::toRadian(360), M_PI * 2);
    ASSERT_FLOAT_EQ(math::angle::toRadian(0), 0);
    // degree
    ASSERT_FLOAT_EQ(math::angle::toDegree(M_PI), 180);
    ASSERT_FLOAT_EQ(math::angle::toDegree(0), 0);
    ASSERT_FLOAT_EQ(math::angle::toDegree(M_PI / 4), 45);
    ASSERT_FLOAT_EQ(math::angle::toDegree(3 * M_PI / 2), 270);
}