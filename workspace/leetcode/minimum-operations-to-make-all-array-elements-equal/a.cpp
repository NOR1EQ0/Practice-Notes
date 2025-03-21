#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<ll> answer;
        answer.reserve
        auto answer_data = answer.data();

        return answer;
    }
};

int main() {
    Solution loc;
    vector<int> nums = { 3,1,6,8 }, queries = { 1,5 };
    auto ret = loc.minOperations(nums, queries);
    for (auto i : ret) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}