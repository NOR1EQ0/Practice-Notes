#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<vector<ll>> v(N + 1);
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        while (n--) {
            ll a;
            cin >> a;
            v[a].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        auto& person = v[i];
        cout << person.size() << ' ';
        ranges::sort(person);
        for (auto i : person) cout << i << ' ';
        cout << '\n';
    }
}