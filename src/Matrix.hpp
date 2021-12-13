/*
 * Created on Mon Apr 27 2020
 *
 * Copyright (c) MathLib 2020 Arthur Lang
 * Matrice.hpp
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

namespace math
{
    template <typename T>
    class Matrix {

        public:
            Matrix(unsigned int rowSize = 0, unsigned int colSize = 0) : _colSize(colSize), _rowSize(rowSize)
            {
                _content.reserve(rowSize * colSize);
                std::fill(_content.begin(), _content.end(), 0);
            }
            Matrix(unsigned int rowSize, unsigned int colSize, std::vector<T> data) : _colSize(colSize), _rowSize(rowSize)
            {
                if (rowSize * colSize < data.size)
                    throw std::logic_error("Error: Data to not fit matrix dimensions");
                _content = data;
            }
            Matrix(std::initializer_list<std::initializer_list<T>> l)
            {
                _colSize = l.size();
                _rowSize = l.begin()->size();
                for (const auto &col : l) {
                    _content.insert(_content.end(), col);
                }
            }
            ~Matrix() { }

            inline const std::vector<T> &rawContent() const { return _content; }
            inline const std::pair<unsigned int, unsigned int> size() const { return {_rowSize, _colSize}; }

            inline T& operator()(std::size_t col, std::size_t row) {
                if (col >= _colSize || row >= _rowSize)
                    throw std::out_of_range("indexes are out of range");
                return _content[_rowSize * col + row];
            }
            inline const T& operator()(std::size_t col, std::size_t row) const {
                if (col >= _colSize || col < 0 || row >= _rowSize || row < 0)
                    throw std::out_of_range("indexes are out of range");
                return _content[_rowSize * col + row];
            }

        private:
            unsigned int _colSize;
            unsigned int _rowSize;
            std::vector<T> _content;
    };

    using Matrixf = Matrix<float>;
    using Matrixi = Matrix<int>;
    using Matrixd = Matrix<double>;

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Matrix<T> &mat)
    {
        unsigned int count = 0;
        std::pair<unsigned int, unsigned int> dim;
        for (auto &i : mat.rawContent()) {
            if (count == 0)
                os << '[';
            os << i;
            if (count == dim.second - 1) {
                count = 0;
                os << ']' << std::endl;
            }
            count++;
        }
        return os;
    }
}