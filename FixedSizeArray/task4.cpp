#include <iostream>

template <void (*Func)()>
class Executor {
public:
    void execute() const {
        Func();
    }
};

void hello() {
    std::cout << "Hello" << std::endl;
}

void bye() {
    std::cout << "Bye" << std::endl;
}

int main() {
    Executor<hello> ex1;
    Executor<bye> ex2;
    ex1.execute();
    ex2.execute();
}
