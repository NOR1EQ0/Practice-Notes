#include <bits/stdc++.h>

using namespace std;

#define forrange(x,name) for(size_t name = 0; name < x; ++name)
class Solution {
    using ll = long long;
    using ull = unsigned long long;
public:
    vector<long long> distance(vector<int>& nums) {
        auto len = nums.size();
        vector<ll> arr;
        arr.reserve(len);
        vector<int> idxArr;
        idxArr.reserve(len);
        unordered_map<int, vector<ll>> sumMap;
        forrange(len, i) {
            sumMap[nums[i]].push_back(i);
        }
        
        return arr;
    }
};

int main() {
    Solution loc;
    vector<int> vec = {
        // #include "hack.txt"
        1,3,1,1,2
    };
    
    auto ret = loc.distance(vec);
    for (auto i : ret) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}