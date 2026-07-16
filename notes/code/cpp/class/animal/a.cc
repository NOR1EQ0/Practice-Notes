#include <bits/stdc++.h>

class Animal {
public:
    virtual ~Animal() {
        std::cout << "~Animal\n";
    }
};

class Cat : public Animal {
public:
    ~Cat() {
        std::cout << "~Cat\n";
        // ~Animal();
    }
};

class Kitty : public Cat {
public:
    ~Kitty() {
        std::cout << "~Kitty\n";
        // ~Cat();
    }
};

int main() {
    sizeof(Animal);
    Animal* a = (Animal*)malloc(sizeof(Kitty));
    new (a) Kitty();
    a->~Animal();
    free(a);
    // delete a;
}