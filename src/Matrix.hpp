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
    // TODO "in computer graphics, we would primarily deal with 4x4 matrices"

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
                    throw std::logic_error("Data to not fit matrix dimensions");
                _content = data;
            }
            Matrix(std::initializer_list<std::initializer_list<T>> l)
            {
                _colSize = l.size();
                _rowSize = l.begin()->size();
                for (const auto &col : l) {
                    if (col.size() != _rowSize)
                        throw std::logic_error("Matrix content do not always have the same dimension");
                    _content.insert(_content.end(), col);
                }
            }
            ~Matrix() { }

            /// \brief rawContent
            /// \return a vector containing the matrix's data.
            inline const std::vector<T> &rawContent() const { return _content; }
            /// \brief size
            /// \return the dimension of the matrix in a pair.
            inline const std::pair<unsigned int, unsigned int> size() const { return {_rowSize, _colSize}; }
            /// \brief isSquare
            /// \return check whether the matrix is squared  
            inline bool isSquare() const { return _colSize == _rowSize; }

            /// \brief operator[]
            /// no bound checking
            /// \param idx index of the row
            /// \return content of a row as a vector
            inline std::vector<T> operator[](const std::size_t idx) {
                return std::vector<T>(_content.begin() + (idx * _rowSize), _content.begin() + ((idx + 1) * _rowSize));
            }
            /// \brief operator[]
            /// no bound checking
            /// \param idx index of the row
            /// \return content of a row as a vector.
            inline const std::vector<T> operator[](const std::size_t idx) const {
                return std::vector<T>(_content.begin() + (idx * _rowSize), _content.begin() + ((idx + 1) * _rowSize));
            }
            /// \brief col
            /// \return return the content of a column as a vector.
            std::vector<T> col(std::size_t idx) {
                std::vector<T> res;
                res.reserve(_colSize);
                while (idx < _content.size()) {
                    res.push_back(_content[idx]);
                    idx += _rowSize;
                }
                return res;
            }
            /// \brief col
            /// \return return the content of a column as a vector.
            const std::vector<T> col(std::size_t idx) const {
                std::vector<T> res;
                res.reserve(_colSize);
                while (idx < _content.size()) {
                    res.push_back(_content[idx]);
                    idx += _rowSize;
                }
                return res;
            }
            /// \brief atCol
            /// \return return the content of a column as a vector.
            std::vector<T> atCol(std::size_t idx) {
                if (idx < 0 || idx > _rowSize)
                    throw std::out_of_range("indexe is out of range");
                std::vector<T> res;
                res.reserve(_colSize);
                while (idx < _content.size()) {
                    res.push_back(_content[idx]);
                    idx += _rowSize;
                }
                return res;
            }
            /// \brief atCol
            /// \return return the content of a column as a vector.
            const std::vector<T> atCol(std::size_t idx) const {
                if (idx < 0 || idx > _rowSize)
                    throw std::out_of_range("indexe is out of range");
                std::vector<T> res;
                res.reserve(_colSize);
                while (idx < _content.size()) {
                    res.push_back(_content[idx]);
                    idx += _rowSize;
                }
                return res;
            }

            /// \brief at
            /// bound checking
            /// \param idx index of the row
            /// \return content of a row as a vector
            inline std::vector<T>at(const std::size_t idx) {
                if (idx < 0 || idx > _colSize)
                    throw std::out_of_range("indexe is out of range");
                return std::vector<T>(_content.begin() + (idx * _rowSize), _content.begin() + ((idx + 1) * _rowSize));                
            }
            /// \brief at
            /// bound checking
            /// \param idx index of the row
            /// \return content of a row as a vector
            inline const std::vector<T>at(const std::size_t idx) const {
                if (idx < 0 || idx > _colSize)
                    throw std::out_of_range("indexe is out of range");
                return std::vector<T>(_content.begin() + (idx * _rowSize), _content.begin() + ((idx + 1) * _rowSize));                
            }
            /// \brief at
            /// bound checking
            /// \param col column number
            /// \param row row number
            /// \return value at the row and col position
            inline T& at(std::size_t col, std::size_t row) {
                if (col >= _colSize || row >= _rowSize)
                    throw std::out_of_range("indexes are out of range");
                return _content[_rowSize * col + row];
            }
            /// \brief at
            /// bound checking
            /// \param col column number
            /// \param row row number
            /// \return value at the row and col position
            inline const T& at(std::size_t col, std::size_t row) const {
                if (col >= _colSize || col < 0 || row >= _rowSize || row < 0)
                    throw std::out_of_range("indexes are out of range");
                return _content[_rowSize * col + row];
            }

            Matrix<T> operator*(const Matrix<T> &other) {
                auto otherSize = other.size();
                if (_colSize != otherSize.second)
                    throw std::logic_error("Cannot multiply different size matrices");
                Matrix res(_colSize, otherSize.first);
                for (int i = 0; i < _colSize; i++) {
                    for (int j = 0; j < otherSize.first; j++) {
                        // res[i][j] = 
                    }
                }
            }


        private:
            T _computeValueMul(const std::vector<T> row, const std::vector<T>col) {
                T res = 0;
                for (int i = 0; i < row.size(); i++)
                    res += row[i] * col[i];
                return res;
            }

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