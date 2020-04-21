/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) RayTracer 2020 Arthur Lang
 * Point2D.hpp
 */

#pragma once

namespace math {

    template<typename T>

    class Point2D {

        public:
            Point2D(T x, T y) : _x(x), _y(y) {};
            Point2D(std::initializer_list<T> l)
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

            ~Point2D();

            inline const T x() const { return _x; };
            inline const T y() const { return _y; };

            bool operator==(const Point2D& other)
            {
                return (other.x() == _x && other.y() == y);
            }

            bool operator!=(const Point2D& other)
            {
                return (other.x() != _x || other.y() != y);
            }

            Point2D operator+(const Point2D& other)
            {
                Point2D<T> res(_x + other.x(), _y + other.y());
                return res;
            }

            Point2D operator-(const Point2D& other)
            {
                Point2D<T> res(_x - other.x(), _y - other.y());
                return res;
            }

            Point2D operator*(const Point2D& other)
            {
                Point2D<T> res(_x * other.x(), _y * other.y());
                return res;
            }

        private:
            T _x;
            T _y;
        };
}