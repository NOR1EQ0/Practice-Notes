#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> m;
        for (auto i : s) {
            m[i]++;
        }
        unordered_map<int, set<char>> rm;
        for (const auto& p : m) {
            rm[p.second].emplace(p.first);
        }
        pair<int, set<char>> resp = *rm.begin();
        size_t maxg = rm.begin().operator*().second.size(),
               maxfreq = rm.begin().operator*().first;
        for (const auto& p : rm) {
            auto thisg = p.second.size();
            auto thisfreq = p.first;
            if (thisg >= maxg && thisfreq >= maxfreq) {
                maxg = thisg;
                resp = p;
            }
        }
        string ret;
        for (auto i : resp.second) {
            ret += i;
        }
        return ret;
    }
};