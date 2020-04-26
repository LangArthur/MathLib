/*
 * Created on Wed Apr 08 2020
 *
 * Copyright (c) MathLib 2020 Arthur Lang
 * Point3.hpp
 */

#pragma once

#include <iostream>

#include "Vector3.hpp"

namespace math
{
    template<typename T>

    class Point3 {

        public:
            Point3(T x, T y, T z) : _x(x), _y(y), _z(z) {};
            Point3(std::initializer_list<T> l)
            {
                if (l.size() == 3) {
                    auto i = l.begin();
                    _x = (*i);
                    i++;
                    _y = (*i);
                    i++;
                    _z = (*i);
                } else {
                    std::cerr << "Invalid number of element to build math::Point3" << std::endl;
                }
            };
            ~Point3() {};

            inline const T x() const { return _x; };
            inline const T y() const { return _y; };
            inline const T z() const { return _z; };

            bool operator==(const Point3<T> &other)
            {
                return (other.x() == _x && other.y() == y && other.z() == z);
            }

            bool operator!=(const Point3<T> &other)
            {
                return (other.x() != _x || other.y() != y || other.z() != z);
            }

            Point3<T> operator+(const Point3<T> &other)
            {
                Point3<T> res(_x + other.x(), _y + other.y(), _z + other.z());
                return res;
            }

            Point3<T> operator-(const Point3<T> &other)
            {
                Point3<T> res(_x - other.x(), _y - other.y(), _z - other.z());
                return res;
            }

            Point3<T> operator*(const Point3<T> &other)
            {
                Point3<T> res(_x * other.x(), _y * other.y(), _z * other.z());
                return res;
            }

        private:
            T _x;
            T _y;
            T _z;
    };

    using Point3f = Point3<float>;
    using Point3i = Point3<int>;
    using Point3d = Point3<double>;

    template<typename T>
    static math::Vector3<T> toVector(const Point3<T> &fst, const Point3<T> &sec)
    {
        math::Vector3 v(sec.x() - fst.x(), sec.y() - fst.y(), sec.z() - fst.z());
        return v;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Point3<T> &toDisp)
    {
        os << "[" << toDisp.x() << "," << toDisp.y() << "," << toDisp.z() << "]";
        return os;
    }
}