#include <bits/stdc++.h>

using namespace std;

class myClass {
public:
    bool assigned;
    int val;
    myClass& operator=(int param) {
        this->val = param;
        return *this;
    }
};

myClass& operator+(myClass& x, myClass& y) {
    myClass ret;
    ret = x.val + y.val;
    return ret;
}

int main() {
    myClass a; a = 78;
    myClass b; b = 92;
    myClass c = a + b;
}