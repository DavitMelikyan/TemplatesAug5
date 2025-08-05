#include <iostream>
#include "matrix.hpp"
#include "matriximpl.hpp"

void square(int& x) { x = x * x; }

int main() {
    MultiDimMatrix<int, 3> matrix({2, 3, 4}, 1); // 2x3x4 matrix filled with 1s

    matrix[0][1][2] = 42;
    matrix[1][2][3] = 5;

    std::cout << "Value at [0][1][2]: " << matrix[0][1][2] << "\n";
    std::cout << "Sum: " << matrix.sum() << "\n";
    std::cout << "Min: " << matrix.min() << "\n";
    std::cout << "Max: " << matrix.max() << "\n";

    matrix.apply(square);
    std::cout << "After squaring, [1][2][3] = " << matrix[1][2][3] << "\n";

    return 0;
}
