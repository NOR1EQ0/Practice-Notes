#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    vector<ll> v;
    cout << "Close synchronization with stdio and disable cin's tie with cout? [n/y]: " << flush;
    {
        string s;
        cin >> s;
        if (s == "y" || s == "Y") {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout << "Job done!" << endl;
        }
    }
    cout << "Input the numbers of the array: " << flush;
    size_t n;
    cin >> n;
    v.reserve(n);
    cout << "Input numbers: " << endl;
    while (n--) {
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    auto start = chrono::steady_clock::now();
    for (auto i : v) {
        cout << i << ' ';
    }
    auto end = chrono::steady_clock::now();
    auto duration = end - start;
    auto nanos = duration.count();
    auto secs = chrono::duration_cast<chrono::seconds>(duration).count();
    auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count();
    cout << '\n'
         << "Cost " << ms << "ms (" << nanos << "ns)" << endl;
}