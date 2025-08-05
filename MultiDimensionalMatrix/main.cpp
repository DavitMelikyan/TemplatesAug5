#include <iostream>
#include "matrix.hpp"
#include "matriximpl.hpp"

void square(int& x) { x = x * x; }

int main() {
    MultiDimMatrix<int, 3> mat1({2, 3, 4}, 1);
    mat1[0][1][2] = 42;
    mat1[1][2][3] = 5;
    std::cout << "[0][1][2]: " << mat1[0][1][2] << std::endl;
    std::cout << "Sum: " << mat1.sum() << "\n";
    std::cout << "Min: " << mat1.min() << "\n";
    std::cout << "Max: " << mat1.max() << "\n";
    mat1.apply(square);
    std::cout << "After squaring [1][2][3] = " << mat1[1][2][3] << std::endl;

    MultiDimMatrix<double, 3> mat2 ({3,3,4}, 4.5);
    mat2[0][1][2] = 2.5;
    mat2[1][2][3] = 10.98;
    std::cout << "[0][1][2]: " << mat2[0][1][2] << std::endl;
    std::cout << "Sum: " << mat2.sum() << "\n";
    std::cout << "Min: " << mat2.min() << "\n";
    std::cout << "Max: " << mat2.max() << "\n";

    return 0;
}
