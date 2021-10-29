/*
 * Created on Sun Apr 26 2020
 *
 * Copyright (c) mathLib 2020 Arthur Lang
 * Vector3.hpp
 */

#pragma once

#include <cmath>
#include <exception>
#include <iostream>
#include <cmath>

namespace math
{
    template <typename T>

    class Vector3 {

        public:
            Vector3(T x, T y, T z) : _x(x), _y(y), _z(z) { }
            Vector3(const Vector3<T> &other) : _x(other.x()), _y(other.y()), _z(other.z()) { }
            Vector3(std::initializer_list<T> l) {
                if (l.size() == 3) {
                    auto i = l.begin();
                    _x = (*i);
                    i++;
                    _y = (*i);
                    i++;
                    _z = (*i);
                } else
                    throw std::runtime_error("Invalid number of element to build math::Vector3");
            };
            ~Vector3() = default;

            inline const T x() const { return _x; }
            inline const T y() const { return _y; }
            inline const T z() const { return _z; }

            inline float norm() const { return std::sqrt(std::pow(_x, 2) + std::pow(_y, 2) + std::pow(_z, 2)); }
            inline float squaredNorm() const { return std::pow(_x, 2) + std::pow(_y, 2) + std::pow(_z, 2); }
            inline T dot(const Vector3<T> other) { return _x * other.x() + _y * other.y() + _z * other.z(); }

            bool operator==(const Vector3<T> &other) { 
                return(_x == other.x() && _y == other.y() && _z == other.z());
            }

            bool operator!=(const Vector3<T> &other) { 
                return(_x != other.x() || _y != other.y() || _z != other.z());
            }

            bool operator<(const Vector3<T> &other) {
                return squaredNorm() < other.squaredNorm();
            }

            bool operator<=(const Vector3<T> &other) {
                return squaredNorm() <= other.squaredNorm();
            }

            bool operator>(const Vector3<T> &other) {
                return squaredNorm() > other.squaredNorm();
            }

            bool operator>=(const Vector3<T> &other) {
                return squaredNorm() >= other.squaredNorm();
            }

            Vector3<T> operator+(const Vector3<T> &other) {
                Vector3<T> res(_x + other.x(), _y + other.y(), _z + other.z());
                return res;
            }

            Vector3<T> operator-(const Vector3<T> &other) {
                Vector3<T> res(_x - other.x(), _y - other.y(), _z - other.z());
                return res;
            }

            void normalize() {
                float vecNorm = norm();
                if (vecNorm != 0) {
                    _x /= vecNorm;
                    _y /= vecNorm;
                    _z /= vecNorm;
                } else
                    throw std::logic_error("Error: cannot normalize a vector of norm = 0");
            }

        private:
            T _x;
            T _y;
            T _z;
    };

    using Vector3f = Vector3<float>;
    using Vector3i = Vector3<int>;
    using Vector3d = Vector3<double>;

    template<typename T>
    bool operator==(const Vector3<T> &a, const Vector3<T> &b) {
        return (a.x() == b.x() && a.y() == b.y() && a.z() == b.z());
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Vector3<T> &toDisp)
    {
        os << "(" << toDisp.x() << "," << toDisp.y() << "," << toDisp.z() << ")";
        return os;
    }

    namespace Vector {
        template<typename T>
        T dot(const Vector3<T> &a, const Vector3<T> &b) {
            return (a.x() * b.x() + a.y() * b.y() + a.z() * b.z());
        }

        template<typename T>
        bool areOrthogonal(const Vector3<T> &a, const Vector3<T> &b) {
            return dot(a, b) == 0;
        }

        template<typename T>
        float angle(const Vector3<T> &a, const Vector3<T> &b) {
            return std::acos(dot(a, b) / (a.norm() * b.norm()));
        }        
    }
}