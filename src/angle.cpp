/*
 * Created on Tue Nov 02 2021
 *
 * Arthur Lang
 * angle.cpp
 */

#include "angle.hpp"

#include <iostream>

float angle::toRadian(float degree) {
    return degree * M_PI / 180.0;
}

float angle::toDegree(float radian) {
    return radian * 180 / M_PI;
}
