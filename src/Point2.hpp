/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) MathLib 2020 Arthur Lang
 * Point2.hpp
 */

#pragma once

namespace math {

    template<typename T>

    class Point2 {

        public:
            Point2(T x, T y) : _x(x), _y(y) {};
            Point2(std::initializer_list<T> l)
            {
                if (l.size() == 2) {
                    auto i = l.begin();
                    _x = (*i);
                    i++;
                    _y = (*i);
                } else {
                    std::cerr << "Invalid number of element to build math::Point3D" << std::endl;
                }
            };

            ~Point2();

            inline const T x() const { return _x; };
            inline const T y() const { return _y; };

            bool operator==(const Point2& other)
            {
                return (other.x() == _x && other.y() == y);
            }

            bool operator!=(const Point2& other)
            {
                return (other.x() != _x || other.y() != y);
            }

            Point2 operator+(const Point2& other)
            {
                Point2<T> res(_x + other.x(), _y + other.y());
                return res;
            }

            Point2 operator-(const Point2& other)
            {
                Point2<T> res(_x - other.x(), _y - other.y());
                return res;
            }

            Point2 operator*(const Point2& other)
            {
                Point2D<T> res(_x * other.x(), _y * other.y());
                return res;
            }

        private:
            T _x;
            T _y;
        };
}