#include <bits/stdc++.h>

using namespace std;

constexpr auto hx = "\nHe Xie Ni Quan Jia!\n"sv;
constexpr const char mosaic[] = "<censored>";
constexpr auto mosaicsize = sizeof mosaic - 1;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n;
    vector<string> vs(n);
    for (auto& s : vs) cin >> s;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);
    size_t pos{};
    int illegalcnt{};
    while (1) {
        bool illegal = false;
        auto input_idx = string::npos;
        auto vs_idx = string::npos;
        for (int i = 0; i < n; i++) {
            auto& s = vs[i];
            auto fd = input.find(s, pos);
            if (fd != string::npos) {
                illegal = true;
                if (fd < input_idx) {
                    input_idx = fd;
                    vs_idx = i;
                }
            }
        }
        if (illegal) {
            input = input.substr(0, input_idx) + mosaic + input.substr(input_idx + vs[vs_idx].size());
            pos = input_idx + mosaicsize;
            k--;
            illegalcnt++;
        } else {
            break;
        }
    }
    if (k > 0) {
        cout << input << '\n';
    } else {
        cout << illegalcnt << hx;
    }
}