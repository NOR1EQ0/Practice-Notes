#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        auto len = s.length();
        for (auto& i : words) {
            auto firstpos = s.find(i.at(0));
            auto ilen = i.length();
            if (len < ilen) {
                continue;
            }
            if (firstpos == 0) {
                bool match = true;
                for (int j = 1; j < len && j < ilen; ++j) {
                    if (i[j] != s[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution loc;
    vector<string> words1 = { "a","b","c","ab","bc","abc" };
    vector<string> words2 = { "a","a" };
    vector<string> hack1 = {
        "feh","w","w","lwd","c","s","vk","zwlv","n","w","sw","qrd","w","w","mqe","w","w","w","gb","w","qy","xs","br","w","rypg","wh","g","w","w","fh","w","w","sccy"
    };
    string s1 = "abc";
    string s2 = "aa";
    string hackS1 = "w";
    vector<int> results = { loc.countPrefixes(words1,s1),
        loc.countPrefixes(words2,s2),
        loc.countPrefixes(hack1, hackS1)
    };
    for (auto i : results) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}