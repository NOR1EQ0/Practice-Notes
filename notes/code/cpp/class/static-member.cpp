#include <bits/stdc++.h>
#define name2str(v) #v

using namespace std;

class myClass {
public:
    static size_t counter;

    int x;
    int y;

    int times() {
        return x * y;
    }

    static auto getCounter() {
        return counter;
    }

    myClass() : x(0), y(0) {
        counter++;
    }
};

size_t myClass::counter;
// Static members in a class must be declared again(?) or initialized outside of this class and a global domain.
// Static members are shared by different variables of the same class.

int main() {
    cout << name2str(myClass::counter) << ": " << myClass::counter << endl;
    myClass();
    myClass();
    cout << name2str(myClass::counter) << ": " << myClass::counter << endl;
    myClass a;
    cout << name2str(a.counter) << ": " << a.counter << endl;
    myClass b;
    cout << name2str(b.counter) << ": " << b.counter << endl;
    cout << name2str(a.counter) << ": " << a.counter << endl;
    return 0;
}