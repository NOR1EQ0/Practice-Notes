#include <bits/stdc++.h>
#include "../../utils/print"
using namespace std;

// 这个写的有问题，理解错了，不过先放着
void radix_sort(vector<int>& vec) {
    static constexpr int intsize = sizeof(int) - 1;
    const auto len = vec.size();
    for (int a = intsize; a > 0; --a) {
        for (int i = a; i > 0; --i) {
            vector<vector<int>> bucket(256);
            for (size_t j = 0; j < len; ++j) {
                char* currentKeyword = reinterpret_cast<char*>(&(vec[j])) + i;
                bucket[static_cast<int>(*currentKeyword)].emplace_back(vec[j]);
            }
            for (size_t k = 0, j = 0; k < 256; k++) {
                for (auto const p : bucket[k]) {
                    vec[j] = p;
                    j++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> inputVec = {
        170, 45, 75, 90, 802, 2, 24, 66
    };
    radix_sort(inputVec);
    print_stl_container_element_with_newline(inputVec);
    return 0;
}