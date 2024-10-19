#include <iostream>
const int array_length = 2;

struct Object
{
    int weight;
    int value;
} e[array_length];

const Object a = { 3,5 };
Object b, B[array_length], tmp;
Object* c;

int main(int argc, char const* argv[]) {

    B[0].value = 2;
    c = new Object();
    std::cout << B[0].value << " " << c->value << '\n';
    return 0;
}

