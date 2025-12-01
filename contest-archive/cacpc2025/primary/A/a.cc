// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

struct contestant {
    int id;
    int total;
    vector<int> detailed_scores;

    contestant(contestant& c) = default;
    // contestant(contestant&& c) = default;
    // contestant() = default;
    contestant(int& a, int& b, vector<int>&& c) : id(a), total(b), detailed_scores(move(c)) {};
};

struct score_cmp {
    bool operator()(contestant& l, contestant& r) {
        if (l.total != r.total) return l.total > r.total;
        else
            return l.id < r.id;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    set<contestant, score_cmp> s;
    vector<contestant> v(n + 1);
    for (int i = 0; i < n; i++) {
        v[i].id = i;
        v[i].detailed_scores.resize(m + 1);
    }
    for (int i = 0; i < k; i++) {
        int c, p, score;
        cin >> c >> p >> score;
        v[i].detailed_scores[p] = max(score, v[i].detailed_scores[p]);
    }

    // Start to count total
    for (int i = 0; i < n; i++) {
        v[i].total = accumulate(v[i].detailed_scores.begin(), v[i].detailed_scores.end(), 0);
        s.emplace(v[i].id, v[i].total, move(v[i].detailed_scores));
    }
    // Make vector invalid, avoid deep copy?
}