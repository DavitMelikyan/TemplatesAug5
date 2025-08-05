#include <iostream>

template <size_t N>
struct Factorial {
    static constexpr size_t value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr size_t value = 1;
};

int main() {
    const size_t fac = 5;
    std::cout << Factorial<fac>::value << std::endl;
}