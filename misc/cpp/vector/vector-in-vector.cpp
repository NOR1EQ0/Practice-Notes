#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> t;
    t.emplace_back(vector<int>());
    t.at(0).emplace_back(8);
    return 0;
}