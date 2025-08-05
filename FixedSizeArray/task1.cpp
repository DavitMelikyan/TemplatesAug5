#include <iostream>

template <typename T, size_t N>
class FixedArray {
private:
    T data[N];
public:
    T& operator[](size_t i) {
        if (i < 0 || i > N) return nullptr;
        return data[i];
    }

    const T& operator[]() const {
        if (i < 0 || i > N) return nullptr;
        return data[i];
    }

    constexpr size_t size() {
        return N;
    }
};