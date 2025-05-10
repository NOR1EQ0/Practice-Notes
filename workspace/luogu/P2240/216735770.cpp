#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // t is bag size
    int n,t;cin>>n>>t;
    double balance = 0;
    vector<pair<int, int>> vec(n);
    multimap<double, int, greater<double>> mtmap;
    for (int i =0; i < n; ++i) {
        cin >> vec[i].first >> vec[i].second;
        mtmap.emplace((double)vec[i].second / (double)vec[i].first, i);
    }
    for (auto const [ratio, index]: mtmap) {
        auto [weight, value] = vec[index];
        if (weight > t) {
            balance += (t * ratio);
            break;
        } 
        balance += value;
        t -= weight;
    }
    cout << fixed << setprecision(2) << balance << '\n';
    return 0;
}