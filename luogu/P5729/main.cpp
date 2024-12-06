#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

int main() {
    IOS;
    int w, x, h, q;
    // cin >> w >> x >> h >> q;
    cin >> q;
    vector<int> arr;
    for (int i = 0; i < q; ++i) {
        arr.emplace_back(cin);
    }
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}