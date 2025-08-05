#ifndef MATRIXIMPL_HPP
#define MATRIXIMPL_HPP
#include "matrix.hpp"

template <typename T, size_t N>
MultiDimMatrix<T, N>::MultiDimMatrix(const std::vector<size_t>& dimensions, const T& val) : m_dimensions{dimensions}, m_data(calculateTotalSize(dimensions), val) {
    calculateStrides();
}

template <typename T, size_t N>
typename MultiDimMatrix<T, N>::template Proxy<N - 1> MultiDimMatrix<T, N>::operator[](size_t index) {
    if (index >= m_dimensions[0]) {
            throw std::out_of_range("Invalid index");
    }
    return Proxy<N - 1>(*this, index * m_strides[0]);
}

template <typename T, size_t N>
void MultiDimMatrix<T, N>::fill(const T& val) {
    for (size_t i = 0; i < m_data.size(); ++i) {
        m_data[i] = val;
    }
}

template <typename T, size_t N>
bool MultiDimMatrix<T, N>::operator==(const MultiDimMatrix& other) const {
    return m_dimensions == other.m_dimensions && m_data == other.m_data;
}

template <typename T, size_t N>
bool MultiDimMatrix<T, N>::operator!=(const MultiDimMatrix& other) const {
    return !(*this == other);
}

template <typename T, size_t N>
void MultiDimMatrix<T, N>::apply(void (*func)(T&)) {
    for (size_t i = 0; i < m_data.size(); ++i) {
       func(m_data[i]);
    }
}

template <typename T, size_t N>
T MultiDimMatrix<T, N>::min() const {
    return *std::min_element(m_data.begin(), m_data.end());
}

template <typename T, size_t N>
T MultiDimMatrix<T, N>::max() const {
    return *std::max_element(m_data.begin(), m_data.end());
}

template <typename T, size_t N>
T MultiDimMatrix<T, N>::sum() const {
    T sum = T();
    for (size_t i = 0; i < m_data.size(); ++i) {
        sum += m_data[i];
    }
    return sum;
}

template <typename T, size_t N>
size_t MultiDimMatrix<T, N>::calculateTotalSize(const std::vector<size_t>& dims) {
    size_t total = 1;
    for (size_t i = 0; i < N; ++i) {
        total *= dims[i];
    }
    return total;
}

template <typename T, size_t N>
void MultiDimMatrix<T, N>::calculateStrides() {
    m_strides[N - 1] = 1;
    for (int i = N - 2; i >= 0; --i) {
        m_strides[i] = m_strides[i + 1] * m_dimensions[i + 1];
    }
}

#endif