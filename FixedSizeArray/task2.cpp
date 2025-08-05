#include <iostream>

template <typename T, size_t N1, size_t N2>
class CompareArrays {
private:
    bool areEqual = false;
public:
    CompareArrays() {
        return areEqual;
    }
};

template <typename T, size_t N, size_t N>
class CompareArrays {
private:
    bool areEqual = true;
public:
    CompareArrays() {
        return areEqual;
    }
};