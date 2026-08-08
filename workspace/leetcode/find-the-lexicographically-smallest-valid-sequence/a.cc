#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
    using ll = long long;
    using ull = unsigned long long;

public:
    vector<int> validSequence(string word1, string word2) {
        unordered_map<char, set<int>> table;
        vector<int> ans;
        for (int i = 0; i < word1.size(); i++) {
            table[word1[i]].emplace(i);
        }
        bool chr_in_word2_not_in_word1 = false;
        for (int i = 0; i < word2.size(); i++) {
            auto it = table.find(word2[i]);
            if (it == table.end()) {
                if (chr_in_word2_not_in_word1) {
                    return {};
                } else {
                    chr_in_word2_not_in_word1 = true;
                    if (!ans.empty()) {
                        ans.emplace_back(i);
                    }
                }
            } else {
                auto& s = it->second;
                if (ans.empty()) {
                    ans.emplace_back(*s.begin());
                } else {
                    auto idx_it = s.upper_bound(ans.back());
                    if (idx_it != s.end()) {
                        ans.emplace_back(*idx_it);
                    } else {
                        return {};
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    auto vec = Solution().validSequence("vbcca", "abc");
    for (auto i : vec) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
