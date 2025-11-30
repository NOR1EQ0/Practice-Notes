#include <algorithm>
#include <iostream>

// -fno-elide-constructors

struct MyClass {
    MyClass() { std::cout << "ctor\n"; }
    MyClass(const MyClass&) { std::cout << "copy\n"; }
    MyClass(MyClass&&) { std::cout << "move\n"; }
};

MyClass makeMyClass() {
    MyClass ret;
    return ret;
}

int main() {
    auto obj = makeMyClass();
    std::cout << '\n'
              << &obj << '\n';
}