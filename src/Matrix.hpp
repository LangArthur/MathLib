/*
 * Created on Mon Apr 27 2020
 *
 * Copyright (c) MathLib 2020 Arthur Lang
 * Matrice.hpp
 */

#include <vector>
#include <algorithm>
#include <iostream>

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
            ~Matrix() { }

            inline const std::vector<T> &rawContent() const { return _content; }
            inline const std::pair<unsigned int, unsigned int> size() const {return {_rowSize, _colSize}; }

            inline T& operator[](int pos) { return _content[pos]; }

        private:
            unsigned int _colSize;
            unsigned int _rowSize;
            std::vector<T> _content;
    };

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