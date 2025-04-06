#include <bits/stdc++.h>

using namespace std;

const char str[] = "Fuck you!";
const int num1 = 6;

int main() {
    const int mainnum = 17;
    int* numptr = const_cast<int*>(&mainnum);
    *numptr = 98;
    cout << "numptr @ " << numptr << ": " << *numptr << '\n';
    cout << "num1 @ " << &mainnum << ": " << mainnum << '\n';
    return 0;
}