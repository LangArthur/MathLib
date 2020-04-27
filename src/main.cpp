/*
 * Created on Tue Apr 21 2020
 *
 * Copyright (c) MathLib 2020 Arthur Lang
 * main.cpp
 */

#include <iostream>

#include "Matrix.hpp"

// This main purpose is only testing
int main()
{
    math::Matrix<float> m(3u, 3u);
    std::cout << m << std::endl;
    return 0;
}
