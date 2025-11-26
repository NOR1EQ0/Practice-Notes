#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto tlen = temperatures.size();
        vector<int> ret;
        ret.resize(temperatures.size());
        stack<int> st;
        for (size_t i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto idx = st.top(); st.pop();
                ret[idx] = i - idx;
            }
            st.push(i);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> v = {
        {73, 74, 75, 71, 69, 72, 76, 73},
        {30, 40, 50, 60},
        {30, 60, 90}};

    for (auto& i : v) {
        cout << "Input: [";
        for (size_t j = 0; j < i.size(); j++) {
            cout << i[j] << ",]"[j == i.size() - 1];
        }
        auto ret = Solution().dailyTemperatures(i);
        cout << "\nOutput: [";
        for (size_t j = 0; j < ret.size(); j++) {
            cout << ret[j] << ",]"[j == ret.size() - 1];
        }
        cout << '\n';
    }
}