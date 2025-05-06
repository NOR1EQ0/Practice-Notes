#include <bits/stdc++.h>
#define NAME_TO_STRING(v) #v

using namespace std;

void printVec(vector<int>& vec) {
    cout << "[" << chrono::system_clock::to_time_t(chrono::system_clock::now()) << "] "
        << "Call ->" << __PRETTY_FUNCTION__ << "<- at LINE " << __LINE__ << endl;
    cout << "[" << chrono::system_clock::to_time_t(chrono::system_clock::now()) << "] "
        << "The address of vec: " << &vec << endl;
    for (const auto i : vec) cout << i << ' ';
    cout << "[" << chrono::system_clock::to_time_t(chrono::system_clock::now()) << "] "
        << "Reach LINE " << __LINE__ << endl;
}

int main() {
    vector<int>* vecptr = nullptr;
    vector<int>& vec = *vecptr;
    cout << NAME_TO_STRING(vecptr) << ": " << vecptr << endl;
    cout << NAME_TO_STRING(&vec) << ": " << vecptr << endl;
    printVec(vec);
    cout << "Reach " << __LINE__ << endl;
    return 0;
}