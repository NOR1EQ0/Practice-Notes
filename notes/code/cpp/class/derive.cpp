#include <bits/stdc++.h>

using namespace std;

class Base {
private:
    int pri1 = 2;
    int pri2 = 23;
    int prisum() { return plus()(pri1, pri2); }
protected:
    float pro1 = 78;
    float pri1pro1() { return pri1 + pro1; }
public:
    int pub1 = 12;
    int pub1time(int val) { return pub1 * val; }
};


class Derived : private Base {
private:
    int prisum() {
        // return (pri1 + pri2) * 9;    Even the Derived privately derives from Base, Derived still can't access the Base's private object
        // return prisum() * 9;         This will call Derived::prisum but not Base::prisum
        return pub1;
    }
};

class DerivedPub : public Base { // Default inherit way
private:
    // int prisum() override {}         Functions in derived classes could only over
public:
    int get2() {
        return (int)(pro1) + pub1;
    }
};

class DerivedProtected : protected Base {
public:
    int get1() {
        return (int)pro1 + pub1; // Protected object is accessible.
    }
};

int main() {
    Base base;
    Derived d;
    DerivedProtected dpro;
    DerivedPub dpub;
    auto a = base.pub1;
    // auto b = d.pub1time(2);      Public objects from Base would be not accessible for Derived (It derives from Base privately so protected objects and public objects can't be accessed.)
}