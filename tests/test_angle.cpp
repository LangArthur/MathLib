/*
 * Created on Tue Nov 02 2021
 *
 * Arthur Lang
 * test_angle.cpp
 */

#include <gtest/gtest.h>

#include "angle.hpp"

TEST(TestAngle, UnitConvertion) {
    std::cout << (angle::toRadian(60) == 1.0472) << std::endl;
    ASSERT_EQ(angle::toRadian(60), 1.0472f);
    ASSERT_EQ(angle::toRadian(90), M_PI / 2);
}