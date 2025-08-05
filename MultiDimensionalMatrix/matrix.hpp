#ifndef m_matrixHPP
#define m_matrixHPP

#include <vector>
#include <iostream>
#include <initializer_list>

template <typename T, size_t N>
class MultiDimMatrix {
private:
    std::vector<size_t> m_dimensions;
    std::vector<T> m_data;
    std::array<size_t, N> m_strides;
    static constexpr std::size_t dimensions_count = N;
public:
    MultiDimMatrix(const std::vector<size_t>& dimensions, const T& val = T());
    template <size_t Dim>
    class Proxy {
    public:
        Proxy(MultiDimMatrix& matrix, size_t indexOffset) : m_matrix{matrix}, m_indexOffset{indexOffset} {}

        auto operator[](size_t index) {
            if (index >= m_matrix.m_dimensions[MultiDimMatrix::dimensions_count - Dim]) {
                throw std::out_of_range("Index out of range");
            }

            size_t offset = m_indexOffset + index * m_matrix.m_strides[N - Dim];
            return Proxy<Dim - 1>(m_matrix, offset);
        }

    private:
        MultiDimMatrix& m_matrix;
        size_t m_indexOffset;
    };

    template <>
    class Proxy<1> {
    public:
        Proxy(MultiDimMatrix& matrix, size_t indexOffset) : m_matrix{matrix}, m_indexOffset{indexOffset} {}

        T& operator[](size_t index) {
            if (index >= m_matrix.m_dimensions[MultiDimMatrix::dimensions_count - 1]) {
                throw std::out_of_range("Invalid index");
            }

            return m_matrix.m_data[m_indexOffset + index];
        }

    private:
        MultiDimMatrix& m_matrix;
        size_t m_indexOffset;
    };

    Proxy<N - 1> operator[](size_t index);
    void fill(const T& val);
    bool operator==(const MultiDimMatrix& other) const;
    bool operator!=(const MultiDimMatrix& other) const;
    void apply(void (*func)(T&));
    T min() const;
    T max() const;
    T sum() const;
    size_t calculateTotalSize(const std::vector<size_t>& dims);
    void calculateStrides();
};

#include "matriximpl.hpp"

#endif