#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    tuple<vector<int>, vector<int>, double> searchLongestLine(vector<vector<int>>& pts) {
        auto calcline = [](vector<int> v1, vector<int> v2) {
            using ll = long long;
#define powma(x) ((x) * (x))
#define up(x) ((ll)(x))
            return sqrt(powma(abs(up(v1[0]) - up(v2[0]))) + powma(abs(up(v1[1]) - up(v2[1]))));
#undef powma
#undef up
        };
        tuple<vector<int>, vector<int>, double> ret = {{},{}, numeric_limits<double>::min()};
        auto& maxline = get<2>(ret);
        const auto len = pts.size();
        for (size_t i = 0; i < len - 1; i++) {
            for (size_t j = i + 1; j < len; j++) {
                auto& p1 = pts[i], &p2 = pts[j];
                auto thisline = calcline(p1, p2);
                if (thisline > maxline) {
                    ret = {p1, p2, thisline};
                }
            }
        }
        return ret;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        auto longest = searchLongestLine(points);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}